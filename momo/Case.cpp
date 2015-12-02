#include <iostream>
#include "Case.hpp"
Case::Case(){}
Case::Case(int _taille): taille(_taille) , indice(0){
  pions = new Pion[taille];
}

Case::~Case(){}

int Case::getNumero(){
  return numero;
}

void Case::setNumero(int n){
  numero = n;
}

bool Case::isEmpty(){
  return taille == 0;
}

void Case::ajouterPion(Pion p){
  if(indice < taille)
    pions[indice++] = p;
  else
    cout << "[Case.cpp-ajouterPion] : le tableau de pion est plein " << endl;
}

void Case::ajouterPions(Pion p[],int t){
  for(int i = 0 ; i < t ; i++)
    ajouterPion(p[i]);
}

int Case::getTaille(){
  return taille;
}

int Case::getIndice(){
  return indice;
}

ostream& operator<<(ostream& o,Case& c){
  int ind = c.getIndice();
  int taille = c.getTaille();
    for(int i = 0 ; i < taille - ind ; i++){
      o << " ";
    }

  for(int i = 0 ; i < taille ; i ++)
    o << c.pions[i];
   return o;
}
