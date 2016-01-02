#ifndef CASE_HPP
#define CASE_HPP

#include "Pion.hpp"
#include <forward_list>

/***** CLASSE ABSTRAITE *****/

class Case {
protected:
  virtual int randomSpecificite() = 0;


public:
  Case();
  
  Case(int, int, int, int);
  Case(int, int, int, int, forward_list<Pion>, int*); // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  virtual ~Case();

  bool isEmpty();
  bool ajouterPion(Pion);
  bool ajouterPions(forward_list<Pion>, int);
  //bool ajouterPions(Pion*, int);
  bool retirerPion(Pion);
  bool retirerPions(forward_list<Pion>, int);
  //bool retirerPions(Pion*, int);

  int getX();
  int getY();
  int getNbPionsMax();
  int getNbPions();
  int* getTableauIdJoueurs();
  forward_list<Pion> getListePions();
  //Pion* getTableauPions();
  void setX(int);
  void setY(int);
  void setNbPionsMax(int);
  void setNbPions(int);
  void setTableauIdJoueurs(int*);
  void setListePions(forward_list<Pion>);
  //void setTableauPions(Pion*);

  //const int NB_JOUEURS_MAX = 4;


private:
  int x;
  int y;

  int nbPionsMax; //= Jeu::nbJoueursTotal * (Jeu::nbPionsParJoueur -1) +1 (dès qu'un joueur a mis tous ses pions la partie se termine)
  int nbPions;
  forward_list<Pion> listePions;
  //Pion* tableauPions; // Tableau de pointeurs de Pion
  int* tableauIdJoueurs; // (length = Jeu::nbJoueursTotal + 1 : [0] = nbJoueursTotal : pour que J1 commence a l'indice 1)

  //protected:

  friend ostream& operator<<(ostream&, Case&);
};

#endif //CASE_HPP
