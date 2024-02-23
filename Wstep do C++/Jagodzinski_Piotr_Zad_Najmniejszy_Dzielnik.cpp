// Jagodzinski Piotr zadanie Najmniejszy dzielnik.

#include <iostream>
using namespace std;

int main() {
    int wczytanaLiczba;
    cin >> wczytanaLiczba;

    for (int i = 2; i * i <= wczytanaLiczba; i++) 
    {
    if (wczytanaLiczba % i) 
        {
            continue;
        } else 
        {
            cout << i;
            return 0;
        }
    }
    cout << wczytanaLiczba;
return 0;
}
