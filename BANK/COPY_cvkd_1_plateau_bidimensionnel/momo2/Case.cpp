#include <iostream>
#include "Case.hpp"

Case::Case(){}
Case::Case(int _taille): taille(_taille) , indice(0),isBonus(false),isMalus(false){
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
    cout << "[Case.cpp-ajouterPion] : le tableau de pion est plein" << endl;
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

bool Case::getIsBonus(){
  return isBonus;
}
bool Case::getIsMalus(){
  return isMalus;
}

void Case::setIsBonus(bool b){
  isBonus = b;
}
void Case::setIsMalus(bool b){
  isMalus = b;
}

bool Case::estVide(){
  return !isBonus && !isMalus && !es.getIsEchelle() && !es.getIsSerpent();
}
  
ostream& operator<<(ostream& o, Case& c){
  int ind = c.getIndice();
  int taille = c.getTaille();
  if(c.isBonus)
    o << "\033[1;53;33mB\033[0m";
  else if(c.isMalus)
    o << "M";
  else o << " ";

  if(c.es.getIsEchelle())
    o << "\033[1;34mH\033[0m";
  else if(c.es.getIsSerpent())
    o << "\033[1;31mS\033[0m";
  else o << " ";
  for(int i = 0 ; i < taille - ind ; i++){
    o << " ";
  }
  
  for(int i = 0 ; i < taille ; i++)
    o << c.pions[i];
  return o;
}
