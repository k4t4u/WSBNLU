#include "Czarodziej.h"
#include <cstdlib>

Czarodziej::Czarodziej(string n, int pz, int s, int w, int m)
:Postac(n, pz, s, w), mana(m) 
{
    
}

void Czarodziej::atak(Postac &przeciwnik) 
{
    int obrazenia = sila + (rand() % 15);
    if (mana > 0) 
    {
        obrazenia += mana / 2;
        mana -= 10;
    }
    przeciwnik.obrona(obrazenia);
    cout << getNazwa() << " atakuje " << przeciwnik.getNazwa() << " i zadaje " << obrazenia << " obrazen. Mana: " << mana << ".\n";
}
