#include "Osoba.h"
#include <iostream>

int Osoba::licznik = 0;

Osoba::Osoba(const std::string& imie, int wiek) : imie(imie), wiek(wiek) 
{
    licznik++;
}

Osoba::~Osoba() 
{
    licznik--;
}

std::string Osoba::getImie() const 
{
    return imie;
}

void Osoba::setImie(const std::string& imie) 
{
    this->imie = imie;
}

int Osoba::getWiek() const 
{
    return wiek;
}

void Osoba::setWiek(int wiek) 
{
    this->wiek = wiek;
}

void Osoba::wypisz() const 
{
    std::cout << "Imię: " << imie << ", Wiek: " << wiek << std::endl;
}

int Osoba::getLicznik() 
{
    return licznik;
}
