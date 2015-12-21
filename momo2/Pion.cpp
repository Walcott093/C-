#include <iostream>
#include "Pion.hpp"

Pion::Pion(){}
Pion::Pion(string _nom,string _couleur,int _x,int _y,int _longueur,int _largeur):
  nom(_nom) , couleur(_couleur) , x(_x) , y(_y), longueur(_longueur),largeur(_largeur) {}

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


void Pion::avancer(int nbCases){
  if(x%2 == 0){ //ligne pair
    if(largeur-(y+1+nbCases) >= 0){ // si il ne passe pas a la ligne du haut
      y +=nbCases;
    }
    else if(largeur-(y+1+nbCases)<0){ // si il passe a la case du haut
      x++;
      y = largeur-(nbCases-(largeur-y+1)); //8-(7-(8-6)) = 3 OK 
    }
  }
  else { // ligne impair
    
  }
}
