#include <iostream>
#include "EchelleSerpent.hpp"
using namespace std;

EchelleSerpent::EchelleSerpent(string nom, int nbHumains, int nbTotal, int nbPionsParJoueur):
  Jeu(nom, nbHumains, nbTotal, nbPionsParJoueur){
  cout << "Construction d'un jeu EchelleSerpent" << endl;
}

EchelleSerpent::EchelleSerpent(string nom, int nbHumains, int nbTotal, int nbPionsParJoueur, int* tab):
  Jeu(nom, nbHumains, nbTotal, nbPionsParJoueur, tab) {
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
