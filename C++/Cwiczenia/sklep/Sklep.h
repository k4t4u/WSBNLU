#pragma once 
#include <vector>
#include "Towar.h"

class Sklep {
private:
  std::vector<Towar *> towary;

public:
  void dodajTowar(Towar & t) 
  {
    towary.push_back(& t);
  }

  friend std::ostream& operator<<(std::ostream& out, const Sklep& t);

  friend std::istream& operator>>(std::istream& in, Sklep& t);

};

std::ostream& operator<<(std::ostream& out, const Sklep& t) {
  cout << t.towary.size() << endl;
  for(auto elem: t.towary){
     out << elem->toString() << endl;
//out << "towar "<< elem->toString() << endl;
  }
  // out << "koniec\n";
  return out;
}

std::istream& operator>>(std::istream& in, Sklep& sklep) {
  int ile;
  in >> ile;
  for(int i=0; i<ile; ++i){
    Towar * t = new Towar();
    in >> *t;

    // in >> znacznik;
    // switch(znacznik){
    // case TOWAR: t = new Towar(); break;
    // case SPOZYWCZY : t = new ProduktSpozywczy(); break;    
    // }
    // t->wczytaj();
    sklep.towary.push_back(t);
  }
  return in;
}