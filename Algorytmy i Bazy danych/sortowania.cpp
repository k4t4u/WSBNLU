#include <iostream> //dla cout
#include <cstdlib> //dla f. rand, srand
#include <ctime> //dla f. time, clock
#include <utility> //dla f. swap
using namespace std;

void printTab(int [], int); //Funkcja drukująca elmenty tablicy
void genTabInc(int [], int); //Generator tablicy-liczby w porządku rosnącym
void genTabDec(int [], int); //Generator tablicy-liczby w porządku malejęcym
void genTabRand(int [], int); //Generator tablicy-liczby pseudolosowe
int linearSearch(int [], int, int); //Algorytm wyszukiwania liniowego zwraca indeks szukanego elementu
int binarySearch(int tab[], int, int); //Algorytm wyszukiwania binarnego - iteracja
int binarySearchRec(int [], int, int, int); //Algorytm wyszukiwania binarnego - rekurencja
void bubbleSort(int [], int); //Algorytm sortowania bąbelkowego
void bubbleSort2(int [], int); //Algorytm sortowania bąbelkowego - eliminacja pustych przebiegów
void insertSort(int [], int); //Algorytm sortowania przez wstawianie
void selectSort(int [], int); //Algorytm sortowania przez wybieranie
void selectSort2(int [], int); //Algorytm sortowania przez wybieranie - sprawdza, czy potrzeba wykonać swap
void quickSortRec(int [], int, int); //Algorytm sortowania szybkiego - rekurencja
void shellSort(int [], int); //Algorytm sortowania metodą Shella

int main()
{
    int n = 10000, x = 10;
    clock_t t;
    double ts;
    int tab[n];
    srand(time(NULL)); //Generator liczb pseudolosowych
    cout<<"Wyszukiwanie i sortowanie tablicy:\n";
    //genTabInc(tab, n);
    //printTab(tab, n);
    genTabRand(tab, n);
    //genTabDec(tab, n);
    //insertSort(tab, n);
    //selectSort(tab, n);
    //printTab(tab, n);
    //selectSort2(tab, n);
    //quickSortRec(tab, 0, n - 1);
    //shellSort(tab, n);
    //printTab(tab, n);
    //return 0;
    t = clock();
    bubbleSort(tab, n);
    t = clock() - t;
    ts = ((double)t)/CLOCKS_PER_SEC;
    cout << "bubbleSort: " << ts << "s\n";
    genTabRand(tab, n);
    //genTabDec(tab, n);
    t = clock();
    bubbleSort2(tab, n);
    t = clock() - t;
    ts = ((double)t)/CLOCKS_PER_SEC;
    cout << "bubbleSort2: " << ts << "s\n";
    
    genTabRand(tab, n);
    //genTabDec(tab, n);
    t = clock();
    insertSort(tab, n);
    t = clock() - t;
    ts = ((double)t)/CLOCKS_PER_SEC;
    cout << "insertSort: " << ts << "s\n";
    genTabRand(tab, n);
    //genTabDec(tab, n);
    t = clock();
    selectSort(tab, n);
    t = clock() - t;
    ts = ((double)t)/CLOCKS_PER_SEC;
    cout << "selectSort: " << ts << "s\n";
    genTabRand(tab, n);
    //genTabDec(tab, n);
    t = clock();
    selectSort2(tab, n);
    t = clock() - t;
    ts = ((double)t)/CLOCKS_PER_SEC;
    cout << "selectSort2: " << ts << "s\n";
    
    genTabRand(tab, n);
    //genTabDec(tab, n);
    t = clock();
    quickSortRec(tab, 0, n-1);
    t = clock() - t;
    ts = ((double)t)/CLOCKS_PER_SEC;
    cout << "quickSortRec: " << ts << "s\n";
    genTabRand(tab, n);
    //genTabDec(tab, n);
    t = clock();
    shellSort(tab, n);
    t = clock() - t;
    ts = ((double)t)/CLOCKS_PER_SEC;
    cout << "shellSort: " << ts << "s\n";
    //printTab(tab, n);
    //cout<<"start\n";
    //cout<<"linearSearch: "<<linearSearch(tab, n, x)<<"\nstop\n";
    //cout << "binarySearch: " << binarySearch(tab, n, x) << "\n";
    //cout << "binarySearchRec: " << binarySearchRec(tab, 0, n-1, x) << "\n";

    return 0;
}

void printTab(int tab[], int n)
{
    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
}

void genTabInc(int tab[], int n)
{
    for(int i=0; i<n; i++)
        tab[i] = i;
}

void genTabDec(int tab[], int n)
{
    for(int i=n - 1; i>= 0; i--)
        tab[i] = n - i - 1;
}

void genTabRand(int tab[], int n)
{
    for(int i=0; i<n; i++)
        tab[i] = rand()%n;
}

int linearSearch(int tab[], int n, int x)
{
    for(int i=0; i<n; i++)
        if(tab[i]==x) //Jeśli element szukany został znaleziony
            return i;

    return -1; //Jeśli szukany element nie został znaleziony
}

int binarySearch(int tab[], int n, int x)
{
	int left = 0;
	int right = n - 1;
 
	while (left <= right)
	{
		int indMid = left + (right - left) / 2;
		if (tab[indMid] == x)
			return indMid;
		if (tab[indMid] < x)
			left = indMid + 1;
		else
			right = indMid - 1;
	}
 
	return -1;
}

int binarySearchRec(int tab[], int left, int right, int x)
{
    if(left <= right)
    {
        int indMid = (left + right) / 2;
        if(tab[indMid] == x)
            return indMid; //Element został znaleziony
        if(tab[indMid] > x)
            return binarySearchRec(tab, left, indMid - 1, x);
        
        return binarySearchRec(tab, indMid + 1, right, x);
    }
    
    return -1; //Brak szukanego elementu
}

void bubbleSort(int tab[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(tab[j] > tab[j+1])
            {
                swap(tab[j], tab[j+1]);
            }
        }
    }
}

void bubbleSort2(int tab[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(tab[j] > tab[j+1])
            {
                swap(tab[j], tab[j+1]);
                swapped = true; //Jeśli nastąpiła zamiana
            }
        }
        if(!swapped)
            return; //Jeśli nie nastąpiła zamiana w ostatnio wykonanej iteracji
    }
}

void insertSort(int tab[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > key)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }
}

void selectSort(int tab [], int n)
{
    for(int i = 0; i < n; i++)
    {
        int indMin = i;
        for(int j = i + 1; j < n; j++)
            if(tab[indMin] > tab[j])
                indMin = j;
        
        swap(tab[indMin], tab[i]);
    }
}

void selectSort2(int tab [], int n)
{
    for(int i = 0; i < n; i++)
    {
        int indMin = i;
        for(int j = i + 1; j < n; j++)
            if(tab[indMin] > tab[j])
                indMin = j;
        if(indMin != i)
            swap(tab[indMin], tab[i]);
    }
}

void quickSortRec(int tab[], int left, int right)
{
    int i = left, j = right;
    int pivot = tab[(left + right) / 2]; //Wybór elementu osiowego
    while(i <= j)
    {
        while(tab[i] < pivot)
            i++;
        
        while(tab[j] > pivot)
            j--;
            
        if(i <= j)
            swap(tab[i++], tab[j--]);
    }
    if(i < right)
        quickSortRec(tab, i, right);
    if(j > left)
        quickSortRec(tab, left, j);
}

void shellSort(int tab[], int n)
{
    for(int d = n / 2; d > 0; d /= 2)
    {
        for(int i = d; i < n; i++)
        {
            int element = tab[i];
            int j;
            for(j = i; j >= d && tab[j - d] > element; j -= d)
                tab[j] = tab[j - d];
                
            tab[j] = element;
        }
    }
}
