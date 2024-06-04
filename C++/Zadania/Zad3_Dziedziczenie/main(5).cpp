#include <iostream>
#include "Osoba.h"
#include "Student.h"
#include "Pracownik.h"
#include "Nauczyciel.h"

int main() 
{
    Student* student = new Student("Pjoter", 34, "Informatyka");
    student->wypisz();
    std::cout << std::endl;

    Pracownik* pracownik = new Pracownik("Anna", 33, "Zasoby Ludzkie");
    pracownik->wypisz();
    std::cout << std::endl;

    Nauczyciel* nauczyciel = new Nauczyciel("Marianna", 25, "Matematyka", "Statystyka");
    nauczyciel->wypisz();
    std::cout << std::endl;

    std::cout << "Liczba osób: " << Osoba::getLicznik() << std::endl;

    delete student;
    delete pracownik;
    delete nauczyciel;

    std::cout << "Liczba osób po usunięciu: " << Osoba::getLicznik() << std::endl;

    return 0;
}
