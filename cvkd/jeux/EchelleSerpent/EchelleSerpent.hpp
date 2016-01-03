#ifndef ECHELLE_SERPENT_HPP
#define ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Jeu.hpp"
using namespace std;

class EchelleSerpent : public Jeu {
protected:
  bool finDePartie(Plateau);
  int deplacementPion(Plateau, Pion);

public:
  EchelleSerpent(string, int, int, int, int, int, int, int, int, int); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur, taillePlateauLignes, taillePlateauColonnes, nbCasesEchelles, nbCasesSerpents, nbCasesOranges, nbCasesVertes
  EchelleSerpent(string, int, int, int, Joueur**, int, int, int, int, int, int); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur, tableauJoueurs, taillePlateauLignes, taillePlateauColonnes, nbCasesEchelles, nbCasesSerpents, nbCasesOranges, nbCasesVertes
  virtual ~EchelleSerpent();

  int getTaillePlateauLignes();
  int getTaillePlateauColonnes();
  int getNbCasesEchelles();
  int getNbCasesSerpents();
  int getNbCasesOranges();
  int getNbCasesVertes();
  void setTaillePlateauLignes(int);
  void setTaillePlateauColonnes(int);
  void setNbCasesEchelles(int);
  void setNbCasesSerpents(int);
  void setNbCasesOranges(int);
  void setNbCasesVertes(int);

private:
  int taillePlateauLignes; // Sert a calculer les probabilites d'avoir une case neutre et non-neutre
  int taillePlateauColonnes; // Sert a calculer les probabilites d'avoir une case neutre et non-neutre
  int nbCasesEchelles;
  int nbCasesSerpents;
  int nbCasesOranges;
  int nbCasesVertes;

};

#endif //ECHELLE_SERPENT_HPP
