#pragma once
#include "Przedmiot.h"
#include <iostream>
#include <string>
// using namespace std;

class Latarka : public Przedmiot {
protected:
  bool wlaczona;

public:
  Latarka(double waga, bool wlaczona = false)
      : Przedmiot(waga), wlaczona(wlaczona) {}
  void akcja() override {
    wlaczona = !wlaczona;
    if (wlaczona) {
      std::cout << "Swieci" << std::endl;
    } else {
      std::cout << "Nie swieci" << std::endl;
    }
  }
  std::string opis() const override {
    using namespace std;
    return std::string("Latarka jest") + (wlaczona ? "wlaczona"s : "wylaczona"s);
  }
};