
#include <iostream>
using namespace std;

class Osoba
{
    private:
        string imie;
        string nazwisko;
    
    public:
        Osoba(string imie, string nazwisko)
        :imie(imie), nazwisko(nazwisko)
            {
            }
            
        void Drukuj() const
        {
            cout<<endl<<"Imie i nazwisko: "<<imie<<" "<<nazwisko;
        }
};

class Pracownik: public Osoba 
{
    private:
        string stanowisko;
    public:
        Pracownik(string imie, string nazwisko, string stanowisko)
        :Osoba(imie, nazwisko), stanowisko(stanowisko)
        {
        }
        
        void Drukuj() const 
        {
            Osoba::Drukuj();
            cout<<endl<<"Stanowisko: "<<stanowisko;
        }
};

class PracownikEtatowy: public Pracownik
{
    private:
        double placaBrutto;
        
    public:
        PracownikEtatowy(string imie, string nazwisko, string stanowisko, double placaBrutto)
        :Pracownik(imie, nazwisko, stanowisko), placaBrutto(placaBrutto)
        {
            
        }
        
        void Drukuj()const
        {
            Pracownik::Drukuj();
            cout<<endl<<"Placa brutto: "<<placaBrutto;
        }
};

class PracownikGodzinowy: public Pracownik
{
    private:
        double liczbaGodzin;
        double stawkaGodzinowa;
    
    public:
        PracownikGodzinowy(string imie, string nazwisko, string stanowisko, double liczbaGodzin, double stawkaGodzinowa)
        :Pracownik(imie, nazwisko, stanowisko), liczbaGodzin(liczbaGodzin), stawkaGodzinowa(stawkaGodzinowa)
        {
            
        }
        
        void Drukuj() const
        {
            Pracownik::Drukuj();
            cout<<endl<<"Liczba godzin: "<<liczbaGodzin;
            cout<<endl<<"Stawka godzinowa: "<<stawkaGodzinowa;
        }
        
        double ObliczWynagrodzenie()
        {
            return liczbaGodzin*stawkaGodzinowa;
        }
};

int main()
{
    std::cout<<"Wyklad 4";

        Pracownik pracownik1("Jan", "Jankowski", "DevOps");
        pracownik1.Drukuj();
        cout<<endl;
        
        PracownikEtatowy pracownikEtatowy2("Janusz", "Januszewski", "Frontas", 650);
        pracownikEtatowy2.Drukuj();
        cout<<endl;

        PracownikGodzinowy pracownikGodzinowy3("Janusz", "Trzeci", "Bakus", 400, 200);
        pracownikGodzinowy3.Drukuj();
        cout<<endl<<"Wynagrodzenie: "<<pracownikGodzinowy3.ObliczWynagrodzenie();
    return 0;
}