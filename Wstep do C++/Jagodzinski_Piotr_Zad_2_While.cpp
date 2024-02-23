//Zad 2. while
#include <iostream>

using namespace std;
int main()
{
  int liczba, i = 1;
  cin >> liczba;
  while(i <= liczba)
	{
    if (liczba % i == 0){
      cout << i << endl;
    }
    i++;
  }
  return 0;
}