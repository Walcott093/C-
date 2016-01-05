#include <iostream>
#include "CaseCartagena.hpp"

CaseCartagena::CaseCartagena(string _symbole,int _specificite,int _position,int _nbPionsMax,int _nbPions):
  symbole(_symbole),Case(_specificite,_position,_nbPionsMax,_nbPions){}

CaseCartagena::~CaseCartagena(){
  cout << "Destruction de la caseCartagena" << endl;
}

string getSymbole(){
  return symbole;
}

void setSymbole(string s){
  symbole = s;
}
