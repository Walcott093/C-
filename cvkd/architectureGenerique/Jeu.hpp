#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Pion.hpp"
using namespace std;

/***** CLASSE ABSTRAITE *****/

class Jeu {
protected:
  virtual bool finDePartie(Plateau) = 0; //On donne les conditions de fin de partie
  virtual int deplacementPion(Plateau, Pion) = 0; //Renvoie le nombre de case pour le deplacement du numero de pion donne en argument


public:
  Jeu();
  Jeu(string, int, int, int); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur
  Jeu(string, int, int, int, int*); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur, tableauScoreJoueur
  virtual ~Jeu();

  int getScoreJoueur(int); //Recuperer le score d'un joueur en donnant son id
  void getScores(); //Afficher les scores de tous les joueurs

  string getNomJeuOuVariante();
  int getNbJoueursHumains();
  int getNbJoueursTotal();
  int getNbPionsParJoueur();
  int* getTableauScoreJoueur();
  void setNomJeuOuVariante(string);
  void setNbJoueursHumains(int);
  void setNbJoueursTotal(int);
  void setTableauScoreJoueur(int*);
  void setNbPionsParJoueur(int);

  int operator[](int);
  

private:
  string nomJeuOuVariante;
  int nbJoueursHumains; //Parametre donne par l'utilisateur
  int nbJoueursTotal; // (=humains + robots) //Parametre donne par l'utilisateur
  int* tableauScoreJoueur; // (length = nbJoueursTotal + 1 : [0] = nbJoueursTotal : pour que J1 commence a l'indice 1)
  int nbPionsParJoueur;
  
};

#endif //JEU_HPP
