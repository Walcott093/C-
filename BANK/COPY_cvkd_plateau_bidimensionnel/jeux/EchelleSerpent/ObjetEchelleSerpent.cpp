#include <iostream>
#include "ObjetEchelleSerpent.hpp"
using namespace std;

ObjetEchelleSerpent::ObjetEchelleSerpent():
  type(""), tete(nullptr), queue(nullptr) {
  cout << "Creation d'un ObjetEchelleSerpent par defaut" << endl;
}

ObjetEchelleSerpent::ObjetEchelleSerpent(string s, Case* t, Case* q):
  type(s), tete(t), queue(q) {
  cout << "Creation d'un ObjetEchelleSerpent" << endl;
}
ObjetEchelleSerpent::~ObjetEchelleSerpent() {
  cout << "Destruction d'un ObjetEchelleSerpent" << endl;
}


string ObjetEchelleSerpent::getType() { return type; }
Case* ObjetEchelleSerpent::getTete() { return tete; }
Case* ObjetEchelleSerpent::getQueue() { return queue; }

void ObjetEchelleSerpent::setType(string s) { type = s; }
void ObjetEchelleSerpent::setTete(Case* c) { tete = c; }
void ObjetEchelleSerpent::setQueue(Case* c) { queue = c; }
