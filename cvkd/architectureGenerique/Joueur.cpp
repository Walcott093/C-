#include <iostream>
#include "Joueur.hpp"
using namespace std;

Joueur::Joueur(): id(0), nom("toto"), score(0), tabPions(nullptr) {
  cout << "Creation d'un Joueur par defaut" << endl;
}
Joueur::Joueur(int i, string s, int sc, Pion* tab):
  id(i), nom(s), score(sc), tabPions(tab) {
  cout << "Creation d'un Joueur" << endl;
}
Joueur::~Joueur() {
  cout << "Destruction d'un Joueur" << endl;
}



int Joueur::getId() { return id; }
string Joueur::getNom() { return nom; }
int Joueur::getScore() { return score; }
Pion* Joueur::getTabPions() { return tabPions; }

void Joueur::setId(int i) { id = i; }
void Joueur::setNom(string s) { nom = s; }
void Joueur::setScore(int i) { score = i; }
void Joueur::setTabPions(Pion* t) { tabPions = t; }
