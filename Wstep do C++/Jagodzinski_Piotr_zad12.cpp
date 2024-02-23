//Jagodzinski Piotr
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
