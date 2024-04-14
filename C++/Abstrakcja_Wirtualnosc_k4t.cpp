
#include <iostream>
using namespace std;

class Data
{
    private:
        int dzien;
        int miesiac;
        int rok;
    
    public:
        Data(int dzien, int miesiac, int rok)
        :dzien(dzien), miesiac(miesiac), rok(rok)
        {
            
        }
        
        void Drukuj() const
        {
            cout<<dzien<<"."<<miesiac<<"."<<rok;
        }
};

class Umowa
{
    private:
        string numerUmowy;
        Data dataWystawienia;
        Data dataOd;
        Data dataDo;
        
    protected:
        double wartosc;
        
    public:
        Umowa(string numerUmowy, 
        int dzienWystawienia, int miesiacWystawienia, int rokWystawienia, 
        int dzienOd, int miesiacOd, int rokOd,
        int dzienDo, int miesiacDo, int rokDo,
        double wartosc)
        :numerUmowy(numerUmowy), 
        dataWystawienia(dzienWystawienia, miesiacWystawienia, rokWystawienia), 
        dataOd(dzienOd, miesiacOd, rokOd), 
        dataDo(dzienDo, miesiacDo, rokDo), 
        wartosc(wartosc)
        {
            
        }
        
    void DrukujUmowe()const
        {
            cout<<endl<<"<<<==Umowa==>>>";
            cout<<endl<<"Numer: "<<numerUmowy;
            cout<<endl<<"Data wystawienia: ";
            dataWystawienia.Drukuj();// To jest wywolanie metody drukuj z klasy Data
            cout<<endl<<"Data waznosci od: ";
            dataOd.Drukuj();
            cout<<endl<<"Data waznosci do: ";
            dataDo.Drukuj();
            cout<<endl<<"Wartosc: "<<wartosc;
            cout<<endl<<"Podatek: "<<ObliczPodatek();
            cout<<endl;
            
        }
    /*  Funkcja ObliczPodatek jest wirtualna dlatego ze:
            Gdyby niebyla wirtualna to w DrukujUmowe, ObliczPodatek wywolywalo by sie zawsze  z klasy Umowa.
            Dzieki wirutalnosci tej funkcji funkcja DrukujUmowe bedzie uzywac dla kazdej klasy swoja funkcje ObliczPodatek(dla typu).
    */
        virtual double ObliczPodatek() const
        {
            return 0;
        }
};


class UmowaZlecenie: public Umowa
{
    public:
        UmowaZlecenie (string numerUmowy, 
        int dzienWystawienia, int miesiacWystawienia, int rokWystawienia, 
        int dzienOd, int miesiacOd, int rokOd,
        int dzienDo, int miesiacDo, int rokDo,
        double wartosc)
        :Umowa(numerUmowy, dzienWystawienia, miesiacWystawienia, rokWystawienia, dzienOd, miesiacOd, rokOd, dzienDo, miesiacDo, rokDo, wartosc)
        {
            
        }
        
        double ObliczPodatek() const
        {
            return wartosc * 20 / 100;
        }
};

class UmowaAutorska: public Umowa
{
    
    public:
        UmowaAutorska(string numerUmowy, 
        int dzienWystawienia, int miesiacWystawienia, int rokWystawienia, 
        int dzienOd, int miesiacOd, int rokOd,
        int dzienDo, int miesiacDo, int rokDo,
        double wartosc)
        :Umowa(numerUmowy, dzienWystawienia, miesiacWystawienia, rokWystawienia, dzienOd, miesiacOd, rokOd, dzienDo, miesiacDo, rokDo, wartosc)
        {
            
        }
        
    double ObliczPodatek() const
    {
        return (wartosc/2) * 20 / 100;
    }
};


int main()
{
    std::cout<<"Wyklad 7"<<endl;
    
    Umowa u("Umowa 1", 1,1,2001,1,1,2001,2,2,2020,1000);
    u.DrukujUmowe();
    
    UmowaZlecenie uz("Umowa zlecenie 2", 2,2,2022, 2,2,2022, 2,2,2200, 2222);
    uz.DrukujUmowe();
    
    UmowaAutorska ua("Umowa autorska 3", 3,3,2003, 3,3,2003, 3,3,2023, 3333);
    ua.DrukujUmowe();

    return 0;
}