#include <iostream>
#include "Plateau.hpp"
#include "Case.hpp"
#include "Pion.hpp"

using namespace std;

int main(){
  int largeur,longueur,nbJoueurs,nbBonusMalus,nbEchelleSerpent;
  
  /*************VERIFICATION DES ENTREE CLAVIER UTILISATEUR********************/
  cout << "Entrez la longueur du plateau" << endl;
  cin >> longueur;
  while(cin.fail()){
    cout << "Entrez un nombre entier pour la longueur du plateau" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> longueur;
  }
  
  cout << "Entrez la largeur du plateau" << endl;
  cin >> largeur;
  while(cin.fail()){
    cout << "Entrez un nombre entier pour la largeur du plateau" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> largeur;
  }
 
  cout << "Entrez le nombre de joueurs" << endl;
  cin >> nbJoueurs;
  while(nbJoueurs > 6  || nbJoueurs <= 1 || cin.fail()){
    cout << "Entrez un nombre entier de joueurs entre 2 et 6" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> nbJoueurs;
  }

  cout << "Entrez le nombres de bonus/malus" << endl;
  cin >> nbBonusMalus;
  while(nbBonusMalus > longueur*largeur || nbBonusMalus < 0 || cin.fail()){
    cout << "Entre un nombre entier de bonus/malus compris entre 0 et le nombre de cases" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> nbBonusMalus;
  }
  cout << "Entrez le nombre d'Echelle/Serpent" << endl;
  cin >> nbEchelleSerpent;
  while(nbEchelleSerpent > longueur*largeur || nbEchelleSerpent < 0){
    cout << "Entre un nombre entier d'Echelle/Serpent compris entre 0 et le nombre de cases" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> nbEchelleSerpent;
  }
  /****************FIN VERIFICATIONS*****************************/
  
  Plateau p = Plateau(longueur, largeur, nbJoueurs, nbBonusMalus, nbEchelleSerpent);
  
  Pion pions[] = { Pion("1","\033[1;31mR\033[0m",0,0,longueur,largeur),
		   Pion("2","\033[1;32mV\033[0m",0,0,longueur,largeur),
		   Pion("3","\033[1;34mB\033[0m",0,0,longueur,largeur),
		   Pion("4","\033[1;33mJ\033[0m",0,0,longueur,largeur),
		   Pion("5","\033[1;37mB\033[0m",0,0,longueur,largeur),
		   Pion("6","\033[1;36mC\033[0m",0,0,longueur,largeur) };

  p.cases[0]->ajouterPions(pions,nbJoueurs);
  cout << p << endl;
  return 0;
}
