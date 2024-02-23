// Jagodzinski Piotr zad. Krol
#include <iostream>

int main() {
    char kolumna;
    int wiersz;
    std::cin >> kolumna >> wiersz;

    int mozliwePola = 8;

    if (kolumna == 'a' || kolumna == 'h') mozliwePola -= 3;
    if (wiersz == 1 || wiersz == 8) mozliwePola -= 3;
    if ((kolumna == 'a' || kolumna == 'h') && (wiersz == 1 || wiersz == 8)) mozliwePola += 1;

    std::cout << mozliwePola << std::endl;

    return 0;
}
