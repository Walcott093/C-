#ifndef CARTAGENA_HPP
#define CARTAGENA_HPP

#include "../../architectureGenerique/Jeu.hpp"
#include "../../architectureGenerique/Joueur.hpp"
#include "../../architectureGenerique/Constantes.hpp"
using namespace std;

class Cartagena : public Jeu {
protected:
  Joueur* creationJoueur();

public:
  Cartagena(string, int, int, int); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur
  Cartagena(string, int, int, int, Joueur**); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur, tableauJoueurs
  virtual ~Cartagena();

};

#endif //CARTAGENA_HPP
