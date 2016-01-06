#ifndef CASE_CARTAGENA_HPP
#define CASE_CARTAGENA_HPP
#include "../../architectureGenerique/Case.hpp"
using namespace std;

class CaseCartagena : public Case {

public:
  CaseCartagena();
  CaseCartagena(int, int, int, string); // position, nbPionsMax, nbPions, symbole
  virtual ~CaseCartagena();

  string getSymbole();
  void setSymbole(string);

  string randomSymbole();

private:
  string symbole; //symbole de la case
};

#endif //CASE_CARTAGENA_HPP
