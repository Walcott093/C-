#include <iostream>
#include "Jeu.hpp"
using namespace std;

/***** CLASSE ABSTRAITE *****/

Jeu::Jeu(): nbJoueursHumains(0), nbJoueursTotal(0), tableauScoreJoueur(nullptr), nbPionsParJoueur(0) {
  cout << "Construction d'un Jeu" << endl;
}

Jeu::Jeu(int nbHumains, int nbTotal, int nbPions):
  nbJoueursHumains(nbHumains), nbJoueursTotal(nbTotal), nbPionsParJoueur(nbPions) {
  tableauScoreJoueur = new int[nbTotal +1];
  tableauScoreJoueur[0] = nbTotal;

  cout << "Construction d'un Jeu" << endl;
}

Jeu::Jeu(int nbHumains, int nbTotal, int* tab, int nbPions):
  nbJoueursHumains(nbHumains), nbJoueursTotal(nbTotal), tableauScoreJoueur(tab), nbPionsParJoueur(nbPions) {

  cout << "Construction d'un Jeu" << endl;
}

Jeu::~Jeu() { cout << "Destruction d'un Jeu" << endl; }





int Jeu::getScoreJoueur(int joueur) { return tableauScoreJoueur[joueur]; }

void Jeu::getScores() {
  for(int i=1 ; i<nbJoueursTotal ; i++)
    cout << "Score joueur " << i << ": " << tableauScoreJoueur[i] << endl;
}


int Jeu::getNbJoueursHumains() { return nbJoueursHumains; }
int Jeu::getNbJoueursTotal() { return nbJoueursTotal; }
int* Jeu::getTableauScoreJoueur() { return tableauScoreJoueur; }
int Jeu::getNbPionsParJoueur() { return nbPionsParJoueur; }

void Jeu::setNbJoueursHumains(int nb) { nbJoueursHumains = nb; }
void Jeu::setNbJoueursTotal(int nb) { nbJoueursTotal = nb; }
void Jeu::setTableauScoreJoueur(int* tab) { tableauScoreJoueur = tab; } //=========================> marche avec l'histoire de pointeur en argument ???
void Jeu::setNbPionsParJoueur(int nb) { nbPionsParJoueur = nb; }

int Jeu::operator[](int i) { return tableauScoreJoueur[i]; }
