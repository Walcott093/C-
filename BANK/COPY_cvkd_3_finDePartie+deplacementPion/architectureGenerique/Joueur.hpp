#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Pion.hpp"
using namespace std;

class Joueur {
public:
  Joueur();
  Joueur(int, string, int, int, Pion**); // idJoueur, nom, score, nbPions, tabPions
  virtual ~Joueur();

  int getIdJoueur();
  string getNom();
  int getScore();
  int getNbPions();
  Pion** getTabPions();

  void setIdJoueur(int);
  void setNom(string);
  void setScore(int);
  void setNbPions(int);
  void setTabPions(Pion**);

  friend ostream& operator<<(ostream&, Joueur&);

private:
  int idJoueur;
  string nom;
  int score;
  int nbPions;
  Pion** tabPions; // Pion** car l'ordre importe, et l'acces est plus facile

};

#endif //JOUEUR_HPP
