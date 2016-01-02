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

const int NB_SPECIFICITES_ES = 3; // Neutre + Echelle + Serpent
const int NB_SPECIFICITES_ESOV = 5; // Neutre + Echelle + Serpent + Orange + Verte
const int NEUTRE = 0;
const int ECHELLE = 1;
const int SERPENT = 2;

const int ORANGE = 3;
const int VERTE = 4;

/********** DEBUT : ECHELLE_SERPENT CONSTANTES POUR LES VARIANTES  **********/

#endif //CONSTANTES_HPP
