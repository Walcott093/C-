#include <iostream>
#include <forward_list>
#include "Pion.hpp"
#include "Case.hpp"
using namespace std;

int main() {
  cout << "Hello !" << endl;
 

  Pion p1(1, 1, "bleu", 0, 0);
  cout << "p1= \n" << p1 << endl;
  
  Pion p2(4, 2, "violet", 6, 7);
  cout << "p2= \n" << p2 << endl;

  Pion p3(1, 2, "rose", 1, 1);
  cout << "p3= \n" << p3 << endl;

  Case c1(0, 0, 4, 0);
  cout << "c1= \n" << c1 << endl;

  c1.ajouterPion(p1);
  cout << "ajouterPion(p1): \n" << c1 << endl;

  c1.ajouterPion(p2);
  cout << "ajouterPion(p2): \n" << c1 << endl;
  
  c1.ajouterPion(p3);
  cout << "ajouterPion(p3): \n" << c1 << endl;

  /*
  c1.retirerPion(p2);
  cout << "retirerPion(p2): \n" << c1 << endl;
  c1.retirerPion(p1);
  cout << "retirerPion(p1): \n" << c1 << endl;
  */
  forward_list<Pion> flp = {p1, p3};
  c1.retirerPions(flp, 2);
  cout << "retirerPions(flp, 2): \n" << c1 << endl;


  /*
  forward_list<Pion> first;
  first.push_front(p1);

  for(auto it=first.begin() ; it!=first.end() ; ++it)
    cout << "1er aff - list: " << *it << endl;

  first.push_front(p2);
  
  for(auto it=first.begin() ; it!=first.end() ; ++it)
    cout << "2eme aff - list: " << *it << endl;

  for(auto it=first.begin() ; it!=first.end() ; ++it)
    cout << "3eme aff - list: " << (*it).getX() << endl;
  */



  /*
  string s1 = "he";
  string s2 = "ho";
  string s3 = "he";

  if(s1 == s3) cout << "gg" << endl;
  else cout << "lose" << endl;
  */



  /*
  // g++ -std=c++11 -Wall -o test test.cpp
  forward_list<int> list;
  list.push_front(4);
  list.push_front(7);
  list.push_front(22);
  
  forward_list<int> second;
  second.push_front(2);
  second.push_front(3);
  
  for(auto it=list.begin() ; it!=list.end(); ++it)
    cout << *it << endl;

  list.remove(7);

  for(auto it=list.begin() ; it!=list.end(); ++it)
    cout << *it << endl;
  
  list.splice_after(list.before_begin(), second);

  for(auto it=list.begin() ; it!=list.end(); ++it)
    cout << *it << endl;

  cout << "test 1st ele list = " << *list.begin() << endl;
*/


 
  return 0;
}
