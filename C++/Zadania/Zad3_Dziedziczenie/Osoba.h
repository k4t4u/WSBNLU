#ifndef OSOBA_H
#define OSOBA_H
#include <string>

class Osoba 
{
protected:
    std::string imie;
    int wiek;
    static int licznik;

public:
    Osoba(const std::string& imie, int wiek);
    virtual ~Osoba();

    std::string getImie() const;
    void setImie(const std::string& imie);

    int getWiek() const;
    void setWiek(int wiek);

    virtual void wypisz() const;

    static int getLicznik();
};

#endif // OSOBA_H
