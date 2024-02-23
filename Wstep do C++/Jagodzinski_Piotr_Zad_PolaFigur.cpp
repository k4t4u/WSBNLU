// Jagodzinski Piotr zadanie obliczenia pola.
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    double a, b, c, h, r;

    char choice = 'N';

    cout << fixed << setprecision(2);

    do
    {
        cout << "Wybierz bryle: \n";
        cout << "S lub s - szescian\n";
        cout << "P lub p - prostopadloscian\n";
        cout << "W lub w - walec\n";
        cout << "K lub k - kula\n";
        cin >> choice;

        switch (choice)
        {
        case 's':
        case 'S':
            cout << "Podaj dlugosc krawedzi szescianu: " << endl;
            cin >> a;
            cout << "Pole wynosi 6*a^2: " << 6 * a * a << endl;
            cout << "Objetosc wynosi a^3: " << a * a * a << endl;
            break;
        case 'p':
        case 'P':
            cout << "Podaj dlugosc pierwszej krawedzi prostopadloscianu: " << endl; 
            cin >> a; cout << "Podaj dlugosc pierwszej krawedzi prostopadloscianu: " << endl; 
            cin >> b; cout << "Podaj dlugosc pierwszej krawedzi prostopadloscianu: " << endl; 
            cin >> c; cout << "Pole P=2ab+2ac+2bc wynosi: " << 2 * a * b + 2 * b * c + 2 * a * c << endl; 
            cout << "Objetosc V=a*b*c wynosi: " << a * b * c << endl; 
            break; 
            case 'w': 
            case 'W': cout << "Podaj dlugosc promienia podstawy walca: " << endl; 
            cin >> r; cout << "Podaj wysokosc walca: " << endl; 
            cin >> h;
            cout << "Pole P=2πrh + 2πr² wynosi: " << 2 * M_PI * r * h + 2 * M_PI * r * r << endl; 
            cout << "Objetosc V=2πr²h wynosi: " << 2 * M_PI * r * r * h << endl; 
            break;

        case 'k':
        case 'K':
            cout << "Podaj dlugosc promienia : " << endl;
            cin >> r;
            cout << "Pole P=4πr² wynosi: " << 4 * M_PI * r * r << endl;
            cout << "Objetosc V= V = 4/3 πr³ wynosi: " << 4 / 3 * M_PI * r * r * r << endl; 
            break;
        }
        cout << endl;

        cout << "Czy powtorzyc operacje? (T/N)";
        cin >> choice;
    } while (choice != 'N' && choice != 'n');

    return 0;
}