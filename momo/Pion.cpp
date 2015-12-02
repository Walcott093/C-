#include <iostream>
#include "Pion.hpp"

Pion::Pion(){}
Pion::Pion(string _nom,string _couleur,int _x,int _y):
  nom(_nom) , couleur(_couleur) , x(_x) , y(_y) {}

Pion::~Pion(){
}


string Pion::getNom(){
  return nom;
}
void Pion::setNom(string _nom){
  nom = _nom;
}

string Pion::getCouleur(){
  return couleur;
}
void Pion::setCouleur(string _couleur){
  couleur = _couleur;
}

int Pion::getX(){
  return x;
}
void Pion::setX(int _x){
  x =  _x;
}

int Pion::getY(){
  return y;
}

void Pion::setY(int _y){
  y =  _y;
}

ostream& operator<<(ostream& o,Pion& p){
  o << p.getCouleur();
  return o;
}
