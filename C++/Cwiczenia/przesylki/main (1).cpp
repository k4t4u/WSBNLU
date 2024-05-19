#include "Przesylka.h"
#include "Paczka.h"
#include <iostream>
#include "PrzesylkaPieniezna.h"
using namespace std;

void fun(const Przesylka & p){
  p.wypisz();
}

int main() {
  string nadawca = "Jan Kowalski";
  Przesylka list(nadawca, "Edwarda Nowaka");
  list.wypisz();
  cout << list.oplata() << endl;
  fun(list);
  //int B = 7;
  Paczka paczka(nadawca, "Edward Nowak", 15, Paczka::B);
  paczka.wypisz();

  Paczka paczka2("Jan Kowalski", "Edward Nowak", 15, Paczka::Gabaryt(10));
  paczka2.wypisz();
  cout << paczka2.oplata() << endl;
  
  PrzesylkaPieniezna kasa("XXXX", "YYYY", 100000);
  kasa.wypisz();
  cout << kasa.oplata() << endl;
}