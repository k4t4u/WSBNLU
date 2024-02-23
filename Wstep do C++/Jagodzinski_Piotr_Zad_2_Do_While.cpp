//Zad 3. do while
#include <iostream>
using namespace std ;

int main (){

  int i = 1;
  int liczba ;

  cin >> liczba;

  do
  {
    if ( liczba % i == 0 )
      cout << i << endl;
    i++;
  } while( i <= liczba);
  return 0;
}