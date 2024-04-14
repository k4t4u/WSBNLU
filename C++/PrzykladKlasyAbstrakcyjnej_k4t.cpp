
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
/* Zakladamy ze w naszej firmie nie ma umow jakotakich sa tylko konkretne umowy: autorskie lub zlecenie.
    Zatem niepotrzebujemy tworzyc obiektow klasy Umowa.
*/
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
            dataWystawienia.Drukuj();
            cout<<endl<<"Data waznosci od: ";
            dataOd.Drukuj();
            cout<<endl<<"Data waznosci do: ";
            dataDo.Drukuj();
            cout<<endl<<"Wartosc: "<<wartosc;
            cout<<endl<<"Podatek: "<<ObliczPodatek();
            cout<<endl;
            
        }
  /* Ponadto niewiemy jak oblizcyc podatek umowy, wiemy za to jak ObliczPodatek dla UmowaZlecenie lub UmowaAutorska. 
        Jak niewiemy jak napisac funkcje w klasie podstawoej a wiemy jak napisac ja w klasie dziedziczacej to w klasie podstawowej powinnabyc abstrakcyjna(przyrownana do 0, wirtualna i bez bloku)
            Jezeli klasa ma w sobie conajmniej jedna funkcje abstrakcyjna to jest tez abstrakcyjna. A klasa Umowa zawiera jedna funkcje abstrakcyjna, wiec jest to klasa abstrakcyjna.
  */
        virtual double ObliczPodatek() const =0;
        
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
    /* Klasa umowa jes abstrakcyjna, niewolno tworzyc obiektow klasy abstrakcyjnej.
            zatem niewolno tworzyc obietkow klasy Umowa
                I dobrze bo niepotrzebujemy w firmie umow.
    Umowa u("Umowa 1", 1,1,2001,1,1,2001,2,2,2020,1000);
    u.DrukujUmowe();
    */
    
    UmowaZlecenie uz("Umowa zlecenie 2", 2,2,2022, 2,2,2022, 2,2,2200, 2222);
    uz.DrukujUmowe();
    
    UmowaAutorska ua("Umowa autorska 3", 3,3,2003, 3,3,2003, 3,3,2023, 3333);
    ua.DrukujUmowe();

    return 0;
}