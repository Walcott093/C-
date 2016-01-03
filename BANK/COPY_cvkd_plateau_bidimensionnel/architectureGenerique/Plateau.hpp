#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"
using namespace std;

/* template <int n, class T>  (template <int nbBonus, CaseEchelleSerpent>) */

//template <class T> // Contient le type de case
class Plateau {
public:
  Plateau(int, int, string, int, int); // nbLignes, nbColonnes, plateauNomJeu, plateauNbPionsParJoueur, plateauNbJoueursTotal
  //Plateau(Jeu*, int, int, Case**); // nbLignes, nbColonnes, plateau, plateauNomJeu, plateauNbPionsParJoueur, plateauNbJoueursTotal
  virtual ~Plateau();

  int getNbLignes();
  int getNbColonnes();
  string getPlateauNomJeu();
  int getPlateauNbPionsParJoueur();
  int getPlateauNbJoueursTotal();
  Case** getPlateau();

  void setNbLignes(int);
  void setNbColonnes(int);
  void setPlateauNomJeu(string);
  void setPlateauNbPionsParJoueur(int);
  void setPlateauNbJoueursTotal(int);
  void setPlateau(Case**);

private:  
  int nbLignes;
  int nbColonnes;
  string plateauNomJeu;
  int plateauNbPionsParJoueur;
  int plateauNbJoueursTotal;

  //T** plateau; // + fonction initPlateau()
  Case** plateau; // en fonction abstract CA VA PLUTOT ETRE CA JE PENSE
  // EN UTILISANT UN STRING POUR SAVOIR DE QUEL TYPE DE CASE IL S'AGIT

  //int nbCasesSpeciales;
  friend ostream& operator<<(ostream&, Plateau&);
  //Case* operator[](int, int);
  //Case* operator[][](int, int);
};

#endif //PLATEAU_HPP
