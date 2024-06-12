#pragma once
#include "Latarka.h"
#include "LukMysliwski.h"
#include "MagicznaRozdzka.h"
#include "Przedmiot.h"
#include <iostream>
#include <vector>

class Plecak : public Przedmiot {
private:
  std::vector<Przedmiot *> plecak;
  double pojemnosc;
  double wagaPrzedmiotow = 0;

public:
  Plecak(double pojemnosc);
  bool dodaj(Przedmiot *przedmiot);
  bool dodaj(Przedmiot &przedmiot);
  Przedmiot *usun(int pozycja);
  void uzyj(int pozycja);

  void wypisz() const;
  std::string opis() const override { 
    std::string  s = "Plecak \n";
    for (int i = 0; i < plecak.size(); i++) {
      s += std::to_string(i + 1) + "\t" + plecak[i]->opis() + "\n";
    }
    return s;
  }
  void akcja() override { wypisz();}

  double getWaga() const override {
    return waga + wagaPrzedmiotow;
  }
};

Plecak::Plecak(double pojemnosc) : Przedmiot(1), pojemnosc(pojemnosc) {}

bool Plecak::dodaj(Przedmiot *przedmiot) {
  if (pojemnosc - wagaPrzedmiotow - przedmiot->getWaga() >= 0) {
    plecak.push_back(przedmiot);
    wagaPrzedmiotow += przedmiot->getWaga();
    return true;
  }
  return false;
}

bool Plecak::dodaj(Przedmiot &przedmiot) { return dodaj(&przedmiot); }

void Plecak::uzyj(int pozycja) { plecak[pozycja - 1]->akcja(); }

void Plecak::wypisz() const {
  std::cout << "Zawartosc plecaka:\n" << opis(); 
}

Przedmiot *Plecak::usun(int pozycja) {
  Przedmiot *p = plecak[pozycja];
  wagaPrzedmiotow -= p->getWaga();
  plecak.erase(plecak.begin() + pozycja - 1);
  return p;
}
