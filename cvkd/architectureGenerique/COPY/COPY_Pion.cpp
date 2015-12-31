#include <iostream>
#include "Pion.hpp"
using namespace std;

Pion::Pion() {
  cout << "Construction d'un Pion par defaut" << endl;
}

Pion::Pion(int idPlayer, int identifiant, string colour): idJoueur(idPlayer), id(identifiant), couleur(colour) {
  cout << "Contruction du Pion : " << *this << endl;
}
/*
Pion::Pion(int idPlayer, int identifiant, string colour, Case c): idJoueur(idPlayer), id(identifiant), couleur(colour), case(c) {
  cout << "Contruction du Pion : " << *this << endl;
  }*/

Pion::~Pion() {
  cout << "Destruction du Pion : " << *this << endl;
}


int Pion::getIdJoueur() { return idJoueur; }
int Pion::getId() { return id; }
string Pion::getCouleur() { return couleur; }
//Case* Pion::getCase() { return case; }

void Pion::setIdJoueur(int idPlayer) { idJoueur = idPlayer; }
void Pion::setId(int identifiant) { id = identifiant; }
void Pion::setCouleur(string colour) { couleur = colour; }
//void Pion::setCase(Case* c) { case = c; }

ostream& operator<<(ostream& o, Pion& p) {
  o << "idJoueur=" << p.idJoueur << " | "
    << "id=" << p.id << " | "
    << "couleur=" << p.couleur;
  //<< "case=" << p.case << " | ";
  return o;
}
