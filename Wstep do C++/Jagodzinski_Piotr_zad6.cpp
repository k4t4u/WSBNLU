//Jagodzinski Piotr Zad. 6
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));

	int n;
 	cin >> n;
	int tablica[n];

	//for(int i = 0; i < n; i++) 
	//{
	//	 tablica[i] = rand() % 101 - 50 ; 
	//}

	//wczytanie liczb do tablicy
	for (int i = 0; i < n; i++) 
	{
		cin >> tablica[i];
	}
	
  int i = 0;
	int indeks_min = 0;
  while (i < n)
  {
      if (tablica[i] < tablica[indeks_min])
      {
        indeks_min = i;
      }
		i++;
  }
  //zamiana el
  int temp = tablica[0];
  tablica[0] = tablica[indeks_min];
  tablica[indeks_min] = temp;

	for (int i=0; i<n; i++) 
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}