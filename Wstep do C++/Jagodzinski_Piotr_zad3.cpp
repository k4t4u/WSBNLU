//Jagodzinski Piotr Zad. 3
#include <iostream>
using namespace std;
int main()
{
	int n;
  cin >> n;
  int tablica[100]; //zgodne ze specyfikacją języka
	//int tablica[n];
  //int *tab = new int[n]; //tablica dynamiczna

	//wczytanie liczb do tablicy
  for (int i=0;i<n;i++) {
    cin >> tablica[i];
  }

	
  for (int i=0;i<n;i++) {
    cout << tablica[i] << " ";
  }

  cout << endl;