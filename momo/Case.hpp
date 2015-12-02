#ifndef CASE
#define CASE
#include <iostream>
#include "Pion.hpp"
using namespace std;

class Case {
public:
  Case();
  Case(int);
  virtual ~Case();
  int getNumero();
  bool isEmpty();
  void ajouterPions(Pion[],int);
  void ajouterPion(Pion);
  void setNumero(int);
  int getTaille();
  int getIndice();
  Pion* pions;
private:
  int numero;
  int taille; // aussi egal au nombre de joueurs
  int indice;
  
  friend ostream& operator<<(ostream&,Case&);
};
#endif //CASE
