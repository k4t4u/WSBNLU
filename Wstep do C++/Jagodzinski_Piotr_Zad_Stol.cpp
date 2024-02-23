//Jagodzinski Piotr Zad. Stol
#include <iostream>
 
using namespace std;
 
 
 
int iloscKrzesel(int a, int b, int k);
int main ()
{
	int bokStoluA, bokStoluB, wymiarKrzesla;
 
    cin>>bokStoluA>> bokStoluB>>wymiarKrzesla;
	   if(bokStoluA > bokStoluB)
	   {
	   	cout<<iloscKrzesel(bokStoluA, bokStoluB, wymiarKrzesla);
	   }
	   else
	   {
	   	cout<<iloscKrzesel(bokStoluB, bokStoluA, wymiarKrzesla);
	   }
	   cin.sync();
	cin.get();
 
	return 0;
}
int iloscKrzesel(int a,int  b,  int k)
{
    int ileKrzesel = 0;
 if(b >= k)
 {
	ileKrzesel = a / k;
 }
   if ( b >= 2 * k)
   {
   	      ileKrzesel = ileKrzesel * 2;
   }
	if (b >= 3* k)
	{
	   b = b - (k *2);
	   b = b / k;
	   b = b *2;		
	}
	else
	{
		b = 0;
	}
	ileKrzesel = ileKrzesel + b;
 
	return ileKrzesel;
}