#include <iostream>
#include "CaseEchelleSerpent.hpp"
using namespace std;

CaseEchelleSerpent::CaseEchelleSerpent(int abs, int ord, int nbMax, int nb, bool boo):
  Case(abs, ord, nbMax, nb), variante(boo) {
  specificite = randomSpecificite();

  cout << "                              Construction de la CaseEchelleSerpent : " << *this << endl;
}

CaseEchelleSerpent::CaseEchelleSerpent(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions, int* tabId, bool boo):
  Case(abs, ord, nbMax, nb, pions, tabId), variante(boo) {
  specificite = randomSpecificite();

  cout << "                              Construction de la CaseEchelleSerpent : " << *this <<endl;
}

CaseEchelleSerpent::~CaseEchelleSerpent() {
  cout << "                              Destruction de la CaseEchelleSerpent : " << *this << endl;
}


// Vaut-il mieux faire une fonction qui renvoie forcement une specificite (et donc ne renvoie pas NEUTRE ?
int CaseEchelleSerpent::randomSpecificite() {
  srand(time(nullptr));
  if(variante)
    return rand() % NB_SPECIFICITES_ESOV;
  else
    return rand() % NB_SPECIFICITES_ES;
}


bool CaseEchelleSerpent::getVariante() { return variante; }
int CaseEchelleSerpent::getSpecificite() { return specificite; }
void CaseEchelleSerpent::setVariante(bool boo) { variante = boo; }
void CaseEchelleSerpent::setSpecificite(int s) { specificite = s; }
