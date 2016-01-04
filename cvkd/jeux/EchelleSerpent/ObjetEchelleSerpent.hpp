#ifndef OBJET_ECHELLE_SERPENT_HPP
#define OBJET_ECHELLE_SERPENT_HPP

#include "../../architectureGenerique/Case.hpp"
//#include "../../architectureGenerique/Constantes.hpp"
using namespace std;

class ObjetEchelleSerpent {
public:
  ObjetEchelleSerpent();
  ObjetEchelleSerpent(string, Case*, Case*); // type, tete, queue
  virtual ~ObjetEchelleSerpent();

  string getType();
  Case* getTete();
  Case* getQueue();

  void setType(string);
  void setTete(Case*);
  void setQueue(Case*);

private:
  string type; // TYPE_ECHELLE_BAS ou TYPE_ECHELLE_HAUT ou TYPE_SERPENT_QUEUE ou TYPE_SERPENT_TETE
  Case* tete;
  Case* queue;

};

#endif //OBJET_ECHELLE_SERPENT_HPP
