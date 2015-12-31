#ifndef CASE_HPP
#define CASE_HPP

#include "Pion.hpp"

/***** CLASSE ABSTRAITE *****/

class Case {
public:
  Case();
  virtual ~Case();

  

  bool isEmpty();


private:
  int taille; // Nombre de pions max
  int* tableauIdJoueurs;
  Pion* tableauPions;
  
  int ligne;
  int colonne;

protected:

};

#endif //CASE_HPP
