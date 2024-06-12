#pragma once
#include <iostream>
#include "Przedmiot.h"

class MagicznaRozdzka : public Przedmiot 
{
  protected:
    //double waga;
  std::string zaklecie;
 public:
  MagicznaRozdzka(double waga,std::string zaklecie )
  :Przedmiot(waga),zaklecie(zaklecie)
  {
    
  }

  void akcja() override {
    std::cout << "Rzucam zaklecie: " << zaklecie << std::endl;
  }

  std::string opis() const override {
    return "Rozdzka magiczna " + zaklecie;
  }
    
};