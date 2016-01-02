#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Pion.hpp"

/***** CLASSE ABSTRAITE *****/

class Jeu {
protected:
  virtual bool finDePartie(Plateau) = 0; //On donne les conditions de fin de partie
  virtual int deplacementPion(Plateau, Pion) = 0; //Renvoie le nombre de case pour le deplacement du numero de pion donne en argument


public:
  Jeu();
  Jeu(int, int, int); // nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur
  Jeu(int, int, int*, int); // nbJoueursHumains, nbJoueursTotal, tableauScoreJoueur, nbPionsParJoueur
  virtual ~Jeu();

  int getScoreJoueur(int); //Recuperer le score d'un joueur en donnant son id
  void getScores(); //Afficher les scores de tous les joueurs

  int getNbJoueursHumains();
  int getNbJoueursTotal();
  int* getTableauScoreJoueur();
  int getNbPionsParJoueur();
  void setNbJoueursHumains(int);
  void setNbJoueursTotal(int);
  void setTableauScoreJoueur(int*);
  void setNbPionsParJoueur(int);

  int operator[](int);
  

private:
  int nbJoueursHumains; //Parametre donne par l'utilisateur
  int nbJoueursTotal; // (=humains + robots) //Parametre donne par l'utilisateur
  int* tableauScoreJoueur; // (length = nbJoueursTotal + 1 : [0] = nbJoueursTotal : pour que J1 commence a l'indice 1)
  int nbPionsParJoueur;
  
};

#endif //JEU_HPP
