#ifndef ECHELLE_SERPENT
#define ECHELLE_SERPENT

class Echelle_Serpent {
public:
  Echelle_Serpent();
  Echelle_Serpent(int,int,int,int,bool,bool);
  virtual ~Echelle_Serpent();
  int getIhaut();
  int getJhaut();
  int getIbas();
  int getJbas();
  bool getIsEchelle();
  bool getIsSerpent();
  void setIhaut(int);
  void setJhaut(int);
  void setIbas(int);
  void setJbas(int);
  void setIsEchelle(bool);
  void setIsSerpent(bool);
private:
  int ihaut;
  int jhaut;
  int ibas;
  int jbas;
  bool isEchelle;
  bool isSerpent;
};
#endif //ECHELLE_SERPENT
