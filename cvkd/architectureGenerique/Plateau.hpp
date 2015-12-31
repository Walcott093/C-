#ifndef PLATEAU_HPP
#define PLATEAU_HPP

//#include "Case.hpp"


/* template <int n, class T>  (template <int nbBonus, CaseEchelleSerpent>) */

template <class T> // Contient le type de case
class Plateau {
public:
  Plateau(int); // Pour creer un plateau carre
  Plateau(int, int); // Pour creer un plateau rectangulaire
  virtual ~Plateau();

  int getNbLignes();
  int getNbColonnes();
  void setNbLignes(int);
  void setNbColonnes(int);

private:  
  int nbLignes;
  int nbColonnes;
  T** plateau; // Case** plateau
  int nbCasesSpeciales;
  friend ostream& operator<<(ostream&, Plateau&);
};

#endif //PLATEAU_HPP
