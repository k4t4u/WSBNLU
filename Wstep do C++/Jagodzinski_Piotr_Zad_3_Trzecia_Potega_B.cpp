#include <iostream>
#include <iomanip>

using namespace std;

int main () 
{
	
  for(int i=1; i <= 15;)
  {  
  
    cout << setw(10) << i << setw(10) << i*i << setw(10) << i*i*i;
    if (i % 2 == 0)
    {
      cout << "\tPARZYSTE!";
    }
    cout << endl;
		i++;
  }
  return 0;
}