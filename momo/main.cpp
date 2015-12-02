#include <iostream>
#include "Plateau.hpp"
#include "Case.hpp"
#include "Pion.hpp"

using namespace std;

int main(){

  int nbJoueurs;
  while(nbJoueurs > 6 || nbJoueurs <= 1){
    cout << "Entrez le nombre de joueurs" << endl;
    cin >> nbJoueurs;
    if(nbJoueurs > 6)
      cout << "Il ne peut y avoir que six joueurs maximum" << endl;
    if(nbJoueurs <= 1)
      cout << "Il doit y avoir au moins deux joueurs" << endl;
  }
  Pion pions[] = { Pion("1","R",0,0),
		   Pion("2","V",0,0),
		   Pion("3","B",0,0),
		   Pion("4","Y",0,0),
		   Pion("5","N",0,0),
		   Pion("6","O",0,0)};
  
  Plateau p = Plateau(25,2,nbJoueurs);
  
  p.cases[0]->ajouterPions(pions,nbJoueurs);
  cout << p << endl;
  return 0;
}
