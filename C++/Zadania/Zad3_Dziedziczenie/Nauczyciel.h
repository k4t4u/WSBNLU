#ifndef NAUCZYCIEL_H
#define NAUCZYCIEL_H

#include "Pracownik.h"

class Nauczyciel : public Pracownik 
{
protected:
    std::string przedmiot;

public:
    Nauczyciel(const std::string& imie, int wiek, const std::string& dzial, const std::string& przedmiot);

    std::string getPrzedmiot() const;
    void setPrzedmiot(const std::string& przedmiot);

    void wypisz() const override;
};

#endif // NAUCZYCIEL_H
