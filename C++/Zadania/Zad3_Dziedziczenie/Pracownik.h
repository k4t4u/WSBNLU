#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "Osoba.h"

class Pracownik : public Osoba 
{
protected:
    std::string dzial;

public:
    Pracownik(const std::string& imie, int wiek, const std::string& dzial);

    std::string getDzial() const;
    void setDzial(const std::string& dzial);

    void wypisz() const override;
};

#endif // PRACOWNIK_H
