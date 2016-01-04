#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"
#include "Constantes.hpp"
#include "../jeux/EchelleSerpent/CaseEchelleSerpent.hpp"
//#include "../jeux/CartagenaVariante/CaseCartagena.hpp"
//#include "../jeux/Numeri/CaseNumeri.hpp"

using namespace std;

/* template <int n, class T>  (template <int nbBonus, CaseEchelleSerpent>) */
//template <class T> // Contient le type de case
class Plateau {
public:
  Plateau(int, int, string, int, int); // nbLignes, nbColonnes, (nbCases: pase necessaire de donner en arg car = nbLignes*nbColonnes), plateauNomJeu, plateauNbPionsParJoueur, plateauNbJoueursTotal
  virtual ~Plateau();

  int getNbLignes();
  int getNbColonnes();
  int getNbCases();
  string getPlateauNomJeu();
  int getPlateauNbPionsParJoueur();
  int getPlateauNbJoueursTotal();
  Case* getPlateau();
  /*
 _ _ _ _
|_|_|_|_|
|_|_|_|_|
|_|_|_|_|

  */
  void setNbLignes(int);
  void setNbColonnes(int);
  void setNbCases(int);
  void setPlateauNomJeu(string);
  void setPlateauNbPionsParJoueur(int);
  void setPlateauNbJoueursTotal(int);
  void setPlateau(Case*);

private:  
  int nbLignes;
  int nbColonnes;
  int nbCases;
  string plateauNomJeu;
  int plateauNbPionsParJoueur;
  int plateauNbJoueursTotal;

  Case* plateau;
   
  friend ostream& operator<<(ostream&, Plateau&);
  Case operator[](int);
  };

#endif //PLATEAU_HPP
