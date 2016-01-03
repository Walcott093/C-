#include <iostream>
#include "Plateau.hpp"

#include "Constantes.hpp"
#include "../jeux/EchelleSerpent/CaseEchelleSerpent.hpp"
//#include "../jeux/CartagenaVariante/CaseCartagena.hpp"
//#include "../jeux/Numeri/CaseNumeri.hpp"

using namespace std;



// MODIFIER DE TELLE SORTE A METTRE BONUS ET MALUS

Plateau::Plateau(int rangeOrd, int rangeAbs, string nom, int nbPJ, int nbJT):
  nbLignes(rangeOrd), nbColonnes(rangeAbs), plateauNomJeu(nom), plateauNbPionsParJoueur(nbPJ), plateauNbJoueursTotal(nbJT) {

  /*
  if(plateauNomJeu == ECHELLE_SERPENT) {
    int nbPionsMax = plateauNbPionsParJoueur * plateauNbJoueursTotal;
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, nbPionsMax, 0, ...);
  }

  /*
  else if(plateauNomJeu == ECHELLE_SERPENT_ORANGE_VERTE) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
  }
  
  else if(plateauNomJeu == ECHELLE_SERPENT_PEDAGOGIQUE) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
  }

  else if(plateauNomJeu == ECHELLE_SERPENT_PLUSIEURS_PIONS) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
  }
   
  else if(plateauNomJeu == CARTAGENA_VARIANTE) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseCartagena(i, j, ...);
  }

  else if(plateauNomJeu == NUMERI) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNumeri(i, j, ...);
  }
    *

  else {
    cout << "[Plateau.cpp] Erreur : Le nom du jeu n'est pas repertorie." << endl;
    exit(EXIT_FAILURE);
    /*
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNormale(i, j, ...);
    *

  }
    */

  cout << "Creation d'un Plateau de taille : " << nbLignes << "*" << nbColonnes << endl;
}


Plateau::~Plateau() {
  cout << "Destruction d'un Plateau" << endl;
}


int Plateau::getNbLignes() { return nbLignes; }
int Plateau::getNbColonnes() { return nbColonnes; }
string Plateau::getPlateauNomJeu() { return plateauNomJeu; }
int Plateau::getPlateauNbPionsParJoueur() { return plateauNbPionsParJoueur; }
int Plateau::getPlateauNbJoueursTotal() { return plateauNbJoueursTotal; }
Case** Plateau::getPlateau() { return plateau; }
void Plateau::setNbLignes(int a) { nbLignes = a; }
void Plateau::setNbColonnes(int a) { nbColonnes = a; }
void Plateau::setPlateauNomJeu(string s) { plateauNomJeu = s; }
void Plateau::setPlateauNbPionsParJoueur(int i) { plateauNbPionsParJoueur = i; }
void Plateau::setPlateauNbJoueursTotal(int i) { plateauNbJoueursTotal = i; }
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

/*
Case* Plateau::operator[](int x, int y) {
  return &(plateau[x][y]);
Case* Plateau::operator[][](int x, int y) {
  return &plateau[x][y];
}
*/
