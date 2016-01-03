#include <iostream>
#include "Plateau.hpp"

using namespace std;


/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
Plateau::Plateau(int rangeOrd, int rangeAbs, string nom, int nbPJ, int nbJT):
  nbLignes(rangeOrd), nbColonnes(rangeAbs), nbCases(rangeOrd*rangeAbs), plateauNomJeu(nom), plateauNbPionsParJoueur(nbPJ), plateauNbJoueursTotal(nbJT) {

  
  if(plateauNomJeu == ECHELLE_SERPENT) {
    int nbPionsMax = plateauNbPionsParJoueur * plateauNbJoueursTotal;
    for(int i=0 ; i<nbCases ; i++)
      plateau[i] = new CaseEchelleSerpent(i, nbPionsMax, 0, 

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
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
int Plateau::getNbLignes() { return nbLignes; }
int Plateau::getNbColonnes() { return nbColonnes; }
int Plateau::getNbCases() { return nbCases; }
string Plateau::getPlateauNomJeu() { return plateauNomJeu; }
int Plateau::getPlateauNbPionsParJoueur() { return plateauNbPionsParJoueur; }
int Plateau::getPlateauNbJoueursTotal() { return plateauNbJoueursTotal; }
Case* Plateau::getPlateau() { return plateau; }

void Plateau::setNbLignes(int a) { nbLignes = a; }
void Plateau::setNbColonnes(int a) { nbColonnes = a; }
void Plateau::setNbCases(int a) { nbCases = a; }
void Plateau::setPlateauNomJeu(string s) { plateauNomJeu = s; }
void Plateau::setPlateauNbPionsParJoueur(int i) { plateauNbPionsParJoueur = i; }
void Plateau::setPlateauNbJoueursTotal(int i) { plateauNbJoueursTotal = i; }
void Plateau::setPlateau(Case* c) { plateau = c; }

ostream& operator<<(ostream& o,Plateau& p){
  int cptLignes = p.getNbLignes();
  int cptColonnes = p.getNbColonnes(); //= 1;
  for(int i=p.getNbCases() ; i>=1 ; i-=p.getNbColonnes()) {
    o << "|";
    if(cptLignes % 2 == 1) { // Si ligne impaire : sensPion = g->d ; sensAffichage = d->g
      for(int c=p.getNbColonnes()-1 ; c>=0 ; c--)
	o << p.plateau[i -c -1] << "|";
      o << endl;
      cptLignes--;
    }
    else { // Si ligne paire : sensPion = d->g ; sensAffichage = g->d
      for(int c=0 ; c<=p.getNbColonnes()-1 ; c++)
	o << p.plateau[i -c -1] << "|";
      o << endl;
      cptLignes--;
    }
  }
  return o;
}

Case Plateau::operator[](int pos) {
  return plateau[pos];
}
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
