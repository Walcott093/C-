#ifndef CASE_NORMALE_HPP
#define CASE_NORMALE_HPP

#include "Case.hpp"

class CaseNormale : public Case {
protected:
  int randomSpecificite();

public:
  CaseNormale(int, int, int); //(position, nbPionsMax, nbPions)
  CaseNormale(int, int, int, forward_list<Pion>); //(position, nbPionsMax, nbPions, listePions)
  // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  virtual ~CaseNormale();
  
};

#endif //CASE_NORMALE_HPP
