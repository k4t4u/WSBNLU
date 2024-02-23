// Jagodzinski Piotr zad. Czas
#include <iostream>

int main() 
{
    int t;
    std::cin >> t;

    int godziny = t / 3600;
    int minuty = (t % 3600) / 60;
    int sekundy = t % 60;

    std::cout << godziny << "h" << minuty << "m" << sekundy << "s" << std::endl;

    return 0;
}
