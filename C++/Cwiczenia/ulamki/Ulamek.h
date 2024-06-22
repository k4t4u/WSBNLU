#pragma once
#include <iostream>
#include <numeric>
using namespace std;

class Ulamek {
private:
  using typ = long long;
  typ licznik;
  typ mianownik;

public:
  Ulamek(typ licznik = 0, typ mianownik = 1)
      : licznik(licznik), mianownik(mianownik) {
    typ nwd = gcd(licznik, mianownik);
    this->licznik = licznik / nwd;
    this->mianownik /= nwd;
    if (this->mianownik < 0) {
      this->mianownik *= -1.0;
      this->licznik *= -1.0;
    }
  }
  friend ostream &operator<<(ostream &out, const Ulamek &u);
  friend Ulamek operator+(const Ulamek &u1, const Ulamek &u2);
  friend Ulamek operator-(const Ulamek &u1, const Ulamek &u2);
  friend Ulamek operator*(const Ulamek &u1, const Ulamek &u2);
  friend Ulamek operator/(const Ulamek &u1, const Ulamek &u2);
  friend bool operator==(const Ulamek &u1, const Ulamek &u2);
  friend bool operator<(const Ulamek &u1, const Ulamek &u2);
  friend bool operator>(const Ulamek &u1, const Ulamek &u2);
  

  Ulamek operator++() {
    licznik += mianownik;
    return *this;
  }

  Ulamek operator++(int) {
    auto temp = *this;
    this->licznik += this->mianownik;
    return temp;
  }

  Ulamek operator--() {
    licznik -= mianownik;
    return *this;
  }

  Ulamek operator--(int) {
    auto temp = *this;
    this->licznik -= this->mianownik;
    return temp;
  }
operator double() const {
  return static_cast<double>(licznik)/mianownik;
}

};

ostream &operator<<(ostream &out, const Ulamek &u) {
  if (u.mianownik == 1)
    out << u.licznik;
  else
    out << u.licznik << "/" << u.mianownik;
  return out;
}

Ulamek operator+(const Ulamek &u1, const Ulamek &u2) {
  return Ulamek(u1.licznik * u2.mianownik + u2.licznik * u1.mianownik,
                u1.mianownik * u2.mianownik);
}
Ulamek operator-(const Ulamek &u1, const Ulamek &u2) {
  return Ulamek(u1.licznik * u2.mianownik - u2.licznik * u1.mianownik,
                u1.mianownik * u2.mianownik);
}
Ulamek operator*(const Ulamek &u1, const Ulamek &u2) {
  return Ulamek(u1.licznik * u2.licznik, u1.mianownik * u2.mianownik);
}
Ulamek operator/(const Ulamek &u1, const Ulamek &u2) {
  return Ulamek(u1.licznik * u2.mianownik, u1.mianownik * u2.licznik);
}
bool operator==(const Ulamek &u1, const Ulamek &u2) {
  return (u1.mianownik == u2.mianownik && u1.licznik == u2.licznik);
}
bool operator!=(const Ulamek &u1, const Ulamek &u2) { return !(u1 == u2); }
bool operator<(const Ulamek &u1,
               const Ulamek &u2) { // p1/q1 < p2/q2    <=> p1*q2 < p2*q1
  return (u1.licznik * u2.mianownik < u2.licznik * u1.mianownik);
}
bool operator>=(const Ulamek &u1, const Ulamek &u2) { return !(u1 < u2); }
// bool operator>(const Ulamek& u1, const Ulamek& u2){
//   return u1>=u2 && u1!=u2;
// }
bool operator>(const Ulamek &u1, const Ulamek &u2) {
  return (u1.licznik * u2.mianownik > u2.licznik * u1.mianownik);
}
