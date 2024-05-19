#include "Przesylka.h"
#include <iostream>
using namespace std;

class PrzesylkaPieniezna : Przesylka {
protected:
  double kwota;

public:
  PrzesylkaPieniezna(const string &adresat, const string &nadawca, double kwota)
      : Przesylka(adresat, nadawca), kwota(kwota) {}

  void wypisz() const {
    Przesylka::wypisz();

    cout << "Kwota: " << kwota << endl;
  }

  double oplata() const { return (10.0 + kwota * 0.01); }
};