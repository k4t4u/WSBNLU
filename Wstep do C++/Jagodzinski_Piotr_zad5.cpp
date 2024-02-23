//Jagodzinski Piotr Zad. 5
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
	
	//for (int i=0; i<n; i++) 
	//{
	//	cout << tablica[i] << " ";
	//}
	//cout << endl;

  int max = tablica[0];

  for (int i=0;i<n;i++)
    if (tablica[i] > max)
    {
      max = tablica[i];
    }
	cout << max;  
	
}