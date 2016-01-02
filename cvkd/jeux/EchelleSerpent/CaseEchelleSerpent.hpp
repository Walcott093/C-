#ifndef CASE_ECHELLE_SERPENT_HPP
#define CASE_ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Case.hpp"

class CaseEchelleSerpent : public Case {
protected:
  virtual int randomSpecificite();


public:
  CaseEchelleSerpent(int, int, int, int, bool); //(abs, ord, nbPionsMax, nbPions, varianteCaseOrangeVerte)
  CaseEchelleSerpent(int, int, int, int, forward_list<Pion>, int*, bool); //(abs, ord, nbPionsMax, nbPions, listePions, tableauIdJoueurs, varianteCaseOrangeVerte)
  // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  virtual ~CaseEchelleSerpent();

  bool getVariante();
  int getSpecificite();
  void setVariante(bool);
  void setSpecificite(int);

private:
  bool variante;
  int specificite;
  const int NB_SPECIFICITES_ES = 3; // Neutre + Echelle + Serpent
  const int NB_SPECIFICITES_ESOV = 5; // Neutre + Echelle + Serpent + Orange + Verte
  const int NEUTRE = 0;
  const int ECHELLE = 1;
  const int SERPENT = 2;

  const int ORANGE = 3;
  const int VERTE = 4;


};

#endif //CASE_ECHELLE_SERPENT_HPP
