// Jagodzinski Piotr zadanie oceny.
#include <iostream>
using namespace std;

int main (){
  int ocena;
  cin >> ocena;

  switch (ocena){
    case 1: cout << "niedostateczny";
    break;
    case 2: cout << "dopuszczajacy";
    break;
    case 3: cout << "dostateczny";
    break;
    case 4: cout << "dobry";
    break;
    case 5: cout << "bardzo dobry";
    break;
    case 6: cout << "celujacy";
    break;
    default: cout << "nie ma takiej oceny";
  }
  return 0;
}