#pragma once
#include "Przedmiot.h"
#include <iostream>
#include <string>

class LukMysliwski : public Przedmiot {
protected:
  unsigned int strzaly;

public:
  LukMysliwski(double waga, int strzaly = 5)
      : Przedmiot(waga), strzaly(strzaly) {}

  void akcja() override {
    if (strzaly != 0) {
      std::cout << "Strzelam z łuku" << std::endl;
      strzaly--;
    }
  }

  std::string opis() const override {
    return "Luk Mysliwski " + std::to_string(strzaly) + " strzał";
  }

    void dodajStrzaly(unsigned int strzaly)
    {
        this -> strzaly += strzaly;
    }

};