// Jagodzinski Piotr zadanie Oko.
#include <iostream>
using namespace std;

int main() 
{
    int max;
    cin >> max;
    int i = 0;
    while (i < max)
    {
        i = i + 1;
        if (i % 2 == 0)
            continue;

        if (i == 21)
        {
            cout << "OKO";
            break;
        }
        cout << " i = " << i << endl;
    }
    return 0;
}