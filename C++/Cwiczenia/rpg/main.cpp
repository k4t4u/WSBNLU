#include "Latarka.h"
#include "LukMysliwski.h"
#include "MagicznaRozdzka.h"
#include "Plecak.h"
#include <iostream>
#include <vector>

using namespace std;
int main() {

  MagicznaRozdzka rozdzka(0.1, "Hokus-Pokus");
  rozdzka.akcja(); // Rzucam zaklecie: Hokus-Pokus
  cout << rozdzka.opis() << endl;

  LukMysliwski luk(1.2, 2);
  cout << luk.opis() << endl;
  luk.akcja();
  cout << luk.opis() << endl;
  luk.akcja();
  cout << luk.opis() << endl;
  luk.akcja();
  cout << luk.opis() << endl;
  luk.akcja();
  luk.dodajStrzaly(3);
  luk.akcja();
  cout << luk.opis() << endl;
  luk.akcja();

  Latarka latarka(0.5, false);
  latarka.akcja();
  latarka.akcja();
  latarka.opis();

  Plecak p(10);
  p.dodaj(rozdzka);
  p.dodaj(luk);
  p.dodaj(latarka);

  p.wypisz();

  p.uzyj(1);
  p.usun(1);
  p.wypisz();

  cout << " Waga plecaka : " << p.getWaga() << endl;
  Plecak p2(2.5);

  p2.dodaj(p);
  p2.wypisz();

  cout << " Waga plecaka 2 : " << p2.getWaga() << endl;

  std::vector<Przedmiot *> przedmioty;
  przedmioty.push_back(&rozdzka);
  przedmioty.push_back(&luk);
  przedmioty.push_back(&latarka);

  for (auto przedmiot : przedmioty) {
    cout << przedmiot->opis() << endl;
    przedmiot->akcja();
  }

  // double  * p = dynamic_cast<double *>(przedmioty[1]);

  // double  * w = (double *)(przedmioty[1]);
  // cout << *(w+1) << endl;

  // LukMysliwski * p = dynamic_cast<LukMysliwski*>(przedmioty[1]);
  // if( p!=nullptr){
  //   p->dodajStrzaly(3);
  // }
  // cout << przedmioty[1]->opis() << endl;

  // if( LukMysliwski * p = dynamic_cast<LukMysliwski*>(przedmioty[1]);
  //     p!=nullptr){
  //   p->dodajStrzaly(3);
  // }
  // cout << przedmioty[1]->opis() << endl;

  // try{
  //   (dynamic_cast<LukMysliwski*>(przedmioty[2]))
  //    ->dodajStrzaly(3);
  //  cout << przedmioty[2]->opis() << endl;
  // }catch(...){
  //   cout << "wyjątek \n";
  // }
}