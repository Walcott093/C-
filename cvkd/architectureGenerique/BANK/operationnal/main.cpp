#include <iostream>
#include "Jeu.hpp" // Il faudra surement ajouter le jeu en question (ex: Numeri.hpp)
#include "Plateau.hpp"

using namespace std;



/* ??CREER UNE FONCTION DE PARAMETRAGE POUR ALLEGER LE MAIN (cette fonction reprend toutes les entrees clavier (cin))
** PUIS INSTANCIER LES OBJETS DANS LE MAIN */

/* ??OU CREER UNE FONCTION DE PARAMETRAGE ET INSTANCIER DIRECTEMENT LES OBJETS DEDANS A L'AIDE DE REFERENCES (qui seront donnees par le main) */


int main() {
  const int NB_JOUEURS_MAX = 4;
  const string LISTE_DES_JEUX = "1. Serpent-Echelle \n2. Serpent-Echelle (variante cases bonus/malus) \n3. Serpent-Echelle (variante pedagogique) \n4. Serpent-Echelle (variante a plusieurs pions) \n5. Cartagena (variante) \n6. Numeri";
  const int SERPENT_ECHELLE = 1;
  const int SERPENT_ECHELLE_BONUS_MALUS = 2;
  const int SERPENT_ECHELLE_PEDAGOGIQUE = 3;
  const int SERPENT_ECHELLE_PLUSIEURS_PIONS = 4;
  const int CARTAGENA_VARIANTE = 5;
  const int NUMERI = 6;

  int choixJeu, nbJoueursHumains, nbJoueursRobots, nbJoueursTotal, choixTypePlateau, plateauCarreTaille, plateauRectangleNbLignes, plateauRectangleNbColonnes, nbBonus, nbMalus, difficulte;
  char charCaseSpeciale;
  bool boolCaseSpeciale; // Surtout utile pour le jeu Echelle-Serpent et pour l'addition de nouveaux jeux qui laisseraient le choix d'utilisation des cases speciales


  Jeu jeu;
  


  cout << "Choix du jeu :\n" << LISTE_DES_JEUX << endl;
  cin >> choixJeu;
  cin.clear(); // A securiser encore plus si time

  switch(choixJeu) {
  case SERPENT_ECHELLE:
    //jeu = new SerpentEchelle(...);
    break;
  case SERPENT_ECHELLE_BONUS_MALUS:
    //jeu = new SerpentEchelleBonusMalus(...);
    break;
  case SERPENT_ECHELLE_PEDAGOGIQUE:
    //jeu = new SerpentEchellePedagogique(...);
    break;
  case SERPENT_ECHELLE_PLUSIEURS_PIONS:
    //jeu = new SerpentEchellePlusieursPions(...);
    break;
  case CARTAGENA_VARIANTE:
    //jeu = new CartagenaVariante(...);
    break;
  case NUMERI:
    //jeu = new Numeri(...);
    break;
  default:
    cout << "Erreur sur le choix du jeu" << endl;
    exit(EXIT_FAILURE);
  }
  




  cout << "Nombre de joueurs humains (4 max.) :" << endl;
  cin >> nbJoueursHumains;
  cin.clear(); // A securiser encore plus si time

  switch(nbJoueursHumains) {
  case 0:
    nbJoueursRobots = NB_JOUEURS_MAX - 0;
    break;
  case 1:
    nbJoueursRobots = NB_JOUEURS_MAX - 1;
    break;
  case 2:
    nbJoueursRobots = NB_JOUEURS_MAX - 2;
    break;
  case 3:
    nbJoueursRobots = NB_JOUEURS_MAX - 3;
    break;
  case 4:
    nbJoueursRobots = NB_JOUEURS_MAX - 4;
    break;
  default:
    cout << "Erreur sur le nombre de joueurs" << endl;
    exit(EXIT_FAILURE);
  }





  cout << "Nombre de joueurs total (" << nbJoueursRobots << " disponible(s)) :" << endl;
  cin >> nbJoueursTotal;
  cin.clear(); // A securiser encore plus si time
  





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

  return 0;
}
