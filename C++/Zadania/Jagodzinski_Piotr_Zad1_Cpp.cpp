#include <iostream>
#include <string>

class WartoscOceny {
    
private:
    std::string wartoscOceny;

public:
    WartoscOceny(const std::string& poczatkowaOcena = "") 
    :wartoscOceny(poczatkowaOcena) 
    {
        
    }

    static bool sprawdzPoprawnoscOceny(const std::string& ocena)
    {
        return ocena == "cel" || ocena == "bdb" || ocena == "db+" || ocena == "db" ||
               ocena == "dst+" || ocena == "dst" || ocena == "dop+" || ocena == "dop" ||
               ocena == "ndst" || ocena == "nzal";
    }

    void ustawNowaOcene(const std::string& nowaWartoscOceny) 
    {
        if (sprawdzPoprawnoscOceny(nowaWartoscOceny)) 
        {
            wartoscOceny = nowaWartoscOceny;
        } else 
        {
            std::cout << "Wprowadzona zla wartosc oceny. Poprawne wartosci to: cel, bdb, db+, db, dst+, dst, dop+, dop, ndst, nzal." << std::endl;
            std::cout << "Wprowadz poprawna wartosc: " << nowaWartoscOceny << std::endl;
        }
    }

    std::string pobierzOcene() const 
    {
        return wartoscOceny;
    }
};

class Student {
    
private:
    std::string ImieStudenta;
    std::string NazwiskoStudenta;
    std::string numerIndeksuStudenta;

public:
    Student(const std::string& imie = "", const std::string& nazwisko = "", const std::string& numerIndeksu = "")
        :ImieStudenta(imie), NazwiskoStudenta(nazwisko), numerIndeksuStudenta(numerIndeksu) 
        {
            
        }

    void wyswietlDaneStudenta() const 
    {
        std::cout << "Student: " << ImieStudenta << " " << NazwiskoStudenta << " Indeks: " << numerIndeksuStudenta << std::endl;
    }
};

class RejestrOcen {
    
private:
    static const int LIMIT_OCEN = 10;
    Student student;
    std::string listaPrzedmiotow[LIMIT_OCEN];
    WartoscOceny tablicaOcen[LIMIT_OCEN];
    int aktualnaLiczbaOcen = 0;

public:
    RejestrOcen(const Student& nowyStudent) 
    :student(nowyStudent) 
    {
        
    }

    void zarejestrujOcene(const std::string& przedmiot, const std::string& ocena) 
    {
        if (WartoscOceny::sprawdzPoprawnoscOceny(ocena) && aktualnaLiczbaOcen < LIMIT_OCEN) 
        {
            listaPrzedmiotow[aktualnaLiczbaOcen] = przedmiot;
            tablicaOcen[aktualnaLiczbaOcen] = WartoscOceny(ocena);
            aktualnaLiczbaOcen++;
            std::cout << "Dodano ocene " << ocena << " z przedmiotu " << przedmiot << std::endl;
        } else 
        {
            std::cout << "Wprowadzona zla wartosc oceny lub przekroczony limit (10) ocen. Poprawne wartosci to: cel, bdb, db+, db, dst+, dst, dop+, dop, ndst, nzal." << std::endl;
        }
    }

    void wyswietlRejestr() const 
    {
        student.wyswietlDaneStudenta();
        for (int i = 0; i < aktualnaLiczbaOcen; i++) 
        {
            std::cout << listaPrzedmiotow[i] << ": " << tablicaOcen[i].pobierzOcene() << std::endl;
        }
    }
};

int main() {
    
    Student anna("Anna", "Jakas", "12345");
    RejestrOcen rejestrAnna(anna);
    
    Student piotr("Piotr", "Ja", "54321");
    RejestrOcen rejestrPiotr(piotr);

    rejestrAnna.zarejestrujOcene("Matematyka", "db");
    rejestrAnna.zarejestrujOcene("Informatyka", "db+");
    rejestrAnna.zarejestrujOcene("Fizyka", "cel");
    rejestrAnna.wyswietlRejestr();
    std::cout << std::endl;
    
    rejestrPiotr.zarejestrujOcene("Matematyka", "cel");
    rejestrPiotr.zarejestrujOcene("Biologia", "bdb");
    rejestrPiotr.zarejestrujOcene("Geografia", "dst");
    rejestrPiotr.wyswietlRejestr();
    std::cout << std::endl;

    rejestrAnna.zarejestrujOcene("Chemia", "6.0");
    std::cout << std::endl;

    rejestrAnna.zarejestrujOcene("Biologia", "dst");
    rejestrAnna.zarejestrujOcene("Geografia", "dst+");
    rejestrAnna.zarejestrujOcene("Historia", "dop+");
    rejestrAnna.zarejestrujOcene("WOS", "dop");
    rejestrAnna.zarejestrujOcene("Muzyka", "ndst");
    rejestrAnna.zarejestrujOcene("Plastyka", "nzal");
    rejestrAnna.zarejestrujOcene("WF", "bdb");
    rejestrAnna.zarejestrujOcene("Programowanie", "dop");
    std::cout << std::endl;

    rejestrAnna.wyswietlRejestr();
    std::cout << std::endl;
    
    rejestrPiotr.wyswietlRejestr();
    std::cout << std::endl;

    return 0;
}
