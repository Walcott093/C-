#include <iostream>
#include "Plateau.hpp"

using namespace std;


/********** DEBUT : CONSTRUCTEURS / DESTRUCTEURS **********/
Plateau::Plateau(Jeu* j, int rangeOrd, int rangeAbs):
  jeu(j), nbLignes(rangeOrd), nbColonnes(rangeAbs), nbCases(rangeOrd*rangeAbs), plateauNomJeu(j->getNomJeuOuVariante()), plateauNbPionsParJoueur(j->getNbPionsParJoueur()), plateauNbJoueursTotal(j->getNbJoueursTotal()) {

  
  if(plateauNomJeu == ECHELLE_SERPENT) {
    int nbPionsMax = plateauNbPionsParJoueur * plateauNbJoueursTotal;
    for(int i=0 ; i<nbCases ; i++)
      plateau[i] = new CaseEchelleSerpent(i, nbPionsMax, 0, ...);

  }

  /*
  else if(plateauNomJeu == ECHELLE_SERPENT_ORANGE_VERTE) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
  }
  
  else if(plateauNomJeu == ECHELLE_SERPENT_PEDAGOGIQUE) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
  }

  else if(plateauNomJeu == ECHELLE_SERPENT_PLUSIEURS_PIONS) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseEchelleSerpent(i, j, ...);
  }
   
  else if(plateauNomJeu == CARTAGENA) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseCartagena(i, j, ...);
  }

  else if(plateauNomJeu == NUMERI) {
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNumeri(i, j, ...);
  }
    *

  else {
    cout << "[Plateau.cpp] Erreur : Le nom du jeu n'est pas repertorie." << endl;
    exit(EXIT_FAILURE);
    /*
    for(int i=0 ; i<rangeAbs -1 ; i++)
      for(int j=0 ; j<rangeOrd -1 ; j++)
	plateau[i][j] = new CaseNormale(i, j, ...);
    *

  }
    */

  cout << "Creation d'un Plateau de taille : " << nbLignes << "*" << nbColonnes << endl;
}

Plateau::~Plateau() {
  cout << "Destruction d'un Plateau" << endl;
}
/********** FIN : CONSTRUCTEURS / DESTRUCTEURS **********/




/********** DEBUT : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/
Jeu* Plateau::getJeu() { return jeu; }
int Plateau::getNbLignes() { return nbLignes; }
int Plateau::getNbColonnes() { return nbColonnes; }
int Plateau::getNbCases() { return nbCases; }
string Plateau::getPlateauNomJeu() { return plateauNomJeu; }
int Plateau::getPlateauNbPionsParJoueur() { return plateauNbPionsParJoueur; }
int Plateau::getPlateauNbJoueursTotal() { return plateauNbJoueursTotal; }
Case* Plateau::getPlateau() { return plateau; }

void Plateau::setJeu(Jeu *j) { jeu = j; }
void Plateau::setNbLignes(int a) { nbLignes = a; }
void Plateau::setNbColonnes(int a) { nbColonnes = a; }
void Plateau::setNbCases(int a) { nbCases = a; }
void Plateau::setPlateauNomJeu(string s) { plateauNomJeu = s; }
void Plateau::setPlateauNbPionsParJoueur(int i) { plateauNbPionsParJoueur = i; }
void Plateau::setPlateauNbJoueursTotal(int i) { plateauNbJoueursTotal = i; }
void Plateau::setPlateau(Case* c) { plateau = c; }

ostream& operator<<(ostream& o,Plateau& p){
  int cptLignes = p.getNbLignes();
  int cptColonnes = p.getNbColonnes(); //= 1;
  for(int i=p.getNbCases() ; i>=1 ; i-=p.getNbColonnes()) {
    o << "|";
    if(cptLignes % 2 == 1) { // Si ligne impaire : sensPion = g->d ; sensAffichage = d->g
      for(int c=p.getNbColonnes()-1 ; c>=0 ; c--)
	o << p.plateau[i -c -1] << "|";
      o << endl;
      cptLignes--;
    }
    else { // Si ligne paire : sensPion = d->g ; sensAffichage = g->d
      for(int c=0 ; c<=p.getNbColonnes()-1 ; c++)
	o << p.plateau[i -c -1] << "|";
      o << endl;
      cptLignes--;
    }
  }
  return o;
}

Case Plateau::operator[](int pos) {
  return plateau[pos];
}
/********** FIN : ACCESSEURS ET REDEFINITION D'OPERATEUR(S) **********/




/********** DEBUT : FONCTIONS SUPPLEMENTAIRES **********/
bool Plateau::finDePartie() {
  string nomJeu = jeu->getNomJeuOuVariante();
  

  /* FIN DE PARTIE [ECHELLE_SERPENT + CARTAGENA]: LORSQUE TOUS LES PIONS D'UN JOUEUR SE TROUVENT SUR LA DERNIERE CASE DU PLATEAU */
  if(nomJeu == ECHELLE_SERPENT
     || nomJeu == ECHELLE_SERPENT_ORANGE_VERTE
     || nomJeu == ECHELLE_SERPENT_PEDAGOGIQUE
     || nomJeu == ECHELLE_SERPENT_PLUSIEURS_PIONS
     || nomJeu == CARTAGENA) {
 
    Case caseFinale = plateau[nbCases -1];
    int idJoueur;
    int cptPionsJoueurs[plateauNbJoueursTotal];
    for(int i=0 ; i<plateauNbJoueursTotal ; i++)
      cptPionsJoueurs[i] = 0;
    if(caseFinale.getNbPions() >= plateauNbPionsParJoueur) {
      forward_list<Pion> list = c.getListePions();
      for(auto it=list.begin() ; it!=list.end() ; ++it) {
	idJoueur = (*it).getIdJoueur();
	cptPionsJoueurs[idJoueur]++;
      }
      for(int i=0 ; i<plateauNbJoueursTotal ; i++)
	if(cptPionsJoueurs[i] == plateauNbPionsParJoueur)
	  return true;
    }
    else {
      //cout << "[EchelleSerpent.cpp]/finDePartie : Pas assez de pions sur la derniere case." << endl;
      return false;
    }
  }


  /* FIN DE PARTIE [NUMERI] : LORSQUE LES 3 DERNIERES CASES DU PLATEAU SONT OCCUPEES */
  else if(nomJeu == NUMERI) {
    Case caseFinale_1 = plateau[nbCases -1];
    Case caseFinale_2 = plateau[nbCases -2];
    Case caseFinale_3 = plateau[nbCases -3];
    if(caseFinale_1.getNbPions() != 0 && caseFinale_2.getNbPions() != 0 && caseFinale_3.getNbPions() != 0)
      return true;
  }
  return false;
}




void Plateau::deplacementPion(Pion pion) {
  string nomJeu = jeu->getNomJeuOuVariante();
  

  /* DEPLACEMENT DE PION [ECHELLE_SERPENT] : AVEC UN LANCER DE DE A 6 FACES */
  if(nomJeu == ECHELLE_SERPENT
     || nomJeu == ECHELLE_SERPENT_ORANGE_VERTE
     || nomJeu == ECHELLE_SERPENT_PEDAGOGIQUE
     || nomJeu == ECHELLE_SERPENT_PLUSIEURS_PIONS) {
    
    srand(time(nullptr));
    int de = (rand() % 6) +1;
    
    Case casePion = plateau[pion.getPosition()];
    casePion.retirerPion(pion);

    int new_position = 0;
    if(pion.getPosition() + de >= nbCases -1)
      new_position = nbCases -1;
    else
      new_position = pion.getPosition() + de;
    Case new_casePion = plateau[new_position];
    
    new_casePion.ajouterPion(pion);
    // voir si new_casePion est ECHELLE_BAS ou SERPENT_TETE
  }


  /* DEPLACEMENT DE PION [CARTAGENA] : AVEC DES CARTES A SYMBOLE */
  else if(nomJeu == CARTAGENA) {

  }

  /* DEPLACEMENT DE PION [NUMERI] : AVEC UN LANCER DE DE A 6 FACES */
  else if(nomJeu == NUMERI) {

  }
}
/********** FIN : FONCTIONS SUPPLEMENTAIRES **********/
