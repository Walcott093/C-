#include <iostream>
#include "CaseNormale.hpp"
using namespace std;

CaseNormale::CaseNormale(int abs, int ord, int nbMax, int nb):
  Case(abs, ord, nbMax, nb) {
  cout << "                              Construction de la CaseNormale : " << *this << endl;
}

CaseNormale::CaseNormale(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions):
  Case(abs, ord, nbMax, nb, pions) {
  cout << "                              Construction de la CaseNormale : " << *this <<endl;
}
/*
CaseNormale::CaseNormale(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions, int* tabId):
  Case(abs, ord, nbMax, nb, pions, tabId) {
  cout << "                              Construction de la CaseNormale : " << *this <<endl;
}
*/

CaseNormale::~CaseNormale() {
  cout << "                              Destruction de la CaseNormale : " << *this << endl;
}


int CaseNormale::randomSpecificite() {
  return 0;
}
