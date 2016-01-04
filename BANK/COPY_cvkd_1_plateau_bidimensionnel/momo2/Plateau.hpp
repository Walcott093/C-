#ifndef PLATEAU
#define PLATEAU
#include <iostream>
#include "Case.hpp"
using namespace std;

class Plateau {
public:
  Plateau(const int,const int,const int, const int, const int);
  virtual ~Plateau();
  int getLongueur();
  int getLargeur();
  Case** cases;
  void randomBM();
  void randomES();
private:
  const int longueur;
  const int largeur;
  const int nbJoueurs;  
  const int nbBonusMalus;
  const int nbEchelleSerpent; //a changer car manque de genericite
  friend ostream& operator<<(ostream&,Plateau&);
};
#endif //PLATEAU
