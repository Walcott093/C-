#include <iostream>
#include "Pion.hpp"
using namespace std;

Pion::Pion(): idJoueur(0), id(0), couleur(""), x(0), y(0) {
  cout << "                              Construction d'un Pion par defaut" << endl;
}

/*
Pion::Pion(int idPlayer, int identifiant, string colour, Case c): idJoueur(idPlayer), id(identifiant), couleur(colour), case(c) {
  cout << "                              Contruction du Pion : " << *this << endl;
}
*/

Pion::Pion(int idPlayer, int identifiant, string colour, int abscisse, int ordonnee): idJoueur(idPlayer), id(identifiant), couleur(colour), x(abscisse), y(ordonnee) {
  cout << "                              Contruction du Pion : " << *this << endl;
}


Pion::~Pion() {
  cout << "                              Destruction du Pion : " << *this << endl;
}


int Pion::getIdJoueur() { return idJoueur; }
int Pion::getId() { return id; }
string Pion::getCouleur() { return couleur; }
//Case* Pion::getCase() { return case; }
int Pion::getX() { return x; }
int Pion::getY() { return y; }

void Pion::setIdJoueur(int idPlayer) { idJoueur = idPlayer; }
void Pion::setId(int identifiant) { id = identifiant; }
void Pion::setCouleur(string colour) { couleur = colour; }
//void Pion::setCase(Case* c) { case = c; }
void Pion::setX(int new_x) { x = new_x; }
void Pion::setY(int new_y) { y = new_y; }


ostream& operator<<(ostream& o, Pion& p) {
  o << "<PION: (" << p.x << ", " << p.y << "), "
    << "idJoueur=" << p.idJoueur << ", "
    << "id=" << p.id << ", "
    << "couleur=" << p.couleur << ">";
  return o;
}

bool Pion::operator==(const Pion& other) {
  if(idJoueur == other.idJoueur
     && id == other.id
     && couleur == other.couleur
     && x == other.x
     && y == other.y)
    return true;
  else
    return false;     
}

