#include <iostream>
using namespace std;
void printTab(int [], int);
void countSort(int [], int); //Sortowanie przez zliczanie

int main()
{
    cout << "Sortowanie przez zliczanie\n";
    int tab[] = {7, 3, 5, 0, 1, 6, 2, 5, 9, 8, 7};
    int n = sizeof(tab) / sizeof(int); //Obliczenie liczby elementów, można też tak sizeof(tab) / sizeof(*tab)
    cout << "n = " << n;
    cout << "Tablica wejściowa: ";
    printTab(tab, n);
    countSort(tab, n); //Wywołanie funkcji sortowania przez zliczanie
    cout << "Tablica posortowana: ";
    printTab(tab, n);
    
    return 0;
}

void printTab(int tab [], int n)
{
    for(int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
}

void countSort(int tab[], int n)
{
    int countSize = 10;
    int *countTab = new int[countSize]; //Pomocnicza tablica zliczająca liczbę wystąpień elementów z przedziału [0,9]
    for(int i = 0; i < n; i++)
        countTab[i] = 0; //Zerowanie tablicy
    
    for(int i = 0; i < n; i++)
        ++countTab[tab[i]]; //Zwiększenie licznika
        
    int tabCounter = 0; //Licznik do iterowania po tablicy sortowanej
    for(int i = 0; i < countSize; i++)
        while(countTab[i] > 0)
        {
            tab[tabCounter++] = i; //Zwracanie elementu do listy
            --countTab[i]; //Zmiejszenie licznika
        }

    delete [] countTab; //Usuwanie tablicy zliczającej z pamięci
}