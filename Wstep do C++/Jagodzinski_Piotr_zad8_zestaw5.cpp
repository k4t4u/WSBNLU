//Jagodzinski Piotr
//zad8. zest. 5
#include <iostream>
using namespace std;
int main()
{
	char napis[10000];
	cin >> napis;
	int i = 0;
	while (napis[i] != '\0')
	{
		if(napis[i] >= 'a' && napis[i] <= 'z')
    {
      napis[i] -= 32;
    }
		i++;
	}
  cout << napis << endl;
}