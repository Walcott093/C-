#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Pion.hpp"
using namespace std;

class Joueur {
public:
  Joueur();
  Joueur(int, string, int, int, Pion**); // id, nom, score, nbPions, tabPions
  virtual ~Joueur();

  int getId();
  string getNom();
  int getScore();
  int getNbPions();
  Pion** getTabPions();

  void setId(int);
  void setNom(string);
  void setScore(int);
  void setNbPions(int);
  void setTabPions(Pion**);

private:
  int id;
  string nom;
  int score;
  int nbPions;
  Pion** tabPions;

  friend ostream& operator<<(ostream&, Joueur&);
};

#endif //JOUEUR_HPP
