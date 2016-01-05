#ifndef CASECARTAGENA
#define CASECARTAGENA
#include "Case.hpp"

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
