#include "Ulamek.h"
#include <iostream>
using namespace std;

int main() {

  Ulamek a(1, 2), b(1, 4), f(12432, 1235435);

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;

  Ulamek c(5);
  Ulamek d = a * f + b + f;

  cout << d << endl;
  ++d;
  cout << d << endl;
  cout << double(d) << endl;
}