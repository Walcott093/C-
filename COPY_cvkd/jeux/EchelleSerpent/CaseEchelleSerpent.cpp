#include <iostream>
//#include "../../architectureGenerique/Constantes.hpp"
#include "CaseEchelleSerpent.hpp"
using namespace std;

CaseEchelleSerpent::CaseEchelleSerpent(int abs, int ord, int nbMax, int nb, EchelleSerpent jeu):
  Case(abs, ord, nbMax, nb), jeuVariante(jeu) {

  nbCases = jeuVariante.getTaillePlateauLignes() * jeuVariante.geTaillePlateauColonnes();
  nbCasesNonNeutres = jeuVariante.getNbCasesEchelles()
    + jeuVariante.getNbCasesSerpents()
    + jeuVariante.getNbCasesOranges()
    + jeuVariante.getNbCasesVertes();
  
  specificiteCase = randomSpecificite();
  
  cout << "                              Construction de la CaseEchelleSerpent : " << *this << endl;
}

CaseEchelleSerpent::CaseEchelleSerpent(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions, int* tabId, EchelleSerpent jeu):
  Case(abs, ord, nbMax, nb, pions, tabId), jeuVariante(jeu) {
  specificiteCase = randomSpecificite();

  cout << "                              Construction de la CaseEchelleSerpent : " << *this <<endl;
}

CaseEchelleSerpent::~CaseEchelleSerpent() {
  cout << "                              Destruction de la CaseEchelleSerpent : " << *this << endl;
}


// Vaut-il mieux faire une fonction qui renvoie forcement une specificite (et donc ne renvoie pas NEUTRE ?
int CaseEchelleSerpent::randomSpecificite() {
  int ret = 0;
  int x = 0;
  string nomVariante = jeuVariante.getNomJeuOuVariante();
  srand(time(nullptr));

  switch(nomVariante) {
  case ECHELLE_SERPENT:
  case ECHELLE_SERPENT_PEDAGOGIQUE:
  case ECHELLE_SERPENT_PLUSIEURS_PIONS:
    x = (rand() % nbCases--) +1;
    if(1 <= x && x <= nbCasesNonNeutres) {  
      ret = (rand() % NB_SPECIFICITES_ES) +1; // 1 (ECHELLE) ou 2 (SERPENT)
      nbCasesNonNeutres--;
    }
    else
      ret = NEUTRE; // 0
    break;

  case ECHELLE_SERPENT_ORANGE_VERTE:
    x = (rand() % nbCases--) +1;
    if(1 <= x && x <= nbCasesNonNeutres) {  
      ret = (rand() % NB_SPECIFICITES_ESOV) +1; // 1 (ECHELLE) ou 2 (SERPENT) ou 3 (ORANGE) ou 4 (VERTE)
      nbCasesNonNeutres--;
    }
    else
      ret = NEUTRE; // 0
    break;

  default:
    cout << "[CaseEchelleSerpent.cpp] Erreur : Nom de variante non reconnu" << endl;
    break;
  }
  return ret;
}


EchelleSerpent CaseEchelleSerpent::getJeuVariante() { return jeuVariante; }
int CaseEchelleSerpent::getSpecificiteCase() { return specificiteCase; }
int CaseEchelleSerpent::getNbCases() { return nbCases; }
int CaseEchelleSerpent::getNbCasesNonNeutres() { return nbCasesNonNeutres; }
void CaseEchelleSerpent::setJeuVariante(EchelleSerpent es) { jeuVariante = es; }
void CaseEchelleSerpent::setSpecificiteCase(int s) { specificiteCase = s; }
void CaseEchelleSerpent::setNbCases(int s) { nbCases = s; }
void CaseEchelleSerpent::setNbCasesNonNeutres(int s) { nbCasesNonNeutres = s; }
