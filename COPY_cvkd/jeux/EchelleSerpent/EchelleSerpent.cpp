#include <iostream>
#include "EchelleSerpent.hpp"
using namespace std;

EchelleSerpent::EchelleSerpent(string nom, int nbHumains, int nbTotal, int nbPionsParJoueur, int nbLignes, int nbColonnes, int nbE, int nbS, int nbO, int nbV):
  Jeu(nom, nbHumains, nbTotal, nbPionsParJoueur), taillePlateauLignes(nbLignes), taillePlateauColonnes(nbColonnes), nbCasesEchelles(nbE), nbCasesSerpents(nbS), nbCasesOranges(nbO), nbCasesVertes(nbV) {
  cout << "Construction d'un jeu EchelleSerpent" << endl;
}

EchelleSerpent::EchelleSerpent(string nom, int nbHumains, int nbTotal, int nbPionsParJoueur, int* tab, int nbLignes, int nbColonnes, int nbE, int nbS, int nbO, int nbV):
  Jeu(nom, nbHumains, nbTotal, nbPionsParJoueur, tab), taillePlateauLignes(nbLignes), taillePlateauColonnes(nbColonnes), nbCasesEchelles(nbE), nbCasesSerpents(nbS), nbCasesOranges(nbO), nbCasesVertes(nbV)  {
  cout << "Construction d'un jeu EchelleSerpent" << endl;
}

EchelleSerpent::~EchelleSerpent() {
  cout << "Destruction d'un jeu EchelleSerpent" << endl;
}


bool EchelleSerpent::finDePartie(Plateau plateau) {
  Case* c = plateau[plateau.getNbColonnes() -1][plateau.getNbLignes() -1];
  if(c->getNbPions() >= nbPionsParJoueur) {
    forward_list<Pion> list = c->getListePions();
    int idJoueur = (*list.begin()).getIdJoueur();

    for(auto it=list.begin() ; it!=list.end() ; ++it) {
      if((*it).getIdJoueur() != idJoueur) {
	cout << "FALSE: " << (*it).getIdJoueur() << " & " << idJoueur << endl;
	return false;   
      }
    }
    return true;
  }
  else {
    //cout << "[EchelleSerpent.cpp]/finDePartie : Pas assez de pions sur la derniere case." << endl;
    return false;
  }
}


int EchelleSerpent::deplacementPion(Plateau plateau, Pion pion) {

}


int EchelleSerpent::getTaillePlateauLignes() { return taillePlateauLignes; }
int EchelleSerpent::getTaillePlateauColonnes() { return taillePlateauColonnes; }
int EchelleSerpent::getNbCasesEchelles() { return nbCasesEchelles; }
int EchelleSerpent::getNbCasesSerpents() { return nbCasesSerpents; }
int EchelleSerpent::getNbCasesOranges() { return nbCasesOranges; }
int EchelleSerpent::getNbCasesVertes() { return nbCasesVertes; }
void EchelleSerpent::setTaillePlateauLignes(int a) { taillePlateauLignes = a; }
void EchelleSerpent::setTaillePlateauColonnes(int a) { taillePlateauColonnes = a; }
void EchelleSerpent::setNbCasesEchelles(int a) { nbCasesEchelles = a; }
void EchelleSerpent::setNbCasesSerpents(int a) { nbCasesSerpents = a; }
void EchelleSerpent::setNbCasesOranges(int a) { nbCasesOranges = a; }
void EchelleSerpent::setNbCasesVertes(int a) { nbCasesVertes = a; }
