#include "Pracownik.h"
#include <iostream>

Pracownik::Pracownik(const std::string& imie, int wiek, const std::string& dzial) 
    : Osoba(imie, wiek), dzial(dzial) 
    {
        
    }

std::string Pracownik::getDzial() const 
{
    return dzial;
}

void Pracownik::setDzial(const std::string& dzial) 
{
    this->dzial = dzial;
}

void Pracownik::wypisz() const 
{
    Osoba::wypisz();
    std::cout << "Dział: " << dzial << std::endl;
}
