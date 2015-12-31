#include <iostream>
#include "Case.hpp"
using namespace std;

const int NB_JOUEURS_MAX = 4;

Case::Case() {
  cout << "Creation d'une Case par defaut" << endl;
}

Case::Case(int abs, int ord, int nbMax, int nb):
  x(abs), y(ord), nbPionsMax(nbMax), nbPions(nb) {

  tableauIdJoueurs = new int[NB_JOUEURS_MAX +1];
  tableauIdJoueurs[0] = 0;

  tableauPions = new Pion[nbMax];

  cout << "Construction de la case : " << *this << endl;
}

Case::Case(int abs, int ord, int nbMax, int nb, Pion* tabPions, int* tabId):
  x(abs), y(ord), nbPionsMax(nbMax), nbPions(nb), tableauPions(tabPions), tableauIdJoueurs(tabId) {
  cout << "Construction de la case : " << *this <<endl;
}

Case::~Case() {
  cout << "Destr" << endl;
  //cout << "Destruction de la Case" << *this << endl;
}


bool Case::isEmpty() { return nbPions == 0; }

int Case::getX() { return x; }
int Case::getY() { return y; }
int Case::getNbPionsMax() { return nbPionsMax; }
int Case::getNbPions() { return nbPions; }
int* Case::getTableauIdJoueurs() { return tableauIdJoueurs; }
Pion* Case::getTableauPions() { return tableauPions; }

void Case::setX(int new_x) { x = new_x; }
void Case::setY(int new_y) { y = new_y; }
void Case::setNbPionsMax(int a) { nbPionsMax = a; }
void Case::setNbPions(int a) { nbPions = a; }
void Case::setTableauIdJoueurs(int* a) { tableauIdJoueurs = a; }
void Case::setTableauPions(Pion* a) { tableauPions = a; }

ostream& operator<<(ostream& o, Case& c) {
  o << "<CASE: (" << c.x << ", " << c.y << "), "
    << "nbPions=" << c.nbPions << ", "
    << "nbPionsMax=" << c.nbPionsMax << ", "
    << "tableauIdJoueurs=[";

  for(int i=1 ; i<c.tableauIdJoueurs[0]; i++)
    o << c.tableauIdJoueurs[i] << ", ";
  if(c.tableauIdJoueurs[0] != 0)
    o << c.tableauIdJoueurs[c.tableauIdJoueurs[0]] << "], ";
  else
    o << "], ";

  o << "tableauPions=[";
  for(int i=0 ; i<c.nbPions -2 ; i++)
    o << c.tableauPions[i] << ", ";
  if(c.nbPions != 0)
    o << c.tableauPions[c.nbPions -1] << "]>";
  else
    o << "]>";

  return o;
}
