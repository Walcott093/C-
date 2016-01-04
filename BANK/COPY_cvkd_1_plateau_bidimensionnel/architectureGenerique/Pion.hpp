#ifndef PION_HPP
#define PION_HPP

//#include "Case.hpp"
using namespace std;

class Pion {
public:
  Pion();
  //Pion(int, int, string, Case);
  Pion(int, int, string, int, int);
  virtual ~Pion();
  
  int getIdJoueur();
  int getId();
  string getCouleur();
  //Case* getCase();
  int getX();
  int getY();
  
  void setIdJoueur(int);
  void setId(int);
  void setCouleur(string);
  //void setCase(Case*);
  void setX(int);
  void setY(int);

  bool operator==(const Pion&);
  
private:
  int idJoueur;
  int id;
  string couleur;
  //Case* case;
  int x;
  int y;
  
  friend ostream& operator<<(ostream&, Pion&);

};

#endif //PION_HPP
