#include <iostream>
#include "Jeu.hpp"
#include "Constantes.hpp"
using namespace std;

/***** CLASSE ABSTRAITE *****/


static int idJoueur = 0;
static int joueursHumainsCrees = 0;
static int joueursRobotsCrees = 0;

Jeu::Jeu(): nomJeuOuVariante(""), nbJoueursHumains(0), nbJoueursTotal(0), nbPionsParJoueur(0), tableauJoueurs(nullptr) {
  cout << "Construction d'un Jeu" << endl;
}

Jeu::Jeu(string nom, int nbHumains, int nbTotal, int nbPions):
  nomJeuOuVariante(nom), nbJoueursHumains(nbHumains), nbJoueursTotal(nbTotal), nbPionsParJoueur(nbPions) {
  
  tableauJoueurs = new Joueur*[nbJoueursTotal];
  for(int i=0 ; i<nbJoueursTotal ; i++) {
    tableauJoueurs[i] = creationJoueur();
  }

  cout << "Construction d'un Jeu" << endl;
}

Jeu::Jeu(string nom, int nbHumains, int nbTotal, int nbPions, Joueur** tab):
  nomJeuOuVariante(nom), nbJoueursHumains(nbHumains), nbJoueursTotal(nbTotal), nbPionsParJoueur(nbPions), tableauJoueurs(tab) {
  cout << "Construction d'un Jeu" << endl;
}

Jeu::~Jeu() { cout << "Destruction d'un Jeu" << endl; }


Joueur* Jeu::creationJoueur() {
  string nom;
  if(joueursHumainsCrees < nbJoueursHumains) {
    cout << "Entrez le nom du joueur :" << endl;
    cin >> nom;
    joueursHumainsCrees++;
  }
  else {
    switch(joueursRobotsCrees++) {
    case 0:
      nom = NOM_1;
      break;
    case 1:
      nom = NOM_2;
      break;
    case 2:
      nom = NOM_3;
      break;
    case 3:
      nom = NOM_4;
      break;
    default:
      nom = NOM_1;
      break;
    }
  }

  int score = 0;

  string couleur;
  if(idJoueur == 0) couleur = COULEUR_1;
  else if(idJoueur == 1) couleur = COULEUR_2;
  else if(idJoueur == 2) couleur = COULEUR_3;
  else couleur = COULEUR_4; // if(idJoueur == 3)
  idJoueur++;
  
  int idPion = 0;
  Pion** tab = new Pion*[nbPionsParJoueur];
  for(int i=0 ; i<nbPionsParJoueur ; i++) {
    tab[i] = new Pion(idJoueur, idPion++, couleur, 0, 0);
  }
  return new Joueur(idJoueur, nom, score, nbPionsParJoueur, tab);
}


int Jeu::getScoreJoueur(int joueur) { return tableauJoueurs[joueur]->getScore(); }

void Jeu::getScores() {
  for(int i=0 ; i<nbJoueursTotal ; i++)
    cout << "Score joueur " << i << ": " << tableauJoueurs[i]->getScore() << endl;
}

string Jeu::getNomJeuOuVariante() { return nomJeuOuVariante; }
int Jeu::getNbJoueursHumains() { return nbJoueursHumains; }
int Jeu::getNbJoueursTotal() { return nbJoueursTotal; }
int Jeu::getNbPionsParJoueur() { return nbPionsParJoueur; }
Joueur** Jeu::getTableauJoueurs() { return tableauJoueurs; }

void Jeu::setNomJeuOuVariante(string nom) { nomJeuOuVariante = nom; }
void Jeu::setNbJoueursHumains(int nb) { nbJoueursHumains = nb; }
void Jeu::setNbJoueursTotal(int nb) { nbJoueursTotal = nb; }
void Jeu::setNbPionsParJoueur(int nb) { nbPionsParJoueur = nb; }
void Jeu::setTableauJoueurs(Joueur** tab) { tableauJoueurs = tab; } //=========================> marche avec l'histoire de pointeur en argument ???

Joueur* Jeu::operator[](int i) { return tableauJoueurs[i]; }
