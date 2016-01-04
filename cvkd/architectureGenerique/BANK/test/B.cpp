#include <iostream>
#include "B.hpp"
using namespace std;

B::B(): A() {cout<<"B cree"<<endl;}
B::~B() {cout<<"B detruit"<<endl;}

string B::getB() {return b;}
