// Jagodzinski Piotr
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double a, b, c, delta, pierwiastek;

  cout << "Podaj kolejno wspolczynniki wielomianu kwadratowego" << endl;
  cin >> a >> b >> c;

  delta = (b * b) - (4 * a * c);

  if (delta < 0)
    cout << "Rownanie nie ma miejsc zerowych" << endl;

  if (delta == 0) {
    double x;
    x = -b / (2 * a);
    cout << "Rownanie ma jedno miejsce zerowe: " << fixed << setprecision(2) << x <<endl;
  }

  if (delta > 0) {
    double x1, x2;
    pierwiastek = sqrt(delta);
    x1 = (-b - pierwiastek) / (2 * a);
    x2 = (-b + pierwiastek) / (2 * a);
    cout << "Rownanie ma dwa rozwiazania w punktach x=" << fixed << setprecision(2) << x1 << " i   x=" << x2
         << endl;
  }
  return 0;
}