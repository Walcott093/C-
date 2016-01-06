#ifndef JOUEUR_CARTAGENA_HPP
#define JOUEUR_CARTAGENA_HPP

#include "../../architectureGenerique/Joueur.hpp"

template <int n>
class JoueurCartagena : public Joueur {
public:
  JoueurCartagena();
  JoueurCartagena(bool, int, string, int, int, Pion**, int*); // estHumain, idJoueur, nom, score, nbPions, tabPions
  virtual ~JoueurCartagena();

  int* getCartes();

  void setCartes(int*);

private:
  int cartes[n];
};

#endif //JOUEUR_CARTAGENA_HPP

#include <iostream>
using namespace std;




template <int n>
JoueurCartagena::JoueurCartagena(): Joueur() {
  cout << "Creation d'un JoueurCartagena par defaut" << endl;
}
template <int n>
JoueurCartagena::JoueurCartagena(bool estHumain, int idJoueur, string nom, int score, int nbPions, Pion** tab): Joueur(estHumain, idJoueur, nom, score, nbPions, tab) {
  int cartes = new int[n];
  for(int i=0 ; i<n ; i++)
    cartes[i] = 0;
  cout << "Creation d'un JoueurCartagena" << endl;
}

int* JoueurCartagena::getCartes() { return cartes; }
void JoueurCartagena::setCartes(int* tab) { cartes = tab; }
