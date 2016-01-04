#include <iostream>
#include "Constantes.hpp"
#include "Jeu.hpp" // Il faudra surement ajouter le jeu en question (ex: Numeri.hpp)
#include "Plateau.hpp"

using namespace std;



/* ??CREER UNE FONCTION DE PARAMETRAGE POUR ALLEGER LE MAIN (cette fonction reprend toutes les entrees clavier (cin))
** PUIS INSTANCIER LES OBJETS DANS LE MAIN */

/* ??OU CREER UNE FONCTION DE PARAMETRAGE ET INSTANCIER DIRECTEMENT LES OBJETS DEDANS A L'AIDE DE REFERENCES (qui seront donnees par le main) */


int main() {
  int choixJeu, nbJoueursHumains, nbJoueursDisponibles, nbJoueursRobots, nbJoueursTotal, nbPionsParJoueur, nbLignesPlateau, nbColonnesPlateau, nbBonus, nbMalus, difficultePedagogique;

  Jeu* jeu;
  



  /****** DEBUT : CHOIX DU JEU  ******/
  cout << "Choix du jeu :\n" << LISTE_DES_JEUX << endl;
  cin >> choixJeu;
  cin.clear(); // A securiser encore plus si time
  /****** FIN : CHOIX DU JEU  ******/




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
    cout << "Il y a " << nbJoueursTotal << " joueurs (" << nbJoueursHumains << " humains et " << nbJoueursRobots << " robots)" << endl;
    break;
  default:
    cout << "[main.cpp] : Erreur sur le nombre de joueurs" << endl;
    exit(EXIT_FAILURE);
  }
  /****** FIN : CHOIX DU NOMBRE DE JOUEURS ROBOTS  ******/




  /****** DEBUT : CHOIX DE LA TAILLE DU PLATEAU (NOMBRE DE LIGNES) ******/
  do {
    nbLignesPlateau = 0;
    cout << "Taille du plateau > nombre de lignes (entre 4 et 10) :" << endl;
    cin >> nbLignesPlateau;
    cin.clear(); // A securiser encore plus si time
  } while(nbLignesPlateau < 4 || 10 < nbLignesPlateau);
  /****** FIN : CHOIX DE LA TAILLE DU PLATEAU (NOMBRE DE LIGNES) ******/




  /****** DEBUT : CHOIX DE LA TAILLE DU PLATEAU (NOMBRE DE COLONNES) ******/
  do {
    nbColonnesPlateau = 0;
    cout << "Taille du plateau > nombre de colonnes (entre 4 et 10) :" << endl;
    cin >> nbColonnesPlateau;
    cin.clear(); // A securiser encore plus si time
  } while(nbColonnesPlateau < 4 || 10 < nbColonnesPlateau);
  /****** FIN : CHOIX DE LA TAILLE DU PLATEAU (NOMBRE DE COLONNES) ******/




  /****** DEBUT : CREATION DU JEU  ******/
  switch(choixJeu) {
  case 1:
    //jeu = new EchelleSerpent(ECHELLE_SERPENT, nbJoueursHumains, nbJoueursTotal, 1, nbLignesPlateau, nbColonnesPlateau); // Standard
    break;
  case 2:
    //jeu = new EchelleSerpent(ECHELLE_SERPENT_ORANGE_VERTE, nbJoueursHumains, nbJoueursTotal, 1, nbLignesPlateau, nbColonnesPlateau); // OrangeVerte
    break;
  case 3:
    //jeu = new EchelleSerpent(ECHELLE_SERPENT_PEDAGOGIQUE, nbJoueursHumains, nbJoueursTotal, 1, nbLignesPlateau, nbColonnesPlateau); // Pedagogique
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

    //jeu = new EchelleSerpent(ECHELLE_SERPENT_PLUSIEURS_PIONS, nbJoueursHumains, nbJoueursTotal, nbPionsParJoueur, nbLignesPlateau, nbColonnesPlateau); // PlusieursPions



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
