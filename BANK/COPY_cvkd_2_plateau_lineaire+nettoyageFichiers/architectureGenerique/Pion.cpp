#include <iostream>
#include "Pion.hpp"
using namespace std;

/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
Pion::Pion(): idJoueur(0), id(0), couleur(""), position(0) {
  cout << "                              Construction d'un Pion par defaut" << endl;
}

Pion::Pion(int idPlayer, int identifiant, string colour, int pos): idJoueur(idPlayer), id(identifiant), couleur(colour), position(pos) {
  cout << "                              Contruction du Pion : " << *this << endl;
}

Pion::~Pion() {
  cout << "                              Destruction du Pion : " << *this << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
int Pion::getIdJoueur() { return idJoueur; }
int Pion::getId() { return id; }
string Pion::getCouleur() { return couleur; }
int Pion::getPosition() { return position; }


void Pion::setIdJoueur(int idPlayer) { idJoueur = idPlayer; }
void Pion::setId(int identifiant) { id = identifiant; }
void Pion::setCouleur(string colour) { couleur = colour; }
void Pion::setPosition(int new_pos) { position = new_pos; }

ostream& operator<<(ostream& o, Pion& p) {
  o << "(" << p.idJoueurs << ", " << p.id << ")" << endl;
  return o;
}
/*
ostream& operator<<(ostream& o, Pion& p) {
  o << "<PION: (" << p.x << ", " << p.y << "), "
    << "idJoueur=" << p.idJoueur << ", "
    << "id=" << p.id << ", "
    << "couleur=" << p.couleur << ">";
  return o;
}
*/
bool Pion::operator==(const Pion& other) {

  if(idJoueur == other.idJoueur
     && id == other.id
     && couleur == other.couleur
     && position == other.position)
    return true;
  else
    return false;     
}
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
