#include <iostream>
#include <sstream>
#include <fstream> 
#include "Towar.h"
#include "Sklep.h"

int main() {

  Towar marchew("MarchewBio", 11.0, 2.0 );
  std::cout << marchew << endl;

  Towar burak;
  cout << burak << endl;
  istringstream in("Burak 7 2.3");
  in >> burak;
  cout << burak << endl;

  Sklep sklep;
  sklep.dodajTowar(marchew);
  sklep.dodajTowar(burak);
   cout << "Zawartosc sklepu \n";
   cout << sklep << endl;
    cout << "--------------\n";
  ofstream plik("baza.txt");
  plik << burak;
}

