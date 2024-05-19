#pragma once

#include "Przesylka.h"
#include <iostream>
using namespace std;

// enum class Gabaryt { A, B, C };
// map<Gabaryt, double> ceny;

class Paczka : public Przesylka {
public:
enum Gabaryt { A, B, C };
protected:
  double waga;
  Gabaryt gabaryt;

public:
  Paczka(const string &adresat, const string &nadawca, double waga,
         Gabaryt gabaryt)
      : Przesylka(adresat, nadawca), waga(waga), gabaryt(gabaryt) {}

  void wypisz() const // w metodach ktore nie modyfikuja obiektu, uzywamy: const
  {
    Przesylka::wypisz();
    cout << "Waga: " << waga << endl;
    cout << "Gabaryt: " << gabaryt << endl;
  }

  double oplata() const {
    switch (gabaryt) {
    case A:
      return 14.99; break;
    case B:
      return 15.99;
    case C:
      return 18.99;
    default:
      return 100000;
    }
  }
};