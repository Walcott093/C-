#include <iostream>
#include "Plateau.hpp"

#include "CaseEchelleSerpent.hpp"
#include "CaseCartagena.hpp"
#include "CaseNumeri.hpp"

using namespace std;

// MODIFIER DE TELLE SORTE A METTRE BONUS ET MALUS

Plateau::Plateau(int rangeOrd, int rangeAbs, string type): nbLignes(rangeOrd), nbColonnes(rangeAbs), jeu(type) {
  switch(jeu) {
  case "CaseEchelleSerpent":
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;

  case "CaseEchelleSerpent+OrangeVerte":
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;
    /*
  case "CaseEchelleSerpent+Pedagogique":
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;

  case "CaseEchelleSerpent+PlusieursPions":
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;
    */
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


ostream& operator<<(ostream& o,Plateau& p){
  for(int i=p.getNbLignes()-1 ; i>=0 ; i --){
      o << "|";
    for(int j=0 ; j<p.getNbColonnes() ; j++)
      o << p.plateau[i][j] << "|";
    o << endl;
  }
  return o;
}

Case* Plateau::operator[][](int x, int y) {
  return &plateau[x][y];
}
