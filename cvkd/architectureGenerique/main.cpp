#include <iostream>
#include "Constantes.hpp"
#include "Jeu.hpp" // Il faudra surement ajouter le jeu en question (ex: Numeri.hpp)
#include "Plateau.hpp"

using namespace std;



/* ??CREER UNE FONCTION DE PARAMETRAGE POUR ALLEGER LE MAIN (cette fonction reprend toutes les entrees clavier (cin))
** PUIS INSTANCIER LES OBJETS DANS LE MAIN */

/* ??OU CREER UNE FONCTION DE PARAMETRAGE ET INSTANCIER DIRECTEMENT LES OBJETS DEDANS A L'AIDE DE REFERENCES (qui seront donnees par le main) */


int main() {
  /*
  const int NB_JOUEURS_MAX = 4;
  const string LISTE_DES_JEUX = "1. Serpent-Echelle \n2. Serpent-Echelle (variante cases bonus/malus) \n3. Serpent-Echelle (variante pedagogique) \n4. Serpent-Echelle (variante a plusieurs pions) \n5. Cartagena (variante) \n6. Numeri";
  const string ECHELLE_SERPENT = "EchelleSerpent";
  const string ECHELLE_SERPENT_ORANGE_VERTE = "EchelleSerpentOrangeVerte";
  const string ECHELLE_SERPENT_PEDAGOGIQUE = "EchelleSerpentPedagogique";
  const string ECHELLE_SERPENT_PLUSIEURS_PIONS = "EchelleSerpentPlusieursPions";
  const string CARTAGENA_VARIANTE = "CartagenaVariante";
  const string NUMERI = "Numeri";
  */

  int choixJeu, nbJoueursHumains, nbJoueursDisponibles, nbJoueursRobots, nbJoueursTotal, nbPionsParJoueur, nbLignesPlateau, nbColonnesPlateau, nbBonus, nbMalus, difficultePedagogique;
  //int choixTypePlateau, plateauCarreTaille, 
  //char charCaseSpeciale;
  //bool boolCaseSpeciale; // Surtout utile pour le jeu Echelle-Serpent et pour l'addition de nouveaux jeux qui laisseraient le choix d'utilisation des cases speciales

  Jeu* jeu;
  



  /****** DEBUT : CHOIX DU NOMBRE DE JOUEURS ROBOTS  ******/
  cout << "Choix du jeu :\n" << LISTE_DES_JEUX << endl;
  cin >> choixJeu;
  cin.clear(); // A securiser encore plus si time
  /****** FIN : CHOIX DU NOMBRE DE JOUEURS ROBOTS  ******/




  /****** DEBUT : CHOIX DU NOMBRE DE JOUEURS HUMAINS  ******/

  cout << "Nombre de joueurs humains (4 max.) :" << endl;
  cin >> nbJoueursHumains;
  cin.clear(); // A securiser encore plus si time

  switch(nbJoueursHumains) {
  case 0:
    nbJoueursDisponibles = NB_JOUEURS_MAX - 0;
    break;
  case 1:
    nbJoueursDisponibles = NB_JOUEURS_MAX - 1;
    break;
  case 2:
    nbJoueursDisponibles = NB_JOUEURS_MAX - 2;
    break;
  case 3:
    nbJoueursDisponibles = NB_JOUEURS_MAX - 3;
    break;
  case 4:
    nbJoueursDisponibles = NB_JOUEURS_MAX - 4;
    break;
  default:
    cout << "[main.cpp] : Erreur sur le nombre de joueurs" << endl;
    exit(EXIT_FAILURE);
  }
  /****** FIN : CHOIX DU NOMBRE DE JOUEURS HUMAINS  ******/




  /****** DEBUT : CHOIX DU NOMBRE DE JOUEURS ROBOTS  ******/

  cout << "Nombre de joueurs robots (" << nbJoueursDisponibles << " disponible(s)) :" << endl;
  cin >> nbJoueursRobots;
  cin.clear(); // A securiser encore plus si time

  switch(nbJoueursRobots) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    nbJoueursTotal = nbJoueursHumains + nbJoueursRobots;
    break;
  default:
    cout << "[main.cpp] : Erreur sur le nombre de joueurs" << endl;
    exit(EXIT_FAILURE);
  }
  /****** FIN : CHOIX DU NOMBRE DE JOUEURS ROBOTS  ******/




  /****** DEBUT : CREATION DU JEU  ******/
  switch(choixJeu) {
  case 1:
    //jeu = new EchelleSerpent(ECHELLE_SERPENT, nbJoueursHumains, nbJoueursTotal, 1); // Standard
    break;
  case 2:
    //jeu = new EchelleSerpent(ECHELLE_SERPENT_ORANGE_VERTE, nbJoueursHumains, nbJoueursTotal, 1); // OrangeVerte
    break;
  case 3:
    //jeu = new EchelleSerpent(ECHELLE_SERPENT_PEDAGOGIQUE, nbJoueursHumains, nbJoueursTotal, 1); // Pedagogique
    break;
  case 4:
    /****** DEBUT : CHOIX DU NOMBRE DE PIONS PAR JOUEUR ******/
    do {
      nbPionsParJoueur = 0;
      cout << "Nombre de pions par joueur (de 2 à 4 max.) :" << endl;
      cin >> nbPionsParJoueur;
      cin.clear(); // A securiser encore plus si time
    } while(nbPionsParJoueur < 2 || 4 < nbPionsParJoueur);
    /****** FIN : CHOIX DU NOMBRE DE PIONS PAR JOUEUR ******/

    //jeu = new EchelleSerpent(ECHELLE_SERPENT_PLUSIEURS_PIONS, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur); // PlusieursPions
    break;
  case 5:
    //jeu = new CartagenaVariante(CARTAGENA_VARIANTE, nbJoueursHumains, nbJoueursTotal, ...);
    break;
  case 6:
    //jeu = new Numeri(NUMERI, nbJoueursHumains, nbJoueursTotal, ...);
    break;
  default:
    cout << "[main.cpp] : Erreur sur le choix du jeu" << endl;
    exit(EXIT_FAILURE);
  }
  /****** FIN : CREATION DU JEU  ******/




  /****** DEBUT : CREATION DU PLATEAU  ******/


  /****** FIN : CREATION DU PLATEAU  ******/






 



  return 0;
}







/*
  cout << "Utilisation des cases speciales ? y/n" << endl;
  cin >> charCaseSpeciale;
  cin.clear(); // A securiser encore plus si time

  switch(charCaseSpeciale) {
  case 'y':
    boolCaseSpeciale = true;
    break;
  case 'n':
    boolCaseSpeciale = false;
    break;
  default:
    cout << "Erreur sur la question des cases speciales" << endl;
    exit(EXIT_FAILURE);
  }
*/



 /*
  cout << "Type du plateau : 1. Carre  /  2. Rectangle" << endl;
  cin >> choixTypePlateau;
  cin.clear(); // A securiser encore plus si time

  switch(choixTypePlateau) {
  case 1:
    cout << "Taille du plateau (entre 3 et 10) : " << endl;
    cin >> plateauCarreTaille;
    cin.clear(); // A securiser encore plus si time

    break;
  case 2:
    cout << "Nombre de lignes du plateau (entre 3 et 10) : " << endl;
    cin >> plateauRectangleNbLignes;
    cin.clear(); // A securiser encore plus si time

    cout << "Nombre de colonnes du plateau (entre 3 et 10) : " << endl;
    cin >> plateauRectangleNbColonnes;
    cin.clear(); // A securiser encore plus si time

    break;
  default:
    cout << "Erreur sur le type du plateau" << endl;
    exit(EXIT_FAILURE);
  }
  */
