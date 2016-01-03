#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Pion.hpp"
using namespace std;

class Joueur {
public:
  Joueur();
  Joueur(int, string, int, Pion*); // id, nom, score, tabPions
  virtual ~Joueur();

  int getId();
  string getNom();
  int getScore();
  Pion* getTabPions();

  void setId(int);
  void setNom(string);
  void setScore(int);
  void setTabPions(Pion*);

private:
  int id;
  string nom;
  int score;
  Pion* tabPions;


};

#endif //JOUEUR_HPP
