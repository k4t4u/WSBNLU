#pragma once

#include <iostream>
using namespace std;

class Przesylka {
protected:
  string adresat;
  string nadawca;

public:
  Przesylka(const string &adresat, const string &nadawca)
      : adresat(adresat), nadawca(nadawca) {}

  void wypisz() const// w metodach ktore nie modyfikuja obiektu, uzywamy: const
  {
    cout << "Informacje o przesylce: " << endl;
    cout << "Adresat: " << adresat << endl;
    cout << "Nadawca: " << nadawca << endl;
  }

  double oplata() const { return 6.0; }
};

