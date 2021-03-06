#include <iostream>
#include "Joueur.hpp"
using namespace std;

Joueur::Joueur(): id(0), nom("toto"), score(0), nbPions(0), tabPions(nullptr) {
  cout << "Creation d'un Joueur par defaut" << endl;
}
Joueur::Joueur(int i, string s, int sc, int nb, Pion** tab):
  id(i), nom(s), score(sc), nbPions(nb), tabPions(tab) {
  cout << "Creation d'un Joueur" << endl;
}
Joueur::~Joueur() {
  cout << "Destruction d'un Joueur" << endl;
}



int Joueur::getId() { return id; }
string Joueur::getNom() { return nom; }
int Joueur::getScore() { return score; }
int Joueur::getNbPions() { return nbPions; }
Pion** Joueur::getTabPions() { return tabPions; }

void Joueur::setId(int i) { id = i; }
void Joueur::setNom(string s) { nom = s; }
void Joueur::setScore(int i) { score = i; }
void Joueur::setNbPions(int i) { nbPions = i; }
void Joueur::setTabPions(Pion** t) { tabPions = t; }


ostream& operator<<(ostream& o, Joueur& j) {
  o << "<JOUEUR: id=" << j.id << ", "
    << "nom=" << j.nom << ", "
    << "score=" << j.score << ", "
    << "tabPions=[";

  switch(j.nbPions) {
  case 0:
    o << "]>";
    break;
  case 1:
    o << "\n  " << *(j.tabPions[0]) << "]>";
    break;
  default:
    int cpt = 0;
    for(int i=0 ; i<j.nbPions ; i++) {
      if(cpt++ == j.nbPions -1)
	o << "\n  " << *(j.tabPions[i]) << "]>";
      else 
	o << "\n  " << *(j.tabPions[i]) << ",";
    }
    break;
  }
  
  return o;
}
