#include <iostream>
#include "CaseNormale.hpp"
using namespace std;

/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
CaseNormale::CaseNormale(int pos, int nbMax, int nb):
  Case(pos, nbMax, nb) {
  cout << "                              Construction de la CaseNormale : " << *this << endl;
}

CaseNormale::CaseNormale(int pos, int nbMax, int nb, forward_list<Pion> pions):
  Case(pos, nbMax, nb, pions) {
  cout << "                              Construction de la CaseNormale : " << *this <<endl;
}

CaseNormale::~CaseNormale() {
  cout << "                              Destruction de la CaseNormale : " << *this << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : FONCTIONS SUPPLEMENTAIRES **********/
int CaseNormale::randomSpecificite() {
  return 0;
}
/********** FIN : FONCTIONS SUPPLEMENTAIRES **********/
