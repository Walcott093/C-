#ifndef ECHELLE_SERPENT_HPP
#define ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Jeu.hpp"
using namespace std;

class EchelleSerpent : public Jeu {
protected:
  bool finDePartie(Plateau);
  int deplacementPion(Plateau, Pion);

public:
  EchelleSerpent(string, int, int, int); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur
  EchelleSerpent(string, int, int, int, int*); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur, tableauScoreJoueur
  virtual ~EchelleSerpent();


};

#endif //ECHELLE_SERPENT_HPP
