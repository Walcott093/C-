#include <iostream>
#include "Plateau.hpp"

using namespace std;

Plateau::Plateau(const int _longueur, const int _largeur, const int _taille):
  longueur(_longueur) , largeur(_largeur) , taille(_taille){

  cases = new Case*[longueur];

  for(int i = longueur-1 ; i >= 0 ; i-- ){
    cases[i] = new Case[largeur];
    for(int j = 0 ; j < largeur ; j++)
      cases[i][j] = Case(taille);
  }
}

Plateau::~Plateau(){
}

int Plateau::getLongueur(){
  return longueur;
}

int Plateau::getLargeur(){
  return largeur;
}

ostream& operator<<(ostream& o,Plateau& p){

  for(int i = p.getLongueur()-1 ; i >= 0 ; i --){
      o << "|";
    for(int j = 0 ; j < p.getLargeur() ; j++)
      o << p.cases[i][j] << "|";
    o << endl;

  }
  return o;
}
