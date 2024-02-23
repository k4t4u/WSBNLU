//zad8. zest. 5
#include <iostream>
using namespace std;
int main()
{
	char napis[10000];
	cin >> napis;
	int i = 0;
	while (napis[i] != '\0')
	{
		if(napis[i] >= 'a' && napis[i] <= 'z')
    {
      napis[i] -= 32;
    }
		i++;
	}
  cout << napis << endl;
}
/*
//zad6. zest. 5
#include <iostream>
using namespace std;
int main()
{
	char WDP[1000] = "Wstep do programowania";
	int i = 0;
	while (WDP[i] != '\0')
	{
		i++; ccccc
	}
	cout << "Dlugosc napisu: " << i << endl;
	cout << WDP << endl;
}
//char (zakres -128 do 127)
*/
/*
//zad3. zest. 5
#include <iostream>
using namespace std;
int main()
{
    for(int i=48; i<=57; i++)
     {
         cout << char(i) << " ";
     }
    cout << endl;

  for(int i=65; i<=90; i++)
   {
       cout << char(i) << " ";
   }
  cout << endl;

  for(int i = 97; i <= 122; i++)
   {
       cout << char(i) << " ";
   }
  cout << endl;
}
*/
/*
//Zestaw 5 zad2.
#include <iostream>
using namespace std;
int main()
{g
	int k = 1;
  for(int i=32; i<127; i++)
  {
      cout << i << " - " << char(i);
      if(k % 3 == 0)
      {
        cout << endl;
      }
      else 
				cout << "\t\t";
      k++;
  }
}
*/
/*
//Zestaw 5 zad1.
#include <iostream>
using namespace std;
int main()
{
	for(int i=32; i<127; i++)
	 cout << i << " - " << char(i) << endl;
	
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	int tab[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
				tab[i][j] = (i + 11) * (j + 11);
		}
  for(int i=11; i<21; i++) 
    cout << '\t' << i;
  cout << endl;
  
	for(int i=0;i<10;i++)
	{
    cout << i+11 << '\t';
		for(int j=0;j<10;j++)
		{
			cout << tab[i][j] << "\t";	
		}
		cout << endl;
	}
}
*/
/*
#include <iostream>
using namespace std;
//Zadnie odroc elementy tablicy
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
*/
/*
//Zad. 6
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
*/

/***************************
//Rozwiązanie Pana Dominika

#include <iostream>

using namespace std;

int main()
{   
    int tablica[20];
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int najmn_w_tab = 10;
    int temp = 0;

    cin >> n;

    while (i < n)
    {   
        cin >> tablica[i];
        i++;
    }

    while (j < n)
    {
        if (tablica[j] < najmn_w_tab)
        {
           najmn_w_tab = tablica[j];
        }
        j++;
    }

    // cout << najmn_w_tab << endl;

    temp = tablica[0];

    while (k < n)
    {   
        if (tablica[k] == najmn_w_tab)
        {

            tablica[k] = temp;
        }

        tablica[0] = najmn_w_tab;

        cout << tablica[k] << " ";
        k++;


    }
    return 0;
}

*********************/
/*
//Zad. 5
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
*/

/*
//Zad. 4
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

  for(int i = 0; i < n; i++) 
  {
     tablica[i] = rand() % 101 ; 
  }
	
	for (int i=0;i<n;i++) {
		cout << tablica[i] << " ";
	}
	cout << endl;
  
}
*/
/*
//Zad. 3
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


*/
/*
//zad 2 Deklaracja tablicy
#include <iostream>
using namespace std;
int main() 
{
  int tablica[] = {3, 5, 7, 8, 9};

  for(int i = 0; i < 5; i++)
  {
    cout << tablica[i] << ", ";
  }
  cout << endl;
}
*/