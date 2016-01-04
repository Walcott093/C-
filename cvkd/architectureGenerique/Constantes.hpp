#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP
#include <iostream>
using namespace std;

/********** DEBUT : LISTE ET NOM DES JEUX  **********/
// Used in "main.cpp"
const string LISTE_DES_JEUX = "1. Serpent-Echelle \n2. Serpent-Echelle (variante cases bonus/malus) \n3. Serpent-Echelle (variante pedagogique) \n4. Serpent-Echelle (variante a plusieurs pions) \n5. Cartagena (variante) \n6. Numeri";
const string ECHELLE_SERPENT = "EchelleSerpent";
const string ECHELLE_SERPENT_ORANGE_VERTE = "EchelleSerpentOrangeVerte";
const string ECHELLE_SERPENT_PEDAGOGIQUE = "EchelleSerpentPedagogique";
const string ECHELLE_SERPENT_PLUSIEURS_PIONS = "EchelleSerpentPlusieursPions";
const string CARTAGENA = "Cartagena";
const string NUMERI = "Numeri";
/********** FIN : LISTE ET NOM DES JEUX  **********/




/********** DEBUT : PARAMETRE DE JEU  **********/
// Used in "main.cpp", "Case.hpp", "Case.cpp"
const int NB_JOUEURS_MAX = 4;

// Used in "Plateau.cpp"
const int DELAY = 2;
/********** FIN : PARAMETRE DE JEU  **********/




/********** DEBUT : ECHELLE_SERPENT CONSTANTES POUR LES VARIANTES  **********/
// Used in "../jeux/EchelleSerpent/CaseEchelleSerpent.hpp"
const int NB_SPECIFICITES_ES = 2; // Echelle + Serpent
const int NB_SPECIFICITES_ESOV = 4; // Echelle + Serpent + Orange + Verte
const int NEUTRE = 0;
const int ECHELLE = 1;
const int SERPENT = 2;
/*const int ECHELLE_BAS = 1;
const int ECHELLE_HAUT = 2;
const int SERPENT_QUEUE = 3;
const int SERPENT_TETE = 4;*/

const int ORANGE = 3;
const int VERTE = 4;


// Used in "../jeux/EchelleSerpent/ObjetEchelleSerpent.hpp"
const string TYPE_ECHELLE_BAS = "TypeEchelleBas";
const string TYPE_ECHELLE_HAUT = "TypeEchelleHaut";
const string TYPE_SERPENT_QUEUE = "TypeSerpentQueue";
const string TYPE_SERPENT_TETE = "TypeSerpentTete";
/********** DEBUT : ECHELLE_SERPENT CONSTANTES POUR LES VARIANTES  **********/




/********** DEBUT : OPTIONS DISPENSABLES DE JEU  **********/
// Used in "Jeu.cpp" pour la creation des pions lors de la creation des joueurs
const string NOIR = "30";
const string ROUGE = "31";
const string VERT = "32";
const string JAUNE = "33";
const string BLEU = "34";
const string MAGENTA = "35";
const string CYAN = "36";
const string BLANC = "37";

const string COULEUR_1 = "31"; // ROUGE
const string COULEUR_2 = "34"; // BLEU
const string COULEUR_3 = "32"; // VERT
const string COULEUR_4 = "33"; // JAUNE
const string COULEUR_5 = "35"; // MAGENTA
const string COULEUR_6 = "36"; // CYAN
const string COULEUR_7 = "37"; // BLANC
const string COULEUR_8 = "30"; // NOIR

// Used in "Joueur.hpp" pour les noms des robots
const string NOM_1 = "Picasso";
const string NOM_2 = "Saitama";
const string NOM_3 = "KitKat";
const string NOM_4 = "Malabar";
const string NOM_DEFAULT = "M&M's";
/********** FIN : OPTIONS DISPENSABLES DE JEU  **********/

#endif //CONSTANTES_HPP
