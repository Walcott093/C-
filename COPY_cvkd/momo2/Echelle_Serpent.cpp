#include <iostream>
#include "Echelle_Serpent.hpp"

using namespace std;
Echelle_Serpent::Echelle_Serpent():isEchelle(false),isSerpent(false){}
Echelle_Serpent::Echelle_Serpent(int _ihaut,int _jhaut,int _ibas,int _jbas,bool _isEchelle,bool _isSerpent): ihaut(_ihaut), jhaut(_jhaut), ibas(_ibas), jbas(_jbas),isEchelle(_isEchelle),isSerpent(_isSerpent){}

Echelle_Serpent::~Echelle_Serpent(){}

int Echelle_Serpent::getIhaut(){
  return ihaut;
}
int Echelle_Serpent::getJhaut(){
  return jhaut;
}
int Echelle_Serpent::getIbas(){
  return ibas;
}
int Echelle_Serpent::getJbas(){
  return jbas;
}

void Echelle_Serpent::setIhaut(int i){
  ihaut = i;
}
void Echelle_Serpent::setJhaut(int j){
  jhaut = j;
}
void Echelle_Serpent::setIbas(int i){
  ibas = i;
}
void Echelle_Serpent::setJbas(int j){
  jbas = j;
}

bool Echelle_Serpent::getIsEchelle(){
  return isEchelle;
}

bool Echelle_Serpent::getIsSerpent(){
  return isSerpent;
}
void Echelle_Serpent::setIsEchelle(bool b){
  isEchelle = b;
}

void Echelle_Serpent::setIsSerpent(bool b){
  isSerpent = b;
}
