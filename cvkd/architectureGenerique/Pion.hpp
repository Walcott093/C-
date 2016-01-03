#ifndef PION_HPP
#define PION_HPP

using namespace std;

class Pion {
public:
  Pion();
  Pion(int, int, string, int); //idJoueur, id, couleur, position
  virtual ~Pion();
  
  int getIdJoueur();
  int getId();
  string getCouleur();
  int getPosition();
  
  void setIdJoueur(int);
  void setId(int);
  void setCouleur(string);
  void setPosition(int);

  bool operator==(const Pion&);
  
private:
  int idJoueur;
  int id;
  string couleur;
  int position; // position sur le plateau (Case*)

  friend ostream& operator<<(ostream&, Pion&);

};

#endif //PION_HPP
