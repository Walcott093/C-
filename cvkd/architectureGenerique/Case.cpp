#include <iostream>
#include <forward_list>
#include "Constantes.hpp"
#include "Case.hpp"
using namespace std;



Case::Case() {
  cout << "                              Creation d'une Case par defaut" << endl;
}
Case::~Case() {
  cout << "                              Destruction de la Case : " << *this << endl;
}


Case::Case(int abs, int ord, int nbMax, int nb):
  x(abs), y(ord), nbPionsMax(nbMax), nbPions(nb) {

  /*
  tableauIdJoueurs = new int[NB_JOUEURS_MAX +1];
  tableauIdJoueurs[0] = 0;
  */

  // forward_list par defaut vide
  //tableauPions = new Pion[nbMax];

  cout << "                              Construction de la case : " << *this << endl;
}

Case::Case(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions):
  x(abs), y(ord), nbPionsMax(nbMax), nbPions(nb), listePions(pions) {
  cout << "                              Construction de la case : " << *this <<endl;
}
/*
Case::Case(int abs, int ord, int nbMax, int nb, forward_list<Pion> pions, int* tabId):
  x(abs), y(ord), nbPionsMax(nbMax), nbPions(nb), listePions(pions), tableauIdJoueurs(tabId) {
  cout << "                              Construction de la case : " << *this <<endl;
}
*/




bool Case::isEmpty() { return nbPions == 0; }

bool Case::ajouterPion(Pion p) {
  if(nbPions < nbPionsMax) {
    listePions.push_front(p);
    nbPions++;
    //tableauPions[nbPions++] = p;
  }
  else {
    cout << "[Case.cpp/ajouterPion] Erreur : Impossible de rajouter le pion. Case remplie." << endl;
    return false;
  }
  return true;
}

bool Case::ajouterPions(forward_list<Pion> fl, int nbPionsToAdd) {
  if(nbPions + nbPionsToAdd > nbPionsMax) {
    cout << "[Case.cpp/ajouterPions] Erreur : Impossible de rajouter les pions. Pas assez de place." << endl;
    return false;
  }
  else {
    listePions.splice_after(listePions.before_begin(), fl);
    nbPions += nbPionsToAdd;
    
    //for(int i=0 ; i<nb ; i++)
    //ret = ajouterPion(t[i]);
    return true;
  }
}

bool Case::retirerPion(Pion p) {
  if(nbPions == 0) {
    cout << "[Case.cpp/retirerPion] Erreur : Impossible de retirer le pion. Case vide." << endl;
    return false;
  }
  else {
    for(auto it=listePions.begin() ; it!=listePions.end(); ++it) {
      //Pion pion(*it);
      
      if(*it == p) {
	listePions.remove(p);
	nbPions--;
	//cout << "Pion supprime: " << p << endl;
	return true;
      }
      
    }
    cout << "[Case.cpp/retirerPion] Erreur : Impossible de retirer le pion. Il n'est pas present." << endl;
    return false;
  }
}

bool Case::retirerPions(forward_list<Pion> fl, int nbPionsToDel) {
  bool all_deleted = true;
  if(nbPions - nbPionsToDel < 0) {
    cout << "[Case.cpp/retirerPions] Erreur : Impossible de retirer les pions. Pas assez de pions." << endl;
    return false;
  }
  else {
    for(auto it=fl.begin() ; it!=fl.end(); ++it) {
      //cout << "RETIRER PIONS ON PASSE : " << *it << endl;
      if(!retirerPion(*it)) {
	cout << "[Case.cpp/retirerPions] Erreur : Impossible de retirer le pion. Il n'est pas present." << endl;
	all_deleted = false;
      }
    }
  }
  return all_deleted;
}

int Case::getX() { return x; }
int Case::getY() { return y; }
int Case::getNbPionsMax() { return nbPionsMax; }
int Case::getNbPions() { return nbPions; }
//int* Case::getTableauIdJoueurs() { return tableauIdJoueurs; }
forward_list<Pion> Case::getListePions() { return listePions; }
//Pion* Case::getTableauPions() { return tableauPions; }

void Case::setX(int new_x) { x = new_x; }
void Case::setY(int new_y) { y = new_y; }
void Case::setNbPionsMax(int a) { nbPionsMax = a; }
void Case::setNbPions(int a) { nbPions = a; }
//void Case::setTableauIdJoueurs(int* a) { tableauIdJoueurs = a; }
void Case::setListePions(forward_list<Pion> fl) { listePions = fl; }
//void Case::setTableauPions(Pion* a) { tableauPions = a; }

ostream& operator<<(ostream& o, Case& c) {
  //o << "\n";
  o << "<CASE: (" << c.x << ", " << c.y << "), "
    << "nbPions=" << c.nbPions << ", "
    << "nbPionsMax=" << c.nbPionsMax << ", ";
    /*
    << "tableauIdJoueurs=[";

  for(int i=1 ; i<c.tableauIdJoueurs[0]; i++)
    o << c.tableauIdJoueurs[i] << ", ";
  if(c.tableauIdJoueurs[0] != 0)
    o << c.tableauIdJoueurs[c.tableauIdJoueurs[0]] << "], ";
  else
    o << "], ";
    */

  o << "listePions=[";
  switch(c.nbPions) {
  case 0:
    o << "]>";
    break;
  case 1:
    o << "\n  " << *c.listePions.begin() << "]>";
    break;
  default:
    int cpt = 0;
    for(auto it=c.listePions.begin() ; it!=c.listePions.end(); ++it) {
      if(cpt++ == c.nbPions -1)
	o << "\n  " << *it << "]>";
      else 
	o << "\n  " << *it << ",";
    }
    break;
  }

  /*
  o << "tableauPions=[";
  for(int i=0 ; i<=c.nbPions -2 ; i++)
    o << "\n  " << c.tableauPions[i] << ",\n  ";
  if(c.nbPions != 0)
    if(c.nbPions == 1)
      o << "\n  " << c.tableauPions[c.nbPions -1] << "]>";
    else
      o << c.tableauPions[c.nbPions -1] << "]>";
  else
    o << "]>";
*/


  return o;
}
