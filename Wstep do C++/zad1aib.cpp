//Zad. 1b. Suma
#include <iostream>
using namespace std;
int main() 
{
	int n = 0;
	long long int suma = 0;
	cin >> n;
  if (n >= 1) 
	{
    for (int i = 1; i <= n; i++)
    {
      suma = suma + i;
    }
  } 
	else 
		if (n < 1) 
		{
	    for (int i = 1; i >= n; i-- ) 
			{
	      suma = suma + i;
	    }
	  } 
  
	cout << suma;
	return 0;
}

/*



//Zad. 1a. Suma
#include <iostream>
using namespace std;
int main() 
{
  int n = 0;
  long long int suma = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    suma = suma + i;
  }
  cout << suma;
  return 0;
}
*/
