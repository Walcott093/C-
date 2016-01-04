#include <iostream>
#include "ObjetEchelleSerpent.hpp"
using namespace std;

/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
ObjetEchelleSerpent::ObjetEchelleSerpent():
  type(""), positionTete(0), positionQueue(0) {
  cout << "Creation d'un ObjetEchelleSerpent par defaut" << endl;
}

ObjetEchelleSerpent::ObjetEchelleSerpent(string s, int t, int q):
  type(s), positionTete(t), positionQueue(q) {
  cout << "Creation d'un ObjetEchelleSerpent" << endl;
}
ObjetEchelleSerpent::~ObjetEchelleSerpent() {
  cout << "Destruction d'un ObjetEchelleSerpent" << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
string ObjetEchelleSerpent::getType() { return type; }
int ObjetEchelleSerpent::getPositionTete() { return positionTete; }
int ObjetEchelleSerpent::getPositionQueue() { return positionQueue; }

void ObjetEchelleSerpent::setType(string s) { type = s; }
void ObjetEchelleSerpent::setPositionTete(int c) { positionTete = c; }
void ObjetEchelleSerpent::setPositionQueue(int c) { positionQueue = c; }
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
