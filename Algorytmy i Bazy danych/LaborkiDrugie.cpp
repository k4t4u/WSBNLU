#include <iostream>
#include <cstdlib> //dla rand i srand
#include <ctime> //dla time
using namespace std;

void printTab(int [], int); //Drukowanie tablicy liczb
void genTabSorted(int [], int); //Geneorwanie tablicy kolejnych liczb
void genTabRand(int [], int); //Geneorwanie liczb pseudolosowych - tylko funkcja rand()
int linearSearch(int [], int, int); //Algorytm wyszukiwania liniowego - zwraca indeks szukanego elementu
void bubbleSort(int [], int); //Algorytm sortowania bąbelkowego

int main()
{
    int n = 10000, x = 3;
    srand(time(0)); //Inicjalizacja generatora liczb pseudolosowych
    int tab[n];
    //printTab(tab, n);
    //genTabSorted(tab, n);
    genTabRand(tab, n);
    cout << "start" << endl;
    //printTab(tab, n);
    //cout << "Wyszukiwanie elementu.\n";
    //cout << "linearSearch: " << linearSearch(tab, n, x);
    bubbleSort(tab, n);
    cout << "stop";
    //printTab(tab, n);

    return 0;
}

void printTab(int tab[], int n)
{
    for(int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
}

void genTabSorted(int tab[], int n)
{
    for(int i = 0; i < n; i++)
        tab[i] = 1 + i;
}

void genTabRand(int tab[], int n)
{
    for(int i = 0; i < n; i++)
        tab[i] = rand() % n + 1; //Generowanie liczb pseudolosowych od 1 do n
}

int linearSearch(int tab[], int n, int x)
{
    for(int i = 0; i < n; i++)
        if(tab[i] == x) //Jeśli element został został znaleziony na i-tej pozycji
            return i;

    return -1; //Jeśli element nie został został znaleziony
}

void bubbleSort(int tab[], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = n - 1; j > i; j--)
        {
            if(tab[j - 1] > tab[j]) //Należy dokonać zamiany
                swap(tab[j - 1], tab[j]); //Zamia miejscami sąsiednich elementów
        }
}
