// Jagodzinski Piotr zadanie dzielniki.
#include <iostream>
using namespace std;

int main()
{
  int n = 0;
  int p = 2;
  cin >> n;
  cout << n << "=";
  while( n > 1 )
  {
    while( n % p == 0)
    {
      cout << p;
      n/=p;
      if (n != 1) cout << "*";
    }
    p++;
  }
  cout << endl;
}