//Jagodzinski Piotr
#include <iostream>
#include <string>

std::string szyfrCezara(std::string tresc, int zmiana, bool szyrf) 
{
    if (!szyrf) 
    {
        zmiana = 26 - zmiana;
    }
    
    for (char &c : tresc) 
    {
        if (isalpha(c)) 
        {
            char baza = islower(c) ? 'a' : 'A';
            c = (c - baza + zmiana) % 26 + baza;
        }
    }
    return tresc;
}

int main() 
{
    int akcja, zmiana;
    std::string tresc;
    std::cin >> akcja;
    std::cin >> zmiana;
    std::cin.ignore();
    std::getline(std::cin, tresc);
    
    std::cout << szyfrCezara(tresc, zmiana, akcja == 1) << std::endl;
    return 0;
}