#ifndef POSTAC_H
#define POSTAC_H
#include <iostream>
#include <string>
using namespace std;

class Postac 
{
protected:
    string nazwa;
    int punktyZycia;
    int sila;
    int wytrwalosc;

public:
    Postac(string n, int pz, int s, int w);
    virtual ~Postac() = default;

    string getNazwa() const;

    virtual void atak(Postac &przeciwnik) = 0;
    virtual void obrona(int obrazenia);

    bool czyZyje() const;

    friend ostream& operator<<(ostream& os, const Postac& p);
    friend istream& operator>>(istream& is, Postac& p);
};

#endif // POSTAC_H