//Jagodzinski Piotr Zad. 4
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
