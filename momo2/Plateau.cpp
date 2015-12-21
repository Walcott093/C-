#include <iostream>
#include "Plateau.hpp"

using namespace std;

Plateau::Plateau(const int _longueur, const int _largeur, const int _nbJoueurs, const int _nbBonusMalus,const int _nbEchelleSerpent):
  longueur(_longueur) , largeur(_largeur) , nbJoueurs(_nbJoueurs), nbBonusMalus(_nbBonusMalus), nbEchelleSerpent(_nbEchelleSerpent){

  cases = new Case*[longueur];
  
  for(int i = longueur-1 ; i >= 0 ; i-- ){
    cases[i] = new Case[largeur];
    for(int j = 0 ; j < largeur ; j++)
      cases[i][j] = Case(nbJoueurs);
  }
  randomBM();
  randomES();
}

void Plateau::randomBM(){
  int randomI,randomJ;
  srand(time(nullptr));
  for(int i = 0 ; i < nbBonusMalus ; i++){
    randomI = (rand() % (longueur-1)) + 1;
    randomJ = (rand() % (largeur-1) ) + 1;
    if(!cases[randomI][randomJ].getIsBonus() && !cases[randomI][randomJ].getIsMalus())
      cases[randomI][randomJ].setIsBonus(true);
    else i--;
  }
  for(int i = 0 ; i < nbBonusMalus ; i++){
    randomI = (rand() % (longueur-1)) + 1;
    randomJ = (rand() % (largeur-1)) + 1;
    if(!cases[randomI][randomJ].getIsMalus() && !cases[randomI][randomJ].getIsBonus())
      cases[randomI][randomJ].setIsMalus(true);
    else i--;
  }
}

void Plateau::randomES(){
  int randomIhaut,randomJhaut,randomIbas,randomJbas;
  srand(time(nullptr));
  for(int i = 0 ; i < nbEchelleSerpent ; i++){
    //gerer le fait que les randomHaut doivent de trouver en haut du plateau et les randomBas en bas, la ce n'est pas le cas et on peut avoir un randomHaut en bas d'un randomBas -> c'est illogique #Spoke
    randomIhaut = (rand() % (longueur-1));
    randomJhaut = (rand() % (largeur-1));
    randomIbas  = (rand() % (longueur-1));
    randomJbas  = (rand() % (largeur-1));
    //tester la premiere et derniere case
    if(randomIbas == longueur && randomJbas == 0){//premiere case
      i--; continue;
    }
    if(randomIhaut == 0 && randomJhaut == 0){ //derniere case
      i--;
      continue;
    }
    if(cases[randomIhaut][randomJhaut].estVide() && cases[randomIbas][randomJbas].estVide())
      cases[randomIhaut][randomJhaut].es = Echelle_Serpent(randomIhaut,randomJhaut,randomIbas,randomJbas,true,false);
    else i--;
  }
  for(int i = 0 ; i < nbEchelleSerpent ; i++){
    //gerer le fait que les randomHaut doivent de trouver en haut du plateau et les randomBas en bas, la ce n'est pas le cas et on peut avoir un randomHaut en bas d'un randomBas -> c'est illogique #Spoke
    randomIhaut = (rand() % (longueur-1));
    randomJhaut = (rand() % (longueur-1));
    randomIbas  = (rand() % (longueur-1));
    randomJbas  = (rand() % (longueur-1));
    //tester la premiere et derniere case
    if(randomIbas == longueur && randomJbas == 0){//premiere case
      i--; continue;
    }
    if(randomIhaut == 0 && randomJhaut == 0){ //derniere case
      i--;
      continue;
    }
    if(cases[randomIhaut][randomJhaut].estVide() && cases[randomIbas][randomJbas].estVide())
      cases[randomIhaut][randomJhaut].es = Echelle_Serpent(randomIhaut,randomJhaut,randomIbas,randomJbas,false,true);
    else i--;
  }
}


Plateau::~Plateau(){
}

int Plateau::getLongueur(){
  return longueur;
}

int Plateau::getLargeur(){
  return largeur;
}

ostream& operator<<(ostream& o,Plateau& p){

  for(int i = p.getLongueur()-1 ; i >= 0 ; i --){
      o << "|";
    for(int j = 0 ; j < p.getLargeur() ; j++)
      o << p.cases[i][j] << "|";
    o << endl;

  }
  return o;
}
