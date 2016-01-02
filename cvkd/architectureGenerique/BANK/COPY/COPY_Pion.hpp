#ifndef PION_HPP
#define PION_HPP

//#include "Case.hpp"
using namespace std;

class Pion {
public:
  Pion();
  Pion(int, int, string);
  //Pion(int, int, string, Case);
  virtual ~Pion();
  
  int getIdJoueur();
  int getId();
  string getCouleur();
  //Case* getCase();
  
  void setIdJoueur(int);
  void setId(int);
  void setCouleur(string);
  //void setCase(Case*);
  
private:
  int idJoueur;
  int id;
  string couleur;
  //Case* case;
  
  friend ostream& operator<<(ostream&, Pion&);

};

#endif //PION_HPP
