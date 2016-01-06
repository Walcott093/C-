#ifndef CASECARTAGENA
#define CASECARTAGENA
#include "../../architectureGenerique/Case.hpp"
using namespace std;

public class CaseCartagena : public Case {

public:
  CaseCartagena(string,int,int,int,int);//symbole,specificite,position
                                        //nbPionsMax,nbPions
  virtual ~CaseCartagena();
  string getSymbole();
  void setSymbole(string);
private:
  string symbole; //symbole de la case
}
