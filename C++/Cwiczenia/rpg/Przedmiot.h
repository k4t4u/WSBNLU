#pragma once
#include <iostream>
class Przedmiot
{
  protected:
    double waga;
  public:
    Przedmiot(double waga=0.0)
    :waga(waga)
    {
    }
  virtual double getWaga() const
  {
    return waga;
  }
  void setWaga(double waga)
  {
    this->waga=waga;
  }
  virtual std::string opis() const = 0;
  virtual void akcja() = 0;
};