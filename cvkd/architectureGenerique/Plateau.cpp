#include <iostream>
#include "Plateau.hpp"
using namespace std;

// MODIFIER DE TELLE SORTE A METTRE BONUS ET MALUS
template <class T>
Plateau::Plateau(int x): nbLignes(x), nbColonnes(x), plateau(new T[x][x]) {
  cout << "Creation d'un Plateau de taille : " << x << endl;
}

template <class T>
Plateau::~Plateau() {
  cout << "Destruction d'un Plateau" << endl;
}


template <class T>
int Plateau::getNbLignes() { return nbLignes; }
template <class T>
int Plateau::getNbColonnes() { return nbColonnes; }
template
