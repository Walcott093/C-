#include <iostream>
#include "Plateau.hpp"

#include "CaseEchelleSerpent.hpp"
#include "CaseCartagena.hpp"
#include "CaseNumeri.hpp"

using namespace std;

// MODIFIER DE TELLE SORTE A METTRE BONUS ET MALUS
/*
Plateau::Plateau(int x): nbLignes(x), nbColonnes(x), plateau(new Case[x][x]) {
  cout << "Creation d'un Plateau de taille : " << x << "*" << x << endl;
}
*/

Plateau::Plateau(int rangeOrd, int rangeAbs, string type): nbLignes(rangeOrd), nbColonnes(rangeAbs), typeCase(type) {
  switch(typeCase) {
  case "CaseEchelleSerpent":
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;

  case "CaseCartagena":
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseCartagena(i, j, ...);

    break;
  case "CaseNumeri":
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNumeri(i, j, ...);

    break;
  default:
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNormale(i, j, ...);

    break;
  }

  cout << "Creation d'un Plateau de taille : " << x << "*" << y << endl;
}


Plateau::~Plateau() {
  cout << "Destruction d'un Plateau" << endl;
}


int Plateau::getNbLignes() { return nbLignes; }
int Plateau::getNbColonnes() { return nbColonnes; }
Case** Plateau::getPlateau() { return plateau; }
void Plateau::setNbLignes(int a) { nbLignes = a; }
void Plateau::setNbColonnes(int a) { nbColonnes = a; }
void Plateau::setPlateau(Case** c) { plateau = c; }

Case* Plateau::operator[][](int x, int y) {
  return &plateau[x][y];
}
