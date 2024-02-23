#include <iostream>
using namespace std;

int
main ()
{
  float h;
  float w;

  cout << "Podaj swoj wzrost (format: cenymetry): ";
  cin >> h;

  h /= 100;

  cout << "\nPodaj swoja wage (kg): ";
  cin >> w;

  float bmi = w / (h * h);

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
