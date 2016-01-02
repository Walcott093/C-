#ifndef CASE_HPP
#define CASE_HPP

#include "Pion.hpp"

/*****CLASSE NORMALE ET PAS  CLASSE ABSTRAITE *****/

class Case {
public:
  Case();
  Case(int, int, int, int);
  Case(int, int, int, int, Pion**, int*); // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  virtual ~Case();

  bool isEmpty();

  int getX();
  int getY();
  int getNbPionsMax();
  int getNbPions();
  int* getTableauIdJoueurs();
  Pion** getTableauPions();

  void setX(int);
  void setY(int);
  void setNbPionsMax(int);
  void setNbPions(int);
  void setTableauIdJoueurs(int*);
  void setTableauPions(Pion**);

private:
  int x;
  int y;

  int nbPionsMax;
  int nbPions;
  Pion** tableauPions; // Tableau de pointeurs de Pion
  int* tableauIdJoueurs; // (length = Jeu::nbJoueursTotal + 1 : [0] = nbJoueursTotal : pour que J1 commence a l'indice 1)

  //protected:

  friend ostream& operator<<(ostream&, Case&);
};

#endif //CASE_HPP
