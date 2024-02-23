//zad. 7. ostry czy rozwarty
#include <iostream>
using namespace std;
int main() 
{
	int kat;
  cin >> kat;

  if (kat > 0 && kat < 90) 
  {
      cout << "ostry" << endl;
  } 
  else if (kat == 90) 
  {
      cout << "prosty" << endl;
  } 
  else if (kat > 90 && kat < 180) 
  {
      cout << "rozwarty" << endl;
  }
  return 0;
}
  
//

/*
//pola figur
#include <iostream>
using namespace std;
#include <iostream>
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
*/
/*
// Zad. 5. Funkcja kwadratowa
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double a, b, c, delta, pierwiastek;

  cout << "Podaj kolejno wspolczynniki wielomianu kwadratowego" << endl;
  cin >> a >> b >> c;

  delta = (b * b) - (4 * a * c);

  if (delta < 0)
    cout << "Rownanie nie ma miejsc zerowych" << endl;

  if (delta == 0) {
    double x;
    x = -b / (2 * a);
    cout << "Rownanie ma jedno miejsce zerowe: " << fixed << setprecision(2) << x <<endl;
  }

  if (delta > 0) {
    double x1, x2;
    pierwiastek = sqrt(delta);
    x1 = (-b - pierwiastek) / (2 * a);
    x2 = (-b + pierwiastek) / (2 * a);
    cout << "Rownanie ma dwa rozwiazania w punktach x=" << fixed << setprecision(2) << x1 << " i   x=" << x2
         << endl;
  }
  return 0;
}
*/
/*
// Zad. 4 WMC
#include <iostream>
using namespace std;

int main()
{
  float h;
  float w;

  cout << "Podaj swoj wzrost (format: cenymetry): ";
  cin >> h;

  h = h / 100;// h /= 100;

  cout << "\nPodaj swoja wage (kg): ";
  cin >> w;

  float bmi = w / (h*h);

  cout << "Twoj wspolczynnik bmi wynosi: " << bmi;

  if (bmi < 19)
  {
    cout << "\n i wskazuje niedowage";
  }
  else if (bmi >= 19 && bmi < 25)
  {
    cout << "\n i wskazuje wage w normie";
  }
    else if (bmi >= 25 && bmi < 30)
  {
    cout << "\n i wskazuje nadwage";
  }
  else if (bmi >= 30)
  {
    cout << "\n i wskazuje otylosc";
  }
  return 0;
}
*/

/*
//Zadanie oceny
#include <iostream>
 using namespace std;

int main()
{
  int n;
  cin >> n;

    if (n <= 50)
    {
      cout << "NDST" << endl;
    }
    else if (n <= 60)
    {
      cout << "MRN" << endl;
    }
    else if (n <= 70)
    {
      cout << "DST" << endl;
    }
    else if (n <= 80)
    {
      cout << "DB" << endl;
    }
    else if (n <= 90)
    {
      cout << "BDB" << endl;
    }
    else
    {
      cout << "CEL" << endl;
    }
}
*/