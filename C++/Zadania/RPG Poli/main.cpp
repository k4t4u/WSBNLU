#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Postac.h"
#include "Rycerz.h"
#include "Czarodziej.h"
using namespace std;

void zapiszPostacieDoPliku(const Postac& p1, const Postac& p2, const string& nazwaPliku, bool append = false) 
{
    ofstream plik;
    if (append) 
    {
        plik.open(nazwaPliku, ios_base::app);
    } else 
    {
        plik.open(nazwaPliku);
    }
    if (plik.is_open()) 
    {
        plik << p1 << "\n" << p2 << "\n";
        plik.close();
    }
}

void pojedynek(Postac &p1, Postac &p2) 
{
    while (p1.czyZyje() && p2.czyZyje()) 
    {
        p1.atak(p2);
        if (!p2.czyZyje()) 
        {
            cout << p1.getNazwa() << " zabil przeciwnika!\n\n";
            return;
        }

        p2.atak(p1);
        if (!p1.czyZyje()) 
        {
            cout << p2.getNazwa() << " zabil przeciwnika!\n\n";
            return;
        }
      
      cout << "Stan: " << p1.getNazwa() << ": " << p1 << ", " << p2.getNazwa() << ": " << p2 << "\n\n";
    }
}

int main() 
{
    srand(static_cast<unsigned int>(time(0)));

    Rycerz rycerz("Hercules", 100, 20, 15);
    Czarodziej czarodziej("Zeus", 80, 15, 10, 50);

    cout << "Przed walką:\n" << rycerz << "\n" << czarodziej << "\n";
    zapiszPostacieDoPliku(rycerz, czarodziej, "postacie.txt");

    pojedynek(rycerz, czarodziej);

    cout << "Po walce:\n" << rycerz << "\n" << czarodziej << "\n";
    zapiszPostacieDoPliku(rycerz, czarodziej, "postacie.txt", true);

    return 0;
}
