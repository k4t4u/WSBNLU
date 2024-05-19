#include <iostream>
using namespace std;
#include "Vector.h"


int main() {
  Vector v(3);
  
  v.at(1) = 5;
  v.at(2) = 3;
  v.at(3) = 4;
  std::cout << v << std::endl;

  Vector b2 = v;
  Vector b(v);
  std::cout << b << std::endl;

  b.at(2) = 10000;

  cout << "zmiana  v = " << v << " b = " << b << endl;
  Vector c(2);
  // b = (c = v);
  c=v;
  cout << "przed  v = " << v << " c = " << c << endl;
  c.at(2) = 1000;

  cout << "zmiana  v = " << v << " c = " << c << endl;

  // auto d = v + b;

//  v.push_back(5);
  
  //v.x + 4;
  
  double *tab = new double[10];
  double tab2[10];

  tab[4] = 5;
  tab2[4] = 5;

  //delete[] tab;
  
}

 