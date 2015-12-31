#include <iostream>
#include "Pion.hpp"
#include "Case.hpp"
using namespace std;

int main() {
  cout << "     Hello !" << endl;
  Pion p1(1, 1, "bleu", 0, 0);
  cout << "     " << p1 << endl;

  Pion p2(4, 2, "violet", 6, 7);

  cout << "     " << p2 << endl;

  Case c1(0, 0, 4, 0);
  //  cout << "     " << c1 << endl;

  return 0;
}
