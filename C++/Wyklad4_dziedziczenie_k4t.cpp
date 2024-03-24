
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
// Pracownik jest osoba, zatem moze dziedziczyc po osobie.
class Pracownik: public Osoba //":" oznacze ze pracownik dziedziczy po osobie, dzieki dziedziczeniu wszystko z klasy Osoba przeszlo do klasy Pracownik
{
    private:
        string stanowisko;
        double placa;
    public:
        Pracownik(string _imie, string _nazwisko, string _stanowisko, double _placa)
        :Osoba(_imie, _nazwisko), stanowisko(_stanowisko), placa(_placa)
        {
        }
        
        void Drukuj() const 
        {
            Osoba::Drukuj(); // to jest wywolanie funkcji Drukuj z klasy Osoba
            cout<<endl<<"Stanowisko: "<<stanowisko;
            cout<<endl<<"Placa: "<<placa<<" euro";
        }
};

int main()
{
    std::cout<<"Wyklad 4";

        Pracownik pracownik1("Jan", "Jankowski", "DevOp", 12002);
        pracownik1.Drukuj();
    return 0;
}