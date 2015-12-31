#ifndef JEU_HPP
#define JEU_HPP

/***** CLASSE ABSTRAITE *****/

class Jeu {
public:
  Jeu();
  virtual ~Jeu();

  int getScoreJoueur(int); //Recuperer le score d'un joueur en donnant son id
  void getScores(); //Afficher les scores de tous les joueurs

  int getNbJoueursHumains();
  int getNbJoueursTotal();
  int* getTableauScoreJoueur();
  void setNbJoueursHumains(int);
  void setNbJoueursTotal(int);
  void setTableauScoreJoueur(int*);
  
private:
  int nbJoueursHumains; //Parametre donne par l'utilisateur
  int nbJoueursTotal; // (=humains + robots) //Parametre donne par l'utilisateur
  int* tableauScoreJoueur; // (length = nbJoueursTotal + 1 : [0] = nbJoueursTotal : pour que J1 commence a l'indice 1)
  
protected:
  virtual bool finDePartie() = 0; //On donne les conditions de fin de partie
  virtual int nbCasesDeplacementPion(int) = 0; //Renvoie le nombre de case pour le deplacement du numero de pion donne en argument

};

#endif //JEU_HPP
