
#include "samochod.h"
#include "warsztat.h"
//#include "czas.h"
#include <iostream>


using namespace std;
int main() {
  Samochod s1; 
  s1.wypisz();
  Samochod s2("BMW", "M5", -5000);
  s2.wypisz();
  s2.jedz(100);
  s2.wypisz();

  Czas c1(15,02);
  c1.wypisz();
  //c1.wczytaj();
  //c1.wypisz();

  Warsztat w1("AutoCar","Jan Kowalski", Czas(7,0),
  Czas(16,0));
  w1.wypisz();
  w1.oddajAuto(s1);
  w1.oddajAuto(s2);
  w1.oddajAuto(s2);
  w1.wypisz();


  
}