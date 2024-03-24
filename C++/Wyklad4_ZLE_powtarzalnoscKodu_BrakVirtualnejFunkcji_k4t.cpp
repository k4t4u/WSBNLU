
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
        
        double DochodyRoczne()
        {
            return 0;
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
        
        double DochodyRoczne()
        {
            return placaBrutto*12;
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
        
        double DochodyRoczne()
        {
            return liczbaGodzin*stawkaGodzinowa;
        }
};

class Ksiegowosc
{
    public:
        void DrukujPit(Pracownik& p)
        {
            cout<<endl;
            cout<<endl<<"PIT 11";
            cout<<endl<<"Dane podatnika: ";
            p.Drukuj();
            cout<<endl<<"Dochody roczne podatnika: "<<p.DochodyRoczne();
        }
        void DrukujPit(PracownikEtatowy& p)
        {
            cout<<endl;
            cout<<endl<<"PIT 11";
            cout<<endl<<"Dane podatnika: ";
            p.Drukuj();
            cout<<endl<<"Dochody roczne podatnika: "<<p.DochodyRoczne();
        }
        void DrukujPit(PracownikGodzinowy& p)
        {
            cout<<endl;
            cout<<endl<<"PIT 11";
            cout<<endl<<"Dane podatnika: ";
            p.Drukuj();
            cout<<endl<<"Dochody roczne podatnika: "<<p.DochodyRoczne();
        }
};

int main()
{
        cout<<"Wyklad 5";
        
        Ksiegowosc Ksiegowosc;

        Pracownik pracownik1("Jan", "Jankowski", "DevOps");
        Ksiegowosc.DrukujPit(pracownik1);
        cout<<endl;
        
        PracownikEtatowy pracownikEtatowy2("Janusz", "Januszewski", "Frontas", 650);
        Ksiegowosc.DrukujPit(pracownikEtatowy2);
        cout<<endl;

        PracownikGodzinowy pracownikGodzinowy3("Janusz", "Trzeci", "Bakus", 400, 200);
        Ksiegowosc.DrukujPit(pracownikGodzinowy3);
        
    return 0;
}