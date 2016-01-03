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
const string CARTAGENA_VARIANTE = "CartagenaVariante";
const string NUMERI = "Numeri";
/********** FIN : LISTE ET NOM DES JEUX  **********/



/********** DEBUT : PARAMETRE DE JEU  **********/
// Used in "main.cpp", "Case.hpp", "Case.cpp"

const int NB_JOUEURS_MAX = 4;
/********** FIN : PARAMETRE DE JEU  **********/



/********** DEBUT : ECHELLE_SERPENT CONSTANTES POUR LES VARIANTES  **********/
// Used in "../jeux/EchelleSerpent/CaseEchelleSerpent.hpp"

const int NB_SPECIFICITES_ES = 4; // Echelle + Serpent
const int NB_SPECIFICITES_ESOV = 6; // Echelle + Serpent + Orange + Verte
const int NEUTRE = 0;
const int ECHELLE_BAS = 1;
const int ECHELLE_HAUT = 2;
const int SERPENT_QUEUE = 3;
const int SERPENT_TETE = 4;

const int ORANGE = 5;
const int VERTE = 6;


// Used in "../jeux/EchelleSerpent/ObjetEchelleSerpent.hpp"

const string TYPE_ECHELLE = "TypeEchelle";
const string TYPE_SERPENT = "TypeSerpent";
/********** DEBUT : ECHELLE_SERPENT CONSTANTES POUR LES VARIANTES  **********/




/********** DEBUT : OPTIONS DISPENSABLES DE JEU  **********/
// Used in "Jeu.cpp" pour la creation des pions lors de la creation des joueurs

const string COULEUR_1 = "Rouge";
const string COULEUR_2 = "Bleu";
const string COULEUR_3 = "Vert";
const string COULEUR_4 = "Jaune";

// Used in "Joueur.hpp" pour les noms des robots

const string NOM_1 = "Picasso";
const string NOM_2 = "Saitama";
const string NOM_3 = "KitKat";
const string NOM_4 = "Malabar";
const string NOM_DEFAULT = "M&M's";
/********** FIN : OPTIONS DISPENSABLES DE JEU  **********/

#endif //CONSTANTES_HPP
