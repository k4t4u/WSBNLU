#include <iostream>
using namespace std;
void printTab(int [], int);
void buildHeap(int [], int n, int i); //Budowanie kopca w tablicy
void heapSort(int [], int); //Sortowanie przez kopcowanie

int main()
{
    cout << "Sortowanie przez kopcowanie\n";
    
    int tab[] = {9, 6, 5, 6, 1, 7, 2, 4, 3, 5, 7, 7, 9, 6};
    int n = sizeof(tab)/sizeof(int); // lub sizeof(tab)/sizeof(*tab)

    //Wyświetla tablicę wejściową.
    cout << "Tablica nieposortowana: ";
    printTab(tab, n);

    // Sortuje tablicę algorytmem przez kopcowanie.
    heapSort(tab, n);

    //Wyświetla posortowaną tablicę.
    cout << "Tablica posortowana: ";
    printTab(tab, n);

    return 0;
}

void printTab(int tab[], int n)
{
    for(int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
}

void buildHeap(int tab[], int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < n && tab[left] > tab[max])
        max = left;
 
    if (right < n && tab[right] > tab[max])
        max = right;
 
    if (max != i)
    {
        swap(tab[i], tab[max]);
        buildHeap(tab, n, max);
    }
}

void heapSort(int tab[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        buildHeap(tab, n, i);
 
    for (int i = n - 1; i > 0; i--)
    {
        swap(tab[0], tab[i]);
        buildHeap(tab, i, 0);
    }
}