#include <iostream>
#include <cmath>
using namespace std;
void hanoiRec(int n, int x, int z);

int main()
{
    int n = 10, x = 1, z = 3; //y = 6 - x - z
    cout << "Problem wież Hanoi dla n = " << n << endl;
    hanoiRec(n, x, z);
    cout << "Minimalna liczba kroków = " << pow(2, n) - 1 << ", dla n = " << n << endl;
  
    return 0;
}

void hanoiRec(int n, int x, int z)
{
  if(n == 1)
    cout << "Dysk nr " << n << " -> " << z << endl;
  else
  {
    hanoiRec(n-1, x, 6 - x - z);
    cout << "Dysk nr " << n << " -> " << z << endl;
    hanoiRec(n-1, 6 - x - z, z);
  }
}
