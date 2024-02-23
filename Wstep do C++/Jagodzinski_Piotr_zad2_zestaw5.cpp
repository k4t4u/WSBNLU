//Jagodzinski Piotr
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
