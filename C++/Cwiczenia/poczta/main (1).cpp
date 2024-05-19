#include "Paczka.h"
#include "Przesylka.h"
#include "PrzesylkaPieniezna.h"
#include <iostream>
using namespace std;

void fun(const Przesylka &p) { p.wypisz(); }

void wypiszInfoIOplate(Przesylka & przesylka) {
  przesylka.wypisz();
  cout << "Oplata : "<< przesylka.oplata() << endl;
  cout << "--------------\n";
}

int main() {
  string nadawca = "Jan Kowalski";
  Przesylka list(nadawca, "Edwarda Nowaka");
  // list.wypisz();
  // cout << list.oplata() << endl;
  // fun(list);
  // //int B = 7;
  Paczka paczka(nadawca, "Edward Nowak", 15, Paczka::B);
  // paczka.wypisz();

  Paczka paczka2("Jan Kowalski", "Edward Nowak", 15, 
  Paczka::Gabaryt(10));
  // paczka2.wypisz();
  // cout << paczka2.oplata() << endl;

  PrzesylkaPieniezna kasa("XXXX", "YYYY", 100000);

  wypiszInfoIOplate(paczka);
  wypiszInfoIOplate(kasa);

  Poczta poczta;

  poczta.nadaj(paczka);
  poczta.nadaj(kasa);
  poczta.nadaj(list);
  
  poczta.wypisz();
  
}