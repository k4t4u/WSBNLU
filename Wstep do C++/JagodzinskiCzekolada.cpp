#include <iostream>
// Jagodzinski
 int main() {
     int w1, k1, w2, k2;
 
     std::cout << "Wprowadz ilosc kostek czekolady. Odpowiadajacej kolejnosci: pierwsza liczba to ilosc kostek w pionie druga ilosc kostek w poziomie Antka. Trzecia liczba to ilosc kostek w pionie i czwarta to ilosc kostek w poziomie Zuzi.";
     while (true) {
         std::cin >> w1 >> k1 >> w2 >> k2;
         
         if (w1 >= 1 && w1 <= 100 && k1 >= 1 && k1 <= 100 && w2 >= 1 && w2 <= 100 && k2 >= 1 && k2 <= 100) {
             break;
         } else {
             std::cout << "Zle dane wejsciowe. Wprowadz liczbe od 1 do 100.";
         }
     }
    
     int totalSquares = w1 * k1 + w2 * k2;
    
     std::cout << "Kostek lacznie: " << totalSquares << std::endl;

     return 0;
}