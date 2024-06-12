#include "Rycerz.h"
#include <cstdlib>

Rycerz::Rycerz(string n, int pz, int s, int w)
:Postac(n, pz, s, w) 
{
    
}

void Rycerz::atak(Postac &przeciwnik)
{
    int obrazenia = sila + (rand() % 10);
    przeciwnik.obrona(obrazenia);
    cout << getNazwa() << " atakuje " << przeciwnik.getNazwa() << " i zadaje " << obrazenia << " obrazen.\n";
}
