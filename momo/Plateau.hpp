#ifndef PLATEAU
#define PLATEAU
#include <iostream>
#include "Case.hpp"
using namespace std;

class Plateau {
public:
  Plateau(const int,const int,const int);
  virtual ~Plateau();
  int getLongueur();
  int getLargeur();
  Case** cases;
private:
  const int longueur;
  const int largeur;
  const int taille;  

  friend ostream& operator<<(ostream&,Plateau&);
};
#endif //PLATEAU
