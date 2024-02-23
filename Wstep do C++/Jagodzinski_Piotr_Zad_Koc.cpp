// Jagodzinski Piotr zadanie Koc.

#include<iostream>
using namespace std;

int main()
{
    int bokA, bokB;
    cin >> bokA >> bokB;

    while (bokA % 2 == 0) 
    {
        bokA = bokA / 2;
    }

    while (bokB % 2 == 0) 
    {
        bokB = bokB / 2;
    }

    int powierzchnia = bokA * bokB;

    cout << powierzchnia << endl;

    return 0;
}