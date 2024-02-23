//Jagodzinski Piotr
#include <iostream>
using namespace std;
void wczytaj(int *tab, int n)
{
	for(int i=0; i<n; i++)
	{
			cin >> tab[i];
	}
}
void odwroc(int *tab, int n)
{
	int tmp;
	for(int i=0; i < n/2; i++)
	{
		tmp = tab[i];
		tab[i] = tab[n-1-i];
		tab[n-1-i] = tmp;
	}

	// int i = 0;
	// int j = n-1;
	// while(i < j)
	// {
	// 	tmp = tab[i];
	// 	tab[i] = tab[j];
	// 	tab[j] = tmp;
	// 	i++;
	// 	j--;
	// }
}

void wypisz(int *a, int n ) {
  for(int i=0; i<n; i++)
  {
      cout << a[i] << " ";
  }
  cout << endl;
}

int main()
{
	int n;
	cin >> n;
	int tab[n];
	wczytaj(tab, n);
	odwroc(tab, n);
	wypisz(tab, n);
}