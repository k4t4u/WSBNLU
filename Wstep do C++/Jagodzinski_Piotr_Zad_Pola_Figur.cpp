#include <iostream>
using namespace std;
int main()
{
  char wybor = 't';
  double wymiar1 = 0;
  double wymiar2 = 0;
  double pole = 0;
  
  cout << "Pole jakiego rodzaju figur chcesz obliczyc? (t/k/p) " << endl;
  cout << "wpisz t jesli chcesz obliczyc pole trojkata prostokatnego " << endl;
  cout << "wpisz k jesli chcesz obliczyc pole kwadratu " << endl;
  cout << "wpisz p jesli chcesz obliczyc pole prostokata " << endl;
  cin >> wybor;

  if (wybor == 't')
  {
    cout << "Wybrales trojkat prostokatny " << endl;
    cout << "Podaj dlugosc jednej z przyprostokatnych" << endl;
    cin >> wymiar1;
    cout << "Podaj dlugosc drugiej przyprostokatnej" << endl;
    cin >> wymiar2;
    pole = (wymiar1 * wymiar2) * 0.5;
    cout << "Pole trojkata prostokatnego wynosi: " << pole << endl;
  } 
  else if (wybor == 'k')
  {
    cout << "Wybrales kwadrat " << endl;
    cout << "Podaj dlugosc boku kwadratu" << endl;
    cin >> wymiar1;
    pole = wymiar1 * wymiar1;
    cout << "Pole kwadratu wynosi: " << pole << endl;   
  }
  else if (wybor == 'p')
  {
    cout << "Wybrales prostokat " << endl;
    cout << "Podaj dlugosc boku a" << endl;
    cin >> wymiar1;
    cout << "Podaj dlugosc boku b" << endl;
    cin >> wymiar2;
    pole = wymiar1 * wymiar2;
    cout << "Pole prostokata wynosi: " << pole << endl;
  }
  else
  {
    cout<< "Nie ma takiej opcji" << endl;
	}
}