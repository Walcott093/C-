#include <iostream>
#include "A.hpp"
using namespace std;

A::A() {cout<<"A cree"<<endl;}
A::~A() {cout<<"A detruit"<<endl;}

string A::getA() {return a;}
