#include <iostream>
#include "Plateau.hpp"

#include "Constantes.hpp"
#include "CaseEchelleSerpent.hpp"
//#include "CaseCartagena.hpp"
//#include "CaseNumeri.hpp"

using namespace std;



// MODIFIER DE TELLE SORTE A METTRE BONUS ET MALUS

Plateau::Plateau(Jeu* game, int rangeOrd, int rangeAbs):
  jeu(game), nbLignes(rangeOrd), nbColonnes(rangeAbs) {

  switch(jeu->getNomJeuOuVariante()) {
  case ECHELLE_SERPENT:
    int nbPionsMax = (jeu->getNbPionsParJoueur()) * (jeu->getNbJoueursTotal());
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, nbPionsMax, 0, ...);
    break;

    /*
  case ECHELLE_SERPENT_ORANGE_VERTE:
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;

    
  case ECHELLE_SERPENT_PEDAGOGIQUE:
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;

  case ECHELLE_SERPENT_PLUSIEURS_PIONS:
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
    break;
    
  case CARTAGENA_VARIANTE:
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseCartagena(i, j, ...);
    break;

  case NUMERI:
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNumeri(i, j, ...);
    break;
    */

  default:
    cout << "[Plateau.cpp] Erreur : Le nom du jeu n'est pas repertorie." << endl;
    exit(EXIT_FAILURE);
    /*
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNormale(i, j, ...);
    */
    break;
  }

  cout << "Creation d'un Plateau de taille : " << x << "*" << y << endl;
}


Plateau::~Plateau() {
  cout << "Destruction d'un Plateau" << endl;
}

Jeu* Plateau::getJeu() { return jeu; }
int Plateau::getNbLignes() { return nbLignes; }
int Plateau::getNbColonnes() { return nbColonnes; }
Case** Plateau::getPlateau() { return plateau; }
void Plateau::setJeu(Jeu* j) { jeu = j; }
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
