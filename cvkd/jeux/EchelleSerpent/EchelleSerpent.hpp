#ifndef ECHELLE_SERPENT_HPP
#define ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Jeu.hpp"

class EchelleSerpent : public Jeu {
protected:
  bool finDePartie(Plateau);
  int deplacementPion(Plateau, Pion);

public:
  EchelleSerpent(int, int); // nbJoueursHumains, nbJoueursTotal
  EchelleSerpent(int, int, int*); // nbJoueursHumains, nbJoueursTotal, tableauScoreJoueur
  virtual ~EchelleSerpent();
};

#endif //ECHELLE_SERPENT_HPP
