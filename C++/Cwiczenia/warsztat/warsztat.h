#pragma once 

#include <iostream>
#include <vector>
#include "czas.h"
#include "samochod.h"
using namespace std;

class Warsztat{
string nazwa;
string wlasciciel;
Czas czasOtwarcia; 
Czas czasZamkniecia;

  std::vector<Samochod> auta;

public:
  Warsztat (string nazwa, string wlasciciel, Czas czasOtwarcia, Czas czasZamkniecia)
  :nazwa(nazwa), wlasciciel(wlasciciel), czasOtwarcia(czasOtwarcia), czasZamkniecia (czasZamkniecia)
  {
  
  }

  void oddajAuto(const Samochod & s){
    auta.push_back(s);
  }
  Samochod zwrocAuto(int indeks){
    if(indeks < auta.size()){
      auto s = auta[indeks];
      auta.erase(auta.begin()+indeks);
      return s;
    }
    return Samochod{};
  }
void wypisz ()
{
  cout<<nazwa<<endl;
  cout<<wlasciciel<<endl;
  // cout<<czasOtwarcia<<endl;
  // cout<<czasZamkniecia<<endl;
  czasOtwarcia.wypisz();
  czasZamkniecia.wypisz();
  cout << "Auta:"<< endl;
  int i=0;
  for(auto samochod: auta){
    cout << i++ << " > ";
    samochod.wypisz();
  }  
}

};


