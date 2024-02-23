// Jagodzinski Piotr ikrementacja.
#include <iostream>
using namespace std;

int main()
{
  int i;

  cin >> i;

  switch (i)
    {
      case 1:
      case 2:
        {
          cout << "zima";
          break;
        }
      case 3 ... 5:
        {
          cout << "wiosna";
          break;
        }
      case 6 ... 8:
        {
          cout << "lato";
          break;
        }
      case 9 ... 11:
        {
          cout << "jesień";
          break;
        }
      case 12:
        {
          cout << "zima";
          break;
        }
    }
  
}
