#include "Postac.h"

Postac::Postac(string n, int pz, int s, int w)
:nazwa(n), punktyZycia(pz), sila(s), wytrwalosc(w) 
{
}

string Postac::getNazwa() const 
{
    return nazwa;
}

void Postac::obrona(int obrazenia) 
{
    int redukcja = wytrwalosc / 2;
    int rzeczywisteObrazenia = obrazenia - redukcja;
    if (rzeczywisteObrazenia > 0) 
    {
        punktyZycia -= rzeczywisteObrazenia;
    }
}

bool Postac::czyZyje() const 
{
    return punktyZycia > 0;
}

ostream& operator<<(ostream& os, const Postac& p) 
{
    os << "Profesja: " << p.nazwa << " Ilosc Zycia: " << p.punktyZycia << " Sila: " << p.sila << " Wytrwalosc: " << p.wytrwalosc;
    return os;
}

istream& operator>>(istream& is, Postac& p) 
{
    is >> p.nazwa >> p.punktyZycia >> p.sila >> p.wytrwalosc;
    return is;
}
