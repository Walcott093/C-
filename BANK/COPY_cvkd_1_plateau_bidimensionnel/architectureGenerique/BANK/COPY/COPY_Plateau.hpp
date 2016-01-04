#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"
using namespace std;

/* template <int n, class T>  (template <int nbBonus, CaseEchelleSerpent>) */

//template <class T> // Contient le type de case
class Plateau {
public:
  //Plateau(int); // Pour creer un plateau carre
  Plateau(int, int); // Pour creer un plateau rectangulaire
  virtual ~Plateau();

  int getNbLignes();
  int getNbColonnes();
  //T** getPlateau();
  Case** getPlateau();
  void setNbLignes(int);
  void setNbColonnes(int);
  void setPlateau(Case**);

private:  
  int nbLignes;
  int nbColonnes;
  string typeCase;

  //T** plateau; // + fonction initPlateau()
  Case** plateau; // en fonction abstract CA VA PLUTOT ETRE CA JE PENSE
  // EN UTLILISATN UN STRING POUR SAVOIR DE QUEL TYPE DE CASE IL S'AGIT

  //int nbCasesSpeciales;
  friend ostream& operator<<(ostream&, Plateau&);
  //Case* operator[](int, int);
  Case* operator[][](int, int);
};

#endif //PLATEAU_HPP
