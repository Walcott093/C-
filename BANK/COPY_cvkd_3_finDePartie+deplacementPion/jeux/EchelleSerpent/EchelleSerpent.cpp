#include <iostream>
#include "EchelleSerpent.hpp"
using namespace std;


/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
EchelleSerpent::EchelleSerpent(string nom, int nbHumains, int nbTotal, int nbPionsParJoueur, int nbLignes, int nbColonnes, int nbE, int nbS, int nbO, int nbV):
  Jeu(nom, nbHumains, nbTotal, nbPionsParJoueur), taillePlateauLignes(nbLignes), taillePlateauColonnes(nbColonnes), nbCasesEchelles(2*nbE), nbCasesSerpents(2*nbS), nbCasesOranges(nbO), nbCasesVertes(nbV) {
  cout << "Construction d'un jeu EchelleSerpent" << endl;
}

EchelleSerpent::EchelleSerpent(string nom, int nbHumains, int nbTotal, int nbPionsParJoueur, Joueur** tab, int nbLignes, int nbColonnes, int nbE, int nbS, int nbO, int nbV):
  Jeu(nom, nbHumains, nbTotal, nbPionsParJoueur, tab), taillePlateauLignes(nbLignes), taillePlateauColonnes(nbColonnes), nbCasesEchelles(2*nbE), nbCasesSerpents(2*nbS), nbCasesOranges(nbO), nbCasesVertes(nbV)  {
  cout << "Construction d'un jeu EchelleSerpent" << endl;
}

EchelleSerpent::~EchelleSerpent() {
  cout << "Destruction d'un jeu EchelleSerpent" << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
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
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
