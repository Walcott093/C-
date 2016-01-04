#ifndef CASE
#define CASE
#include <iostream>
#include "Pion.hpp"
#include "Echelle_Serpent.hpp"
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
  bool getIsBonus();
  bool getIsMalus();
  void setIsBonus(bool);
  void setIsMalus(bool);
  void avancer(int);
  bool estVide();
  Pion* pions;
  Echelle_Serpent es;
private:
  int numero;
  int taille; // aussi egal au nombre de joueurs
  int indice;
  bool isBonus;
  bool isMalus;
 
 
  friend ostream& operator<<(ostream&,Case&);
};
#endif //CASE
