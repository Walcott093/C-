#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Jeu.hpp"
#include "Case.hpp"
using namespace std;

/* template <int n, class T>  (template <int nbBonus, CaseEchelleSerpent>) */

//template <class T> // Contient le type de case
class Plateau {
public:
  Plateau(Jeu*, int, int); // jeu, nbLignes, nbColonnes
  //Plateau(Jeu*, int, int, Case**); // jeu, nbLignes, nbColonnes, plateau
  virtual ~Plateau();

  Jeu* getJeu();
  int getNbLignes();
  int getNbColonnes();
  //T** getPlateau();
  Case** getPlateau();
  void setJeu(Jeu*);
  void setNbLignes(int);
  void setNbColonnes(int);
  void setPlateau(Case**);

private:  
  Jeu* jeu;
  int nbLignes;
  int nbColonnes;

  //T** plateau; // + fonction initPlateau()
  Case** plateau; // en fonction abstract CA VA PLUTOT ETRE CA JE PENSE
  // EN UTLILISATN UN STRING POUR SAVOIR DE QUEL TYPE DE CASE IL S'AGIT

  //int nbCasesSpeciales;
  friend ostream& operator<<(ostream&, Plateau&);
  //Case* operator[](int, int);
  Case* operator[][](int, int);
};

#endif //PLATEAU_HPP
