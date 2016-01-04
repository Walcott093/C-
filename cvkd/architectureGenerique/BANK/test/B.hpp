#ifndef B_HPP
#define B_HPP
#include "A.hpp"
using namespace std;
class B : public A {
public:
  B();
  virtual ~B();

  string getB();
  string b = "BBB";
};

#endif
