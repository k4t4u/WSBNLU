#include "Nauczyciel.h"
#include <iostream>

Nauczyciel::Nauczyciel(const std::string& imie, int wiek, const std::string& dzial, const std::string& przedmiot) 
    : Pracownik(imie, wiek, dzial), przedmiot(przedmiot) 
    {
        
    }

std::string Nauczyciel::getPrzedmiot() const 
{
    return przedmiot;
}

void Nauczyciel::setPrzedmiot(const std::string& przedmiot) 
{
    this->przedmiot = przedmiot;
}

void Nauczyciel::wypisz() const 
{
    Pracownik::wypisz();
    std::cout << "Przedmiot: " << przedmiot << std::endl;
}
