#include <iostream>
#include "CaseCartagena.hpp"
using namespace std;


/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
CaseCartagena::CaseCartagena(int _position,int _nbPionsMax,int _nbPions, string _symbole):
  Case(_position, _nbPionsMax, _nbPions), symbole(_symbole){

  symbole = randomSymbole();

  cout << "Creation de la CaseCartagena : " << this << endl;
}

CaseCartagena::~CaseCartagena() {
  cout << "Destruction de la CaseCartagena : " << this << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
string CaseCartagena::getSymbole() { return symbole; }

void CaseCartagena::setSymbole(string s) { symbole = s; }
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/




/********** DEBUT : FONCTIONS SUPPLEMENTAIRES **********/
string CaseCartagena::randomSymbole() {
  
}
/********** FIN : FONCTIONS SUPPLEMENTAIRES **********/
