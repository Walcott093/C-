#ifndef JEU_HPP
#define JEU_HPP

#include "Constantes.hpp"
#include "Plateau.hpp"
#include "Pion.hpp"
#include "Joueur.hpp"
using namespace std;

/***** CLASSE ABSTRAITE *****/

class Jeu {
protected:
  virtual bool finDePartie(Plateau) = 0; //On donne les conditions de fin de partie
  virtual int deplacementPion(Plateau, Pion) = 0; //Renvoie le nombre de case pour le deplacement du numero de pion donne en argument


public:
  Jeu();
  Jeu(string, int, int, int); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur
  Jeu(string, int, int, int, Joueur**); // nomJeuOuVariante, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur, tableauJoueurs
  virtual ~Jeu();

  Joueur* creationJoueur(); // VAUT-IL MIEUX RENVOYER UN JOUEUR OU UN JOUEUR* ???
  int getScoreJoueur(int); //Recuperer le score d'un joueur en donnant son id
  void getScores(); //Afficher les scores de tous les joueurs

  string getNomJeuOuVariante();
  int getNbJoueursHumains();
  int getNbJoueursTotal();
  int getNbPionsParJoueur();
  Joueur** getTableauJoueurs();

  void setNomJeuOuVariante(string);
  void setNbJoueursHumains(int);
  void setNbJoueursTotal(int);
  void setNbPionsParJoueur(int);
  void setTableauJoueurs(Joueur**);

  Joueur* operator[](int);
  

protected:
  string nomJeuOuVariante;
  int nbJoueursHumains; //Parametre donne par l'utilisateur
  int nbJoueursTotal; // (=humains + robots) //Parametre donne par l'utilisateur
  int nbPionsParJoueur;
  Joueur** tableauJoueurs;
  
};

#endif //JEU_HPP
