#ifndef CZARODZIEJ_H
#define CZARODZIEJ_H
#include "Postac.h"

class Czarodziej : public Postac 
{
private:
    int mana;

public:
    Czarodziej(string n, int pz, int s, int w, int m);
    void atak(Postac &przeciwnik) override;
};

#endif // CZARODZIEJ_H