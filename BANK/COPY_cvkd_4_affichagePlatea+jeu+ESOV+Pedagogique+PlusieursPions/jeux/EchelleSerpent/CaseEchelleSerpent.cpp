#include <iostream>
#include "CaseEchelleSerpent.hpp"
using namespace std;


/*** DEBUT : Sert a la repartition des cases par probabilite ***/
static int nbEchellesRestantes;
static int nbSerpentsRestants;
static bool basHautEchelle = false;
static bool queueTeteSerpent = false; // pe inutile avec la classe ObjetEchelleSerpent
static Case* caseBasEchelle;
static Case* caseHautEchelle;
static Case* caseQueueSerpent;
static Case* caseTeteSerpent;
/*** FIN : Sert a la repartition des cases par probabilite ***/




/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
CaseEchelleSerpent::CaseEchelleSerpent(int spe, int position, int nbMax, int nb, EchelleSerpent* jeu):
  Case(spe, position, nbMax, nb), jeuVariante(jeu) {

  specificite = randomSpecificite();
  // if specificite != ECHELLE, SERPENT => alors obj = nullptr
  cout << "                              Construction de la CaseEchelleSerpent : " << this << endl;
}

CaseEchelleSerpent::CaseEchelleSerpent(int spe, int position, int nbMax, int nb, forward_list<Pion*> pions, ObjetEchelleSerpent* oes, EchelleSerpent* jeu):
  Case(spe, position, nbMax, nb, pions, oes), jeuVariante(jeu) {
  specificite = randomSpecificite();

  cout << "                              Construction de la CaseEchelleSerpent : " << this <<endl;
}

CaseEchelleSerpent::~CaseEchelleSerpent() {
  cout << "                              Destruction de la CaseEchelleSerpent : " << this << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
EchelleSerpent* CaseEchelleSerpent::getJeuVariante() { return jeuVariante; }
//int CaseEchelleSerpent::getNbCasesPlateau() { return nbCasesPlateau; }
//bool CaseEchelleSerpent::getIsObjetEchelleSerpent() { return isObjetEchelleSerpent; }
//ObjetEchelleSerpent* CaseEchelleSerpent::getObj() { return obj; }
//int CaseEchelleSerpent::getSpecificiteCase() { return specificiteCase; }

void CaseEchelleSerpent::setJeuVariante(EchelleSerpent* es) { jeuVariante = es; }
//void CaseEchelleSerpent::setNbCasesPlateau(int i) { nbCasesPlateau = i; }
//void CaseEchelleSerpent::setIsObjetEchelleSerpent(bool b) { isObjetEchelleSerpent = b; }
//void CaseEchelleSerpent::setObj(ObjetEchelleSerpent* oes) { obj = oes; }
//void CaseEchelleSerpent::setSpecificiteCase(int s) { specificiteCase = s; }
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/




/********** DEBUT : FONCTIONS SUPPLEMENTAIRES **********/
int CaseEchelleSerpent::randomSpecificite() {
  int ret = NEUTRE; // 0
  int x = 0;
  string nomVariante = jeuVariante->getNomJeuOuVariante();
  srand(time(nullptr));

  int val = jeuVariante->getNbCasesPlateauRestantes();
  cout << "avant val" << endl;
  x = (rand() % val) +1;
  jeuVariante->setNbCasesPlateauRestantes(val -1); // <=> jeuVariante.nbCasesPlateauRestantes--; on retire car on traite une case qui ne sera donc plus a traiter
  
  if(1 <= x && x <= jeuVariante->getNbCasesNonNeutres()) {
    jeuVariante->setNbCasesNonNeutres( jeuVariante->getNbCasesNonNeutres() -1 ); // <=> jeuVariante.nbCasesNonNeutres--;

    do {
      if(nomVariante == ECHELLE_SERPENT_ORANGE_VERTE) {
	cout << "avant NB_SPECIFICITES_ESOV" << endl;
	ret = (rand() % NB_SPECIFICITES_ESOV) +1; // 1 (ECHELLE) ou 2 (SERPENT) ou 3 (ORANGE) ou 4 (VERTE)
      }
      else {
	cout << "avant NB_SPECIFICITES_ES" << endl;
	ret = (rand() % NB_SPECIFICITES_ES) +1; // 1 (ECHELLE) ou 2 (SERPENT)
      }
      cout << "[CaseEchelleSerpent.cpp] : do while" << endl;
    } while((ret == ECHELLE && jeuVariante->getNbCasesEchellesRestantes() == 0)
	    || (ret == SERPENT && jeuVariante->getNbCasesSerpentsRestantes() == 0)
	    || (ret == ORANGE && jeuVariante->getNbCasesOrangesRestantes() == 0)
	    || (ret == VERTE && jeuVariante->getNbCasesVertesRestantes() == 0));
    
    
    if(ret == ECHELLE) {
      jeuVariante->setNbCasesEchellesRestantes( jeuVariante->getNbCasesEchellesRestantes() -1 );
      if(basHautEchelle == false) {
	caseBasEchelle = this;
	basHautEchelle = true;
      }
      else { // if(basHautEchelle == true)
	jeuVariante->setNbCasesEchellesRestantes( jeuVariante->getNbCasesEchellesRestantes() -1 );
	caseHautEchelle = this;
	int idOES = jeuVariante->getNbCasesEchelles() - jeuVariante->getNbCasesEchellesRestantes();
	caseBasEchelle->obj = new ObjetEchelleSerpent(idOES/2, TYPE_ECHELLE_BAS, caseHautEchelle->getPosition(), caseBasEchelle->getPosition());
	caseHautEchelle->obj = new ObjetEchelleSerpent(idOES/2, TYPE_ECHELLE_HAUT, caseHautEchelle->getPosition(), caseBasEchelle->getPosition());
	basHautEchelle = false;
      }
    }
      
    else if(ret == SERPENT) {
      jeuVariante->setNbCasesSerpentsRestantes( jeuVariante->getNbCasesSerpentsRestantes() -1 );
      if(queueTeteSerpent == false) {
	caseQueueSerpent = this;
	queueTeteSerpent = true;
      }
      else { // if(queueTeteSerpent == true)
	jeuVariante->setNbCasesSerpentsRestantes( jeuVariante->getNbCasesSerpentsRestantes() -1 );
	caseTeteSerpent = this;
	int idOES = jeuVariante->getNbCasesSerpents() - jeuVariante->getNbCasesSerpentsRestantes();
	caseQueueSerpent->obj = new ObjetEchelleSerpent(idOES/2, TYPE_SERPENT_QUEUE, caseTeteSerpent->getPosition(), caseQueueSerpent->getPosition());
	caseTeteSerpent->obj = new ObjetEchelleSerpent(idOES/2, TYPE_SERPENT_TETE, caseTeteSerpent->getPosition(), caseQueueSerpent->getPosition());
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
