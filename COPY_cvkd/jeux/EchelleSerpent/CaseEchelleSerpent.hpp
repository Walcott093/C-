#ifndef CASE_ECHELLE_SERPENT_HPP
#define CASE_ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Constantes.hpp"
#include "../../architectureGenerique/Case.hpp"
#include "EchelleSerpent.hpp"
using namespace std;

class CaseEchelleSerpent : public Case {
protected:
  virtual int randomSpecificite();


public:
  CaseEchelleSerpent(int, int, int, int, EchelleSerpent); // abs, ord, nbPionsMax, nbPions, jeuVariante
  CaseEchelleSerpent(int, int, int, int, forward_list<Pion>, int*, EchelleSerpent); // abs, ord, nbPionsMax, nbPions, listePions, tableauIdJoueurs, jeuVariante
  // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  virtual ~CaseEchelleSerpent();

  EchelleSerpent getJeuVariante();
  int getSpecificiteCase();
  int getNbCases();
  int getNbCasesNonNeutres();
  void setJeuVariante(EchelleSerpent);
  void setSpecificiteCase(int);
  void setNbCases(int);
  void setNbCasesNonNeutres(int);
  
private:
  EchelleSerpent jeuVariante;
  int specificiteCase;

  /*** DEBUT : Sert a la repartition des cases par probabilite ***/
  static int nbCases;
  static int nbCasesNonNeutres;
  /*** FIN : Sert a la repartition des cases par probabilite ***/


  //bool variantePedagogique;
  //bool variantePlusieursPions;

  /*
  const int NB_SPECIFICITES_ES = 2; // Neutre + Echelle + Serpent
  const int NB_SPECIFICITES_ESOV = 4; // Neutre + Echelle + Serpent + Orange + Verte
  const int NEUTRE = 0;
  const int ECHELLE = 1;
  const int SERPENT = 2;

  const int ORANGE = 3;
  const int VERTE = 4;
  */

};

#endif //CASE_ECHELLE_SERPENT_HPP
