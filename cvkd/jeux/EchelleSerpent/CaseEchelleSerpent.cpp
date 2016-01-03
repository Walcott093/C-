#include <iostream>
//#include "../../architectureGenerique/Constantes.hpp"
#include "CaseEchelleSerpent.hpp"
using namespace std;


/*** DEBUT : Sert a la repartition des cases par probabilite ***/
static int nbCases;
static int nbCasesNonNeutres;
static bool teteQueue;
/*** FIN : Sert a la repartition des cases par probabilite ***/


CaseEchelleSerpent::CaseEchelleSerpent(int abs, int ord, int nbMax, int nb, EchelleSerpent jeu, bool boo):
  Case(abs, ord, nbMax, nb), jeuVariante(jeu), isObjetEchelleSerpent(boo) {

  if(isObjetEchelleSerpent)
    obj = new ObjetEchelleSerpent();
  else
    obj = nullptr;

  nbCases = jeuVariante.getTaillePlateauLignes() * jeuVariante.getTaillePlateauColonnes();
  nbCasesNonNeutres = jeuVariante.getNbCasesEchelles()
    + jeuVariante.getNbCasesSerpents()
    + jeuVariante.getNbCasesOranges()
    + jeuVariante.getNbCasesVertes();
  
  specificiteCase = randomSpecificite();
  
  cout << "                              Construction de la CaseEchelleSerpent : " << *this << endl;
}

CaseEchelleSerpent::CaseEchelleSerpent(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions, EchelleSerpent jeu, bool boo):
  Case(abs, ord, nbMax, nb, pions), jeuVariante(jeu), isObjetEchelleSerpent(boo) {
  specificiteCase = randomSpecificite();

  cout << "                              Construction de la CaseEchelleSerpent : " << *this <<endl;
}
/*
CaseEchelleSerpent::CaseEchelleSerpent(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions, int* tabId, EchelleSerpent jeu, bool boo):
  Case(abs, ord, nbMax, nb, pions, tabId), jeuVariante(jeu), isObjetEchelleSerpent(boo) {
  specificiteCase = randomSpecificite();

  cout << "                              Construction de la CaseEchelleSerpent : " << *this <<endl;
}
*/

CaseEchelleSerpent::~CaseEchelleSerpent() {
  cout << "                              Destruction de la CaseEchelleSerpent : " << *this << endl;
}


int CaseEchelleSerpent::randomSpecificite() {
  int ret = 0;
  int x = 0;
  string nomVariante = jeuVariante.getNomJeuOuVariante();
  srand(time(nullptr));

  if(nomVariante == ECHELLE_SERPENT
     || nomVariante == ECHELLE_SERPENT_PEDAGOGIQUE
     || nomVariante == ECHELLE_SERPENT_PLUSIEURS_PIONS) {
    x = (rand() % nbCases--) +1;
    if(1 <= x && x <= nbCasesNonNeutres) {  
      ret = (rand() % NB_SPECIFICITES_ES) +1; // 1 (ECHELLE) ou 2 (SERPENT)
      nbCasesNonNeutres--;
    }
    else
      ret = NEUTRE; // 0
  }
  else if(nomVariante == ECHELLE_SERPENT_ORANGE_VERTE) {
    x = (rand() % nbCases--) +1;
    if(1 <= x && x <= nbCasesNonNeutres) {  
      ret = (rand() % NB_SPECIFICITES_ESOV) +1; // 1 (ECHELLE) ou 2 (SERPENT) ou 3 (ORANGE) ou 4 (VERTE)
      nbCasesNonNeutres--;
    }
    else
      ret = NEUTRE; // 0
  }
  else
    cout << "[CaseEchelleSerpent.cpp] Erreur : Nom de variante non reconnu" << endl;
  
  return ret;
}


EchelleSerpent CaseEchelleSerpent::getJeuVariante() { return jeuVariante; }
bool CaseEchelleSerpent::getIsObjetEchelleSerpent() { return isObjetEchelleSerpent; }
ObjetEchelleSerpent* CaseEchelleSerpent::getObj() { return obj; }
int CaseEchelleSerpent::getSpecificiteCase() { return specificiteCase; }
int CaseEchelleSerpent::getNbCases() { return nbCases; }
int CaseEchelleSerpent::getNbCasesNonNeutres() { return nbCasesNonNeutres; }
bool CaseEchelleSerpent::getTeteQueue() { return teteQueue; }

void CaseEchelleSerpent::setJeuVariante(EchelleSerpent es) { jeuVariante = es; }
void CaseEchelleSerpent::setIsObjetEchelleSerpent(bool b) { isObjetEchelleSerpent = b; }
void CaseEchelleSerpent::setObj(ObjetEchelleSerpent* oes) { obj = oes; }
void CaseEchelleSerpent::setSpecificiteCase(int s) { specificiteCase = s; }
void CaseEchelleSerpent::setNbCases(int s) { nbCases = s; }
void CaseEchelleSerpent::setNbCasesNonNeutres(int s) { nbCasesNonNeutres = s; }
void CaseEchelleSerpent::setTeteQueue(bool b) { teteQueue = b; }
