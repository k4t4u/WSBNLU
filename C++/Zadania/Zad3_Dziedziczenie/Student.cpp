#include "Student.h"
#include <iostream>

Student::Student(const std::string& imie, int wiek, const std::string& kierunek) 
    : Osoba(imie, wiek), kierunek(kierunek) 
    {
        
    }

std::string Student::getKierunek() const 
{
    return kierunek;
}

void Student::setKierunek(const std::string& kierunek) 
{
    this->kierunek = kierunek;
}

void Student::wypisz() const 
{
    Osoba::wypisz();
    std::cout << "Kierunek: " << kierunek << std::endl;
}
