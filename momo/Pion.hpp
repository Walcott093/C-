#ifndef PION
#define PION
#include <iostream>
using namespace std;

class Pion {
public:
  Pion();
  Pion(string,string,int,int);
  virtual ~Pion();

  string getNom();
  void setNom(string);
  
  string getCouleur();
  void setCouleur(string);
  
  int getX();
  void setX(int);
  int getY();
  void setY(int);
private:
  string nom; //identifier le pion si il y en a plusieurs par joueur
  string couleur; //identifie la couleur du pion
  int x,y;
  friend ostream& operator<<(ostream&,Pion&);
};
#endif //PION
