#include <iostream>
using namespace std;

int
main ()
{
  int n;
  cin >> n;

  if (n <= 50)
    {
      cout << "NDST" << endl;
    }
  else if (n <= 60)
    {
      cout << "MRN" << endl;
    }
  else if (n <= 70)
    {
      cout << "DST" << endl;
    }
  else if (n <= 80)
    {
      cout << "DB" << endl;
    }
  else if (n <= 90)
    {
      cout << "BDB" << endl;
    }
  else
    {
      cout << "CEL" << endl;
    }
}
