#ifndef OBJET_ECHELLE_SERPENT_HPP
#define OBJET_ECHELLE_SERPENT_HPP

using namespace std;

class ObjetEchelleSerpent {
public:
  ObjetEchelleSerpent();
  ObjetEchelleSerpent(string, int, int); // type, positionTete, positionQueue
  virtual ~ObjetEchelleSerpent();

  string getType();
  int getPositionTete();
  int getPositionQueue();

  void setType(string);
  void setPositionTete(int);
  void setPositionQueue(int);

private:
  string type; // TYPE_ECHELLE_BAS ou TYPE_ECHELLE_HAUT ou TYPE_SERPENT_QUEUE ou TYPE_SERPENT_TETE
  int positionTete;
  int positionQueue;

};

#endif //OBJET_ECHELLE_SERPENT_HPP
