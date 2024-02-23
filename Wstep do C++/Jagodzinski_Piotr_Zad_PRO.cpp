//Jagodzinski Piotr
#include <iostream>

int main() 
{
    int x, y, z;
    std::cin >> x >> y >> z;

    int objetosc = x * y * z;
    int powierzchnia = 2 * (x * y + y * z + x * z);

    std::cout << objetosc << std::endl;
    std::cout << powierzchnia << std::endl;

    return 0;
}