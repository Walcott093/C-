#ifndef CASE_ECHELLE_SERPENT_HPP
#define CASE_ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Constantes.hpp"
#include "../../architectureGenerique/Case.hpp"
#include "EchelleSerpent.hpp"
#include "ObjetEchelleSerpent.hpp"
using namespace std;

class CaseEchelleSerpent : public Case {
protected:
  virtual int randomSpecificite();


public:
  CaseEchelleSerpent(int, int, int, int, EchelleSerpent, bool); // abs, ord, nbPionsMax, nbPions, jeuVariante, isObjetEchelleSerpent
  CaseEchelleSerpent(int, int, int, int, forward_list<Pion>, EchelleSerpent, bool); // abs, ord, nbPionsMax, nbPions, listePions, jeuVariante, isObjetEchelleSerpent
  // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  //CaseEchelleSerpent(int, int, int, int, forward_list<Pion>, int*, EchelleSerpent, bool); // abs, ord, nbPionsMax, nbPions, listePions, tableauIdJoueurs, jeuVariante, isObjetEchelleSerpent
  // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  virtual ~CaseEchelleSerpent();

  EchelleSerpent getJeuVariante();
  bool getIsObjetEchelleSerpent();
  ObjetEchelleSerpent* getObj();
  int getSpecificiteCase();
  int getNbCases();
  int getNbCasesNonNeutres();
  bool getTeteQueue();

  void setJeuVariante(EchelleSerpent);
  void setIsObjetEchelleSerpent(bool);
  void setObj(ObjetEchelleSerpent*);
  void setSpecificiteCase(int);
  void setNbCases(int);
  void setNbCasesNonNeutres(int);
  void setTeteQueue(bool);
  
private:
  EchelleSerpent jeuVariante;
  int specificiteCase;

  bool isObjetEchelleSerpent;
  ObjetEchelleSerpent* obj;


  //bool variantePedagogique;
  //bool variantePlusieursPions;

  /*
  const int NB_SPECIFICITES_ES = 4; // Neutre + Echelle + Serpent
  const int NB_SPECIFICITES_ESOV = 6; // Neutre + Echelle + Serpent + Orange + Verte
  const int NEUTRE = 0;
  const int ECHELLE_BAS = 1;
  const int ECHELLE_HAUT = 2;
  const int SERPENT_QUEUE = 3;
  const int SERPENT_TETE = 4;

  const int ORANGE = 5;
  const int VERTE = 6;
  */

};

#endif //CASE_ECHELLE_SERPENT_HPP
