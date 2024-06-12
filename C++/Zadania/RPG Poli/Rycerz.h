#ifndef RYCERZ_H
#define RYCERZ_H
#include "Postac.h"

class Rycerz : public Postac 
{
public:
    Rycerz(string n, int pz, int s, int w);
    void atak(Postac &przeciwnik) override;
};

#endif // RYCERZ_H