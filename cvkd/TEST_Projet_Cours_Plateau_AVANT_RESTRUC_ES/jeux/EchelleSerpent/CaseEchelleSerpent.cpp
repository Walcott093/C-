#include <iostream>
#include "CaseEchelleSerpent.hpp"
using namespace std;


/*** DEBUT : Sert a la repartition des cases par probabilite ***/
static int cptIdE = 1;
static int cptIdS = 1;
static bool basHautEchelle = false;
static bool queueTeteSerpent = false; // pe inutile avec la classe ObjetEchelleSerpent
static CaseEchelleSerpent* caseBasEchelle;
static CaseEchelleSerpent* caseHautEchelle;
static CaseEchelleSerpent* caseQueueSerpent;
static CaseEchelleSerpent* caseTeteSerpent;
/*** FIN : Sert a la repartition des cases par probabilite ***/




/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
CaseEchelleSerpent::CaseEchelleSerpent(int position, int nbMax, int nb, EchelleSerpent* jeu, int spe):
  Case(position, nbMax, nb), jeuVariante(jeu), specificite(spe) {

  specificite = randomSpecificite();
  // if specificite != ECHELLE, SERPENT => alors obj = nullptr
  cout << "                              Construction de la CaseEchelleSerpent : " << this << endl;
}

CaseEchelleSerpent::CaseEchelleSerpent(int position, int nbMax, int nb, forward_list<Pion*> pions, ObjetEchelleSerpent* oes, EchelleSerpent* jeu, int spe):
  Case(position, nbMax, nb, pions), jeuVariante(jeu), specificite(spe), obj(oes) {
  specificite = randomSpecificite();

  cout << "                              Construction de la CaseEchelleSerpent : " << this <<endl;
}

CaseEchelleSerpent::~CaseEchelleSerpent() {
  cout << "                              Destruction de la CaseEchelleSerpent : " << this << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
int CaseEchelleSerpent::getSpecificite() { return specificite; }
EchelleSerpent* CaseEchelleSerpent::getJeuVariante() { return jeuVariante; }
ObjetEchelleSerpent* CaseEchelleSerpent::getObj() { return obj; }
//int CaseEchelleSerpent::getNbCasesPlateau() { return nbCasesPlateau; }
//bool CaseEchelleSerpent::getIsObjetEchelleSerpent() { return isObjetEchelleSerpent; }
//ObjetEchelleSerpent* CaseEchelleSerpent::getObj() { return obj; }
//int CaseEchelleSerpent::getSpecificiteCase() { return specificiteCase; }

void CaseEchelleSerpent::setSpecificite(int spe) { specificite = spe; }
void CaseEchelleSerpent::setJeuVariante(EchelleSerpent* es) { jeuVariante = es; }
void CaseEchelleSerpent::setObj(ObjetEchelleSerpent* oes) { obj = oes; }
//void CaseEchelleSerpent::setNbCasesPlateau(int i) { nbCasesPlateau = i; }
//void CaseEchelleSerpent::setIsObjetEchelleSerpent(bool b) { isObjetEchelleSerpent = b; }
//void CaseEchelleSerpent::setObj(ObjetEchelleSerpent* oes) { obj = oes; }
//void CaseEchelleSerpent::setSpecificiteCase(int s) { specificiteCase = s; }

ostream& operator<<(ostream& o, CaseEchelleSerpent*& c) {
  if(c->obj != nullptr) {
    string type = (c->obj)->getType();
    int idOES = (c->obj)->getIdOES();
    if(c->specificite == ECHELLE || c->specificite == SERPENT) {
      if(type == TYPE_ECHELLE_BAS)
	o << BLANC << "e" << idOES << SUFFIXE_COULEUR;
      else if(type == TYPE_ECHELLE_HAUT)
	o << BLANC << "E" << idOES << SUFFIXE_COULEUR;
      else if(type == TYPE_SERPENT_QUEUE)
	o << NOIR << "s" << idOES << SUFFIXE_COULEUR;
      else if(type == TYPE_SERPENT_TETE)
	o << NOIR << "S" << idOES << SUFFIXE_COULEUR;
    }
  }
  if(c->specificite == ORANGE)
    o << CYAN << "O " << SUFFIXE_COULEUR;
  else if(c->specificite == VERTE)
    o << MAGENTA << "V " << SUFFIXE_COULEUR;

  int retrait = 0;
  if(c->specificite == ECHELLE || c->specificite == SERPENT)
    retrait = 2;
  else if(c->specificite == ORANGE || c->specificite == VERTE)
    retrait = 1;
    
  int maxEspace = 2 + c->getNbPionsMax();
  
  switch(c->nbPions) {
  case 0:
    for(int i=0 ; i<maxEspace-retrait ; i++)
      o << " ";
    break;
  case 1:
    for(int i=0 ; i<retrait ; i++)
      o << " ";
    o << *((c->listePions).begin());
    for(int i=0 ; i<maxEspace-1-retrait-retrait ; i++)
      o << " ";
    break;
  default:
    for(int i=0 ; i<retrait ; i++)
      o << " ";
    int cpt = 0;
    for(auto it=c->listePions.begin() ; it!=c->listePions.end(); ++it) {
      o << *it;
      cpt++;
    }
    for(int i=0 ; i<maxEspace-cpt-retrait-retrait ; i++)
      o << " ";
    break;
    }
  return o;
}
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/




/********** DEBUT : FONCTIONS SUPPLEMENTAIRES **********/
int CaseEchelleSerpent::randomSpecificite() {
  int ret = NEUTRE; // 0
  int x = 0;
  string nomVariante = jeuVariante->getNomJeuOuVariante();

  int val = jeuVariante->getNbCasesPlateauRestantes();
  jeuVariante->setNbCasesPlateauRestantes(val -1); // <=> jeuVariante.nbCasesPlateauRestantes--; on retire car on traite une case qui ne sera donc plus a traiter

  if(position == 0 || position == jeuVariante->getNbCasesPlateau()-1)
    return ret; // La 1ere et la derniere et la derniere case sont forcement des cases NEUTRE

  srand(time(nullptr));
  x = (rand() % val) +1;
  
  /*cout << "nbCasesNonNeutresRestantes= " << jeuVariante->getNbCasesNonNeutresRestantes() << endl;
  cout << "nbCasesEchellesRestantes= " << jeuVariante->getNbCasesEchellesRestantes() << endl;
  cout << "nbCasesSerpentsRestantes= " << jeuVariante->getNbCasesSerpentsRestantes() << endl;
  cout << "nbCasesOrangesRestantes= " << jeuVariante->getNbCasesOrangesRestantes() << endl;
  cout << "nbCasesVertesRestantes= " << jeuVariante->getNbCasesVertesRestantes() << endl;*/
  if(1 <= x && x <= jeuVariante->getNbCasesNonNeutresRestantes()) {
    cout << "**nbCasesNonNeutresRestantes= " << jeuVariante->getNbCasesNonNeutresRestantes() << endl;
    jeuVariante->setNbCasesNonNeutresRestantes( jeuVariante->getNbCasesNonNeutresRestantes() -1 ); // <=> jeuVariante.nbCasesNonNeutresRestantes--;
    cout << "**nbCasesNonNeutresRestantes= " << jeuVariante->getNbCasesNonNeutresRestantes() << endl;

    do {
      cout << "nbCasesNonNeutresRestantes= " << jeuVariante->getNbCasesNonNeutresRestantes() << endl;
      cout << "nbCasesEchellesRestantes= " << jeuVariante->getNbCasesEchellesRestantes() << endl;
      cout << "nbCasesSerpentsRestantes= " << jeuVariante->getNbCasesSerpentsRestantes() << endl;
      cout << "nbCasesOrangesRestantes= " << jeuVariante->getNbCasesOrangesRestantes() << endl;
      cout << "nbCasesVertesRestantes= " << jeuVariante->getNbCasesVertesRestantes() << endl;
      
      if(nomVariante == ECHELLE_SERPENT) {
	cout << "** ** dans ECHELLE SERPENT" << endl;
	ret = (rand() % NB_SPECIFICITES_ES) +1; // 1 (ECHELLE) ou 2 (SERPENT)
	cout << "** ** ** ret = " << ret << endl;
      }
      else { // if ESOV || ESP || ESPP
	cout << "** ** dans ESOV || ESP || ESPP" << endl;
	ret = (rand() % NB_SPECIFICITES_ESOV) +1; // 1 (ECHELLE) ou 2 (SERPENT) ou 3 (ORANGE) ou 4 (VERTE)
	cout << "** ** ** ret = " << ret << endl;
      }
      
      cout << "[CaseEchelleSerpent.cpp] : do while" << endl;
    } while((ret == ECHELLE && jeuVariante->getNbCasesEchellesRestantes() == 0)
	    || (ret == SERPENT && jeuVariante->getNbCasesSerpentsRestantes() == 0)
	    || (ret == ORANGE && jeuVariante->getNbCasesOrangesRestantes() == 0)
	    || (ret == VERTE && jeuVariante->getNbCasesVertesRestantes() == 0));
    
    cout << "** SORTI : ret = " << ret << endl;

    if(ret == ECHELLE) {
      jeuVariante->setNbCasesEchellesRestantes( jeuVariante->getNbCasesEchellesRestantes() -1 );

      if(basHautEchelle == false) {
	basHautEchelle = true;
	caseBasEchelle = this;
      }
      else { // if(basHautEchelle == true)
	basHautEchelle = false;
	caseHautEchelle = this;
	caseBasEchelle->obj = new ObjetEchelleSerpent(cptIdE, TYPE_ECHELLE_BAS, caseHautEchelle->getPosition(), caseBasEchelle->getPosition());
	caseHautEchelle->obj = new ObjetEchelleSerpent(cptIdE++, TYPE_ECHELLE_HAUT, caseHautEchelle->getPosition(), caseBasEchelle->getPosition());
      }
    }
      
    else if(ret == SERPENT) {
      jeuVariante->setNbCasesSerpentsRestantes( jeuVariante->getNbCasesSerpentsRestantes() -1 );

      if(queueTeteSerpent == false) {
	queueTeteSerpent = true;
	caseQueueSerpent = this;
      }
      else { // if(queueTeteSerpent == true)
	queueTeteSerpent = false;
	caseTeteSerpent = this;
	caseQueueSerpent->obj = new ObjetEchelleSerpent(cptIdS, TYPE_SERPENT_QUEUE, caseTeteSerpent->getPosition(), caseQueueSerpent->getPosition());
	caseTeteSerpent->obj = new ObjetEchelleSerpent(cptIdS++, TYPE_SERPENT_TETE, caseTeteSerpent->getPosition(), caseQueueSerpent->getPosition());
      }
    }
    
    else if(ret == ORANGE)
      jeuVariante->setNbCasesOrangesRestantes( jeuVariante->getNbCasesOrangesRestantes() -1 );

    else if(ret == VERTE)
      jeuVariante->setNbCasesVertesRestantes( jeuVariante->getNbCasesVertesRestantes() -1 );
  }
    
  return ret;
}
/********** FIN : FONCTIONS SUPPLEMENTAIRES **********/
