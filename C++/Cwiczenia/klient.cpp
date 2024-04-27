#include <iostream>
using namespace std;

class Klient{
public:
    string imie;
    string nazwisko;
    string adres;
    string telefon;
};

void Wypisz(const Klient & k){
    cout << "Klient:" << endl;
    cout << "\tImie: " << k.imie << endl;
    cout << "\tNazwisko: " << k.nazwisko << endl;
    cout << "\tAdres: " << k.adres << endl;
    cout << "\tTelefon: " << k.telefon << endl;
}

void Wczytaj(Klient *k){
    cout << "Podaj imie: ";
    cin >> k->imie;
    cout << "Podaj nazwisko: ";
    cin >> k->nazwisko;
    cout << "Podaj adres: ";
    cin.ignore();
    getline(cin, k->adres);
    cout << "Podaj telefon: ";
    cin >> k->telefon;
}

void Wczytaj(Klient & k){
    cout << "Podaj imie: ";
    cin >> k.imie;
    cout << "Podaj nazwisko: ";
    cin >> k.nazwisko;
    cout << "Podaj adres: ";
    cin.ignore();
    getline(cin, k.adres);
    cout << "Podaj telefon: ";
    cin >> k.telefon;
}




int main(){
    //Klient k;
    //Wczytaj(&k);
    //Wypisz(k);
    //Wczytaj(*k);
    //Wypisz(k);

    Klient * l = new Klient;
    Wczytaj(l);
    Wypisz(*l);
    delete l;
}

/* Wersja bez powtarzalnosci kodu
 *
 * #include <iostream>
using namespace std;

class Klient{
public:
  string imie;
  string nazwisko;
  string adres;
  string telefon;
};

void Wypisz(const Klient & k){
  cout << "Klient:" << endl;
  cout << "\tImie: " << k.imie << endl;
  cout << "\tNazwisko: " << k.nazwisko << endl;
  cout << "\tAdres: " << k.adres << endl;
  cout << "\tTelefon: " << k.telefon << endl;
}

void Wczytaj(Klient *k){
  cout << "Podaj imie: ";
  cin >> k->imie;
  cout << "Podaj nazwisko: ";
  cin >> k->nazwisko;
  cout << "Podaj adres: ";
  cin.ignore();
  getline(cin, k->adres);
  cout << "Podaj telefon: ";
  cin >> k->telefon;
}

void Wczytaj(Klient & k){
  Wczytaj(&k)
}
// void Wczytaj(Klient & k){
//   cout << "Podaj imie: ";
//   cin >> k.imie;
//   cout << "Podaj nazwisko: ";
//   cin >> k.nazwisko;
//   cout << "Podaj adres: ";
//   cin.ignore();
//   getline(cin, k.adres);
//   cout << "Podaj telefon: ";
//   cin >> k.telefon;
// }




int main(){
  //Klient k;
  //Wczytaj(&k);
  //Wypisz(k);
  //Wczytaj(*k);
  //Wypisz(k);

  Klient * l = new Klient;
  Wczytaj(l);
  Wypisz(*l);
  delete l;
}


 */