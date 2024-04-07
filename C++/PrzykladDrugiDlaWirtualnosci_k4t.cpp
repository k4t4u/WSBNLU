#include <iostream>
using namespace std;

class Samochod
{
    protected:
        double spalanie;
        double amortyzacja;
        
    public:
        Samochod(double spalanie, double amortyzacja)
        :spalanie(spalanie), amortyzacja(amortyzacja)
        {
            
        }
        // te funkcje sa wirtualne bo w klasie transport jest funkcja WykonajTrase ktora jako parametr dostaje jako referencje na Samochod. Gdyby te funkcje byly bez virtual to w klasie Transport ObliczSpalanieNaTrasie i ObliczAmortyzacjeNaTrasie funkcji WykonajTrase wywowylawy by sie zawsze z klasy samochod.
        // W funkcji w klasie WykonajTrase wywouja sie z tego samochod z ktorego typu rzeczywiscie jest obiekt (dla SamochodCiezarowy z SamochodCiezarowy a dla SamochodOsobowy z SamochodOsobowy)
        virtual double ObliczSpalanieNaTrasie(double liczbaKilometrow) 
        {
            return 0;
        }
        
        virtual double ObliczAmortyzacjeNaTrasie(double liczbaKilometrow)
        {
            return 0;
        }
};

class SamochodOsobowy:public Samochod
{
    public:
        SamochodOsobowy(double spalanie, double amortyzacja)
        :Samochod(spalanie,amortyzacja) // wywoluje konstruktor z klasy Samochod.
        {
            
        }
        
        double ObliczSpalanieNaTrasie(double liczbaKilometrow)
        {
            return liczbaKilometrow*spalanie/100;
        }
        
        double ObliczAmortyzacjeNaTrasie(double liczbaKilometrow)
        {
            return liczbaKilometrow*amortyzacja/100;
        }
};

class SamochodCiezarowy:public Samochod
{
    private:
        double ladownoscNaczepy;
        double ladownoscPrzyczepy;
        
    public:
        SamochodCiezarowy(double spalanie, double amortyzacja, double ladownoscNaczepy, double ladownoscPrzyczepy)
        :Samochod(spalanie, amortyzacja), ladownoscNaczepy(ladownoscNaczepy), ladownoscPrzyczepy(ladownoscPrzyczepy)
        {
            
        }
        
        double ObliczSpalanieNaTrasie(double liczbaKilometrow)
        {
            return liczbaKilometrow*(spalanie*ladownoscNaczepy/100+ladownoscPrzyczepy/100)/100;
        }
        
        double ObliczAmortyzacjeNaTrasie(double liczbaKilometrow)
        {
            return liczbaKilometrow*(amortyzacja+2*ladownoscNaczepy/100+3*ladownoscPrzyczepy/100)/100;
        }
};

class Transport
{
    private:
        double kosztyPaliwaFirmy;
        double kosztyAmortyzacjiFirmy;
        
    public:
        Transport()
        {
            kosztyPaliwaFirmy = 0;
            kosztyAmortyzacjiFirmy = 0;
        }
    
    void WykonajTrase(Samochod& s, double liczbaKilometrow)
    {
        kosztyPaliwaFirmy+=s.ObliczSpalanieNaTrasie(liczbaKilometrow)*7;
        kosztyAmortyzacjiFirmy+=s.ObliczAmortyzacjeNaTrasie(liczbaKilometrow);
    }
    
    void Wyswietl()const
    {
        cout<<endl<<"Koszty paliwa w firmie: "<<kosztyPaliwaFirmy<<"$";
        cout<<endl<<"Koszty amortyzacji w firmie: "<<kosztyAmortyzacjiFirmy<<"$";
    }
};

int main()
{
    std::cout<<endl<<"Wyklad 6";
    std::cout<<endl<<"Przyklad wirtualnosci";
    Transport t;
    
    Samochod s1(7, 10);
    t.WykonajTrase(s1, 1000);
    
    SamochodOsobowy so1(10, 20);
    t.WykonajTrase(so1, 1000);
    
    SamochodCiezarowy sc1(30, 120, 5500, 3000);
    t.WykonajTrase(sc1, 1000);
    
    t.Wyswietl();
    return 0;
}
