#include <iostream>
#include "Jeu.hpp"
using namespace std;

/***** CLASSE ABSTRAITE *****/

Jeu::Jeu(): nbJoueursHumains(0), nbJoueursTotal(0), tableauScoreJoueur(nullptr) {
  cout << "Construction d'un Jeu" << endl;
}

Jeu::~Jeu() { cout << "Destruction d'un Jeu" << endl; }

int Jeu::getScoreJoueur(int joueur) { return tableauScoreJoueur[joueur]; }

void Jeu::getScores() {
  for(int i=1 ; i<nbJoueursTotal ; i++)
    cout << "Score joueur " << i << ": " << tableauScoreJoueur[i] << " | ";
  cout << endl;
}


int Jeu::getNbJoueursHumains() { return nbJoueursHumains; }
int Jeu::getNbJoueursTotal() { return nbJoueursTotal; }
int* Jeu::getTableauScoreJoueur() { return tableauScoreJoueur; }

void Jeu::setNbJoueursHumains(int nb) { nbJoueursHumains = nb; }
void Jeu::setNbJoueursTotal(int nb) { nbJoueursTotal = nb; }
void Jeu::setTableauScoreJoueur(int* tab) { tableauScoreJoueur = tab; } //=========================> marche avec l'histoire de pointeur en argument ???
