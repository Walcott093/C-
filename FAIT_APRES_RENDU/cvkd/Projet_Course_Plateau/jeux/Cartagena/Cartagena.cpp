#include <iostream>
#include "Cartagena.hpp"
using namespace std;

static int idJoueur = 0;
static int joueursHumainsCrees = 0;
static int joueursRobotsCrees = 0;


/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
Cartagena::Cartagena(): Jeu("", 0, 0, 0) {
  cout << "Construction d'un jeu Cartagena" << endl;
}

Cartagena::Cartagena(string nom, int nbHumains, int nbTotal, int nbPions):
  Jeu(nom, nbHumains, nbTotal, nbPions) {

  tableauJoueurs = new Joueur*[nbJoueursTotal];
  for(int i=0 ; i<nbJoueursTotal ; i++) {
    tableauJoueurs[i] = creationJoueur();
  }

  cout << "Construction d'un jeu Cartagena" << endl;
}

Cartagena::Cartagena(string nom, int nbHumains, int nbTotal, int nbPions, Joueur** tab):
  Jeu(nom, nbHumains, nbTotal, nbPions, tab) {
  cout << "Construction d'un jeu Cartagena" << endl;
} 

Cartagena::~Cartagena() { cout << "Destruction d'un jeu Cartagena" << endl; }
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/

/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/




/********** DEBUT : FONCTIONS SUPPLEMENTAIRES **********/
Joueur* Jeu::creationJoueur() {
  cout << "--- Creation de JoueurCartagena ---" << endl;
  string nom;
  bool estHumain = false;
  if(joueursHumainsCrees < nbJoueursHumains) {
    cout << "Entrez le nom du joueur :" << endl;
    cin >> nom;
    joueursHumainsCrees++;
    estHumain = true;
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
  if(idJoueur == 0) couleur = ROUGE;
  else if(idJoueur == 1) couleur = BLEU;
  else if(idJoueur == 2) couleur = VERT;
  else couleur = JAUNE; // if(idJoueur == 3)
  
  int idPion = 0;
  Pion** tab = new Pion*[nbPionsParJoueur];
  for(int i=0 ; i<nbPionsParJoueur ; i++) {
    tab[i] = new Pion(idJoueur, idPion++, couleur, 0);
  }
  return new Joueur(estHumain, idJoueur++, nom, score, nbPionsParJoueur, tab);
}
/********** FIN : FONCTIONS SUPPLEMENTAIRES **********/
