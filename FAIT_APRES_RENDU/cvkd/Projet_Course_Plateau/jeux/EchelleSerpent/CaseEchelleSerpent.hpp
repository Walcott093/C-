#ifndef CASE_ECHELLE_SERPENT_HPP
#define CASE_ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Constantes.hpp"
#include "../../architectureGenerique/Case.hpp"
#include "EchelleSerpent.hpp"
#include "ObjetEchelleSerpent.hpp"
using namespace std;

class CaseEchelleSerpent : public Case {
public:
  CaseEchelleSerpent(int, int, int, EchelleSerpent*, int); // position, nbPionsMax, nbPions, jeuVariante, specificite 
  CaseEchelleSerpent(int, int, int, forward_list<Pion*>, ObjetEchelleSerpent*, EchelleSerpent*, int); // position, nbPionsMax, nbPions, listePions, obj, jeuVariante, specificite
  // Sert pour la premiere case ou se trouvent tous les pions au debut, ou pour modifier une case en cours de partie si un jeu le permet
  virtual ~CaseEchelleSerpent();

  int getSpecificite();
  EchelleSerpent* getJeuVariante();
  ObjetEchelleSerpent* getObj();

  void setSpecificite(int);
  void setJeuVariante(EchelleSerpent*);
  void setObj(ObjetEchelleSerpent*);

  friend ostream& operator<<(ostream&, CaseEchelleSerpent*&);
  
  int randomSpecificite();

private:
  EchelleSerpent* jeuVariante;
  int specificite;
  ObjetEchelleSerpent* obj;

};

#endif //CASE_ECHELLE_SERPENT_HPP
