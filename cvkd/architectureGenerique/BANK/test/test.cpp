#include <iostream>
#include <forward_list>
/*
#include "Constantes.hpp"
#include "Pion.hpp"
#include "Case.hpp"
#include "Joueur.hpp"
#include "CaseNormale.hpp"
#include "../jeux/EchelleSerpent/CaseEchelleSerpent.hpp"
//#include "Plateau.hpp"
*/
#include "A.hpp"
#include "B.hpp"
#include <thread>
#include <chrono>
using namespace std;

/*static int idJoueur = 0;
static int joueursHumainsCrees = 0;
static int joueursRobotsCrees = 0;
static int nbJoueursHumains = 2;
static int nbJoueursTotal = 4;
static int nbPionsParJoueur = 4;*/

//Joueur* creationJoueur();



void affichage(int* p, int nbCases, int nbLignes, int nbColonnes){
  int cptLignes = nbLignes; //int cptLignes = p.getNbLignes();
  int cptColonnes = nbColonnes; //int cptColonnes = p.getNbColonnes(); //= 1;
  for(int i=nbCases ; i>=1 ; i-=nbColonnes) {
    cout << "|";
    if(cptLignes % 2 == 1) { // Si ligne impaire : sensPion = g->d ; sensAffichage = d->g
      for(int c=nbColonnes-1 ; c>=0 ; c--)//for(int c=p.getNbColonnes()-1 ; c>=0 ; c--)
	cout << p[i -c -1] << "|"; //o << p.plateau[i -c] << "|";
      cout << endl;
      cptLignes--;
    }
    else { // Si ligne paire : sensPion = d->g ; sensAffichage = g->d
      for(int c=0 ; c<=nbColonnes-1 ; c++) { //for(int c=0 ; c<=p.getNbColonnes()-1 ; c++) {
	cout << p[i -c -1] << "|"; //o << p.plateau[i -c] << "|";
      }
      cout << endl;
      cptLignes--;
    }
  }


}
int main() {
  cout << "Hello !" << endl;
  int delay;
  cin >> delay;

  this_thread::sleep_for(chrono::seconds(delay));

  cout << "Delayed Ack" << endl;

  /*
  A* a = new A();
  B* b = new B();

  cout << "test" << endl;
  //B* b0 = new A();
  A* a0 = new B();
  cout << "a0.getA()=" << a0->getA() << endl;
  cout << "a0.getB()=" << a0->b << endl;
  */



  /*
  int nbCases;
  cin >> nbCases;
  int position;
  cin >> position;

    srand(time(nullptr));
    int de = (rand() % 6) +1;
    
    int new_position = 0;
    if(position + de >= nbCases -1)
      new_position = nbCases -1;
    else
      new_position = position + de;

    cout << "position : " << position << endl;
    cout << "de : " << de << endl;
    cout << "new_position : " << new_position << endl;
  */



  /*
  int p[5];
  for(int i=0 ; i<5 ; i++)
    cout << "p[" << i << "] = " << p[i] << endl;
  */


  /*
  int p[50];
  for(int i=0 ; i<50 ; i++)
    p[i] = i;
  
  affichage(p, 12, 3, 4);
  cout << endl;
  affichage(p, 12, 4, 3);
  cout << endl;
  affichage(p, 25, 5, 5);
  cout << endl;
  affichage(p, 49, 7, 7);
  cout << endl;
  affichage(p, 36, 6, 6);
  */

  /*
  Joueur** tableauJoueurs = new Joueur*[nbJoueursTotal];
  for(int i=0 ; i<nbJoueursTotal ; i++) {
    tableauJoueurs[i] = creationJoueur();
  }

  for(int i=0 ; i<nbJoueursTotal ; i++)
    cout << "Joueur[" << i << "] =\n" << *tableauJoueurs[i] << endl;
  */






  /*
  int idPion = 0;
  Pion** tab = new Pion*[5];
  
  for(int i=0; i<5 ; i++) {
    //Pion p(0, idPion++, "BLEU", 0, 0);
    //tab[i] = &p;
    tab[i] = new Pion(0, idPion++, "BLEU", 0, 0);
    cout << "tab[i] = " << *tab[i] << endl;
  }
  
  for(int i=0 ; i<5 ; i++) {
    cout << "tab[" << i << "] = " << *tab[i] << endl;
  }
*/

  
  /*
  Pion p1(1, 1, "bleu", 0, 0);
  cout << "p1= \n" << p1 << endl;
  
  Pion p2(4, 2, "violet", 6, 7);
  cout << "p2= \n" << p2 << endl;

  Pion p3(1, 2, "rose", 1, 1);
  cout << "p3= \n" << p3 << endl;
  */
  


  /*
  int nbCases, nbCasesNonNeutres;
  cout << "(nbCases, nbCasesNonNeutres) : " << endl;
  cin >> nbCases;
  cin >> nbCasesNonNeutres;
  int ret = 0;
  int x = 0;
  string nomVariante = "";
  cout << "nomVariante = " << endl;
  cin >> nomVariante;
  srand(time(nullptr));

  do {
    if(nomVariante == ECHELLE_SERPENT
       || nomVariante == ECHELLE_SERPENT_PEDAGOGIQUE
       || nomVariante == ECHELLE_SERPENT_PLUSIEURS_PIONS) {
      x = (rand() % nbCases--) +1;
      if(1 <= x && x <= nbCasesNonNeutres) {  
	ret = (rand() % NB_SPECIFICITES_ES) +1; // 1 (ECHELLE) ou 2 (SERPENT)
	nbCasesNonNeutres--;
      }
      else
	ret = NEUTRE; // 0
    }
    else if(nomVariante == ECHELLE_SERPENT_ORANGE_VERTE) {
      x = (rand() % nbCases--) +1;
      if(1 <= x && x <= nbCasesNonNeutres) {  
	ret = (rand() % NB_SPECIFICITES_ESOV) +1; // 1 (ECHELLE) ou 2 (SERPENT) ou 3 (ORANGE) ou 4 (VERTE)
	nbCasesNonNeutres--;
      }
      else
	ret = NEUTRE; // 0
    }
    else
      cout << "[CaseEchelleSerpent.cpp] Erreur : Nom de variante non reconnu" << endl;

    cout << "ret = " << ret << endl;
  } while(nbCases > 0);
*/





  /*
  int nbLignesPlateau, nbColonnesPlateau;

  do {
    nbLignesPlateau = 0;
    cout << "Taille du plateau > nombre de lignes (entre 4 et 10) :" << endl;
    cin >> nbLignesPlateau;
    cin.clear(); // A securiser encore plus si time
  } while(nbLignesPlateau < 4 || 10 < nbLignesPlateau);
 
  do {
    nbColonnesPlateau = 0;
    cout << "Taille du plateau > nombre de colonnes (entre 4 et 10) :" << endl;
    cin >> nbColonnesPlateau;
    cin.clear(); // A securiser encore plus si time
  } while(nbColonnesPlateau < 4 || 10 < nbColonnesPlateau);
 
*/

  /*
  srand(time(nullptr));
  int ret = rand() % 3;
  cout << "ret = " << ret << endl;
  ret = rand() % 3;
  cout << "ret = " << ret << endl;
  */

  /*
  int nbPionsParJoueur;
  do {
    nbPionsParJoueur = 0;
    cout << "Nombre de pions par joueur (de 2 à 4 max.) :" << endl;
    cin >> nbPionsParJoueur;
    cin.clear(); // A securiser encore plus si time
    cout << "nbPionsParJoueur = " << nbPionsParJoueur << endl;
  } while(nbPionsParJoueur < 2 || 4 < nbPionsParJoueur);
  */



  /*
  int i = 0;

  cin >> i;
  cout << "i = " << i << endl;

  if(i == 1)
    cout << "gg" << endl;
  else
    cout << "perdu" << endl;
  */



  /*
  cout << "LISTE_DES_JEUX = " << LISTE_DES_JEUX << endl;
  cout << "NB_SPECIFICITE_ES = " << NB_SPECIFICITES_ES << endl;
  */


  /*
  //Case c1(0, 0, 4, 0);
  //CaseNormale c1(0, 0, 4, 0);
  CaseEchelleSerpent c1(0, 0, 2, 0, true);
  cout << "c1= \n" << c1 << endl;
  cout << "c1.getVariante()= " << c1.getVariante() << endl;
  cout << "c1.getSpecificite()= " << c1.getSpecificite() << endl;
  
  Pion p1(1, 1, "bleu", 0, 0);
  cout << "p1= \n" << p1 << endl;
  
  Pion p2(4, 2, "violet", 6, 7);
  cout << "p2= \n" << p2 << endl;

  Pion p3(1, 2, "rose", 1, 1);
  cout << "p3= \n" << p3 << endl;

  cout << "ajouterPion(p1):" << endl;
  c1.ajouterPion(p1);
  cout << c1 << endl;

  cout << "ajouterPion(p2):" << endl;
  c1.ajouterPion(p2);
  cout << c1 << endl;
  
  cout << "ajouterPion(p3):" << endl;
  c1.ajouterPion(p3);
  cout << c1 << endl;

  
    cout << "retirerPion(p2):" << endl;
  c1.retirerPion(p2);
  cout << c1 << endl;
  cout << "retirerPion(p3):" << endl;
  c1.retirerPion(p3);
  cout << c1 << endl;
  /*
  forward_list<Pion> flp = {p1, p3};
  cout << "retirerPions(flp, 2):" << endl;
  c1.retirerPions(flp, 2);
  cout << c1 << endl;
  */





  /*
  forward_list<Pion> first;
  first.push_front(p1);

  for(auto it=first.begin() ; it!=first.end() ; ++it)
    cout << "1er aff - list: " << *it << endl;

  first.push_front(p2);
  
  for(auto it=first.begin() ; it!=first.end() ; ++it)
    cout << "2eme aff - list: " << *it << endl;

  for(auto it=first.begin() ; it!=first.end() ; ++it)
    cout << "3eme aff - list: " << (*it).getX() << endl;
  */



  /*
  string s1 = "he";
  string s2 = "ho";
  string s3 = "he";

  if(s1 == s3) cout << "gg" << endl;
  else cout << "lose" << endl;
  */



  /*  
  // g++ -std=c++11 -Wall -o test test.cpp
  forward_list<int> list;
  list.push_front(4);
  list.push_front(7);
  list.push_front(22);
  

  forward_list<int> second;
  second.push_front(2);
  second.push_front(3);
  
  for(auto it=list.begin() ; it!=list.end(); ++it)
    cout << *it << endl;
  
  list.remove(7);

  for(auto it=list.begin() ; it!=list.end(); ++it)
    cout << *it << endl;
  
  list.splice_after(list.before_begin(), second);

  for(auto it=list.begin() ; it!=list.end(); ++it)
    cout << *it << endl;

  cout << "test 1st ele list = " << *list.begin() << endl;
  */




  /*
  int i;
  cin >> i;
  switch(i) {
  case 0:
  case 1:
  case 2:
    cout << "i vaut " << i << endl;
    break;
  default:
    cout << "i perdu" << endl;
    break;
  }
*/
 
  return 0;
}






/*
Joueur* creationJoueur() {
  string nom;
  if(joueursHumainsCrees < nbJoueursHumains) {
    cout << "Entrez le nom du joueur :" << endl;
    cin >> nom;
    joueursHumainsCrees++;
  }
  else {
    switch(joueursRobotsCrees++) {
    case 0:
      nom = NOM_1;
      break;
    case 1:
      nom = NOM_2;
      break;
    case 2:
      nom = NOM_3;
      break;
    case 3:
      nom = NOM_4;
      break;
    default:
      nom = NOM_1;
      break;
    }
  }

  int score = 0;

  string couleur;
  if(idJoueur == 0) couleur = COULEUR_1;
  else if(idJoueur == 1) couleur = COULEUR_2;
  else if(idJoueur == 2) couleur = COULEUR_3;
  else couleur = COULEUR_4; // if(idJoueur == 3)
  idJoueur++;
  
  int idPion = 0;
  Pion** tab = new Pion*[nbPionsParJoueur];
  for(int i=0 ; i<nbPionsParJoueur ; i++) {
    tab[i] = new Pion(idJoueur, idPion++, couleur, 0, 0);
  }
  return new Joueur(idJoueur, nom, score, nbPionsParJoueur, tab);
}
*/
