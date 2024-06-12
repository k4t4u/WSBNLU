#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Towar {
  protected:
    string nazwa;
    double cena;
    double waga;
public:
  Towar(string nazwa, double cena,double waga ) 
  : nazwa(nazwa), cena(cena), waga(waga)
  {
    
  }
  Towar() {
    nazwa = "";
    cena = 0;
    waga = 0;
  }
  virtual string toString() const{
    ostringstream str;
    str << nazwa << " " << cena << " " << waga;
    return str.str();
  }

  //  <towar><nazwa>Marchew</nazwa>         </towar>
  // string toXML() const{
     
  // }

  friend std::ostream& operator<<(std::ostream& out, const Towar& t);

  friend std::istream& operator>>(std::istream& in, Towar& t);

};

std::ostream& operator<<(std::ostream& out, const Towar& t) {
  out << t.nazwa << endl;
  out << t.cena << endl;
  out << t.waga << endl;
  return out;

}

std::istream& operator>>(std::istream& in, Towar& t) {

  in >> t.nazwa >> t.cena >> t.waga;
  return in;
  
}