#include <iostream>
using namespace std;
/* Klasa abstrakcyjna: 
                        Funkcja czysto wirtualna inaczej abstrakcyjna to taka ktora:
                            - Ma "virtual" z przodu.
                            - Nie ma bloku.
                            - Jest porownana do 0.
                            - Np. virtual void pokaz()=0;
                            
                        Klasa abstrakcyjna to taka ktora ma conajmniej jedna fukncje abstrakcyjna.
                        Nie da sie tworzyc obiektu klasy abstrakcyjnej. 


    Zakladamy ze w naszej firmie nie ma samochodow jakotakich beda tylko konkretne samochody: osobowe, ciezarowe itp. Wtedy tworzenie ObliczSpalanieNaTrasie i ObliczAmortyzacjeNaTrasie jest bez sensu bo niewiemy ile spala i amortyzuje jako taki samochod.
  Wtedy klasa Samochod mozebyc abstrakcyjna bo niebedziemy tworzyc jej obiektow.
  Funkcje ObliczSpalanieNaTrasie i ObliczAmortyzacjeNaTrasie rowniez mogabyc abstrakcyjne a mawet musza bo niewiemy jak je napisac w samochodzie.
  Funkcje abstrakcyjne stanowia "obietnice ze zostana zrealizowane w klasach dziedziczacych".
*/  

// Klasa Samochod zawiera conajmniej jedna funkcje abstrakcyjna (dwie) wiec jest abstrakcyjna.
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
        // To sa Funkcje abstrakcyjne.
        virtual double ObliczSpalanieNaTrasie(double liczbaKilometrow)=0;
        virtual double ObliczAmortyzacjeNaTrasie(double liczbaKilometrow)=0;
};

class SamochodOsobowy:public Samochod
{
    public:
        SamochodOsobowy(double spalanie, double amortyzacja)
        :Samochod(spalanie,amortyzacja)
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
    
    /* Niewolno tworzyc obietkow klasy abstrakcyjnej.
    Samochod s1(7, 10);
    t.WykonajTrase(s1, 1000);
    */
    
    SamochodOsobowy so1(10, 20);
    t.WykonajTrase(so1, 1000);
    
    SamochodCiezarowy sc1(30, 120, 5500, 3000);
    t.WykonajTrase(sc1, 1000);
    
    t.Wyswietl();
    return 0;
}
