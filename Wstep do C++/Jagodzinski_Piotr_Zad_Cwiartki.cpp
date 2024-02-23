// Jagodzinski Piotr zad. CWI.
#include <iostream>

int main() {
    long long x, y;
    std::cin >> x >> y;

    if (x == 0 && y == 0) 
    {
        std::cout << "0" << std::endl;
    } else if (x == 0) 
    {
        std::cout << "OY" << std::endl;
    } else if (y == 0) 
    {
        std::cout << "OX" << std::endl;
    } else if (x > 0 && y > 0) 
    {
        std::cout << "I" << std::endl;
    } else if (x < 0 && y > 0) 
    {
        std::cout << "II" << std::endl;
    } else if (x < 0 && y < 0) 
    {
        std::cout << "III" << std::endl;
    } else if (x > 0 && y < 0) 
    {
        std::cout << "IV" << std::endl;
    }

    return 0;
}