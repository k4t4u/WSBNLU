#include <iostream>
#include <map> //dla klasy szablonowej map
using namespace std;

template <typename T>
struct Node
{
    Node(T value); //Konstruktor
    T value; //Pole na przechowywanie danych
    Node<T> *next; //Wskaźnik do następnego elementu
};

template <typename T>
class MyQueue
{
    public:
        MyQueue(); //Konstruktor
        void enqueue(T element); //Wstawianie elementu na koniec kolejki
        T dequeue(); //Zwracanie elementu z początku kolejki
        void showQueue(); //Wypisanie wszystkich elementów kolejki
        bool isEmpty(); //Sprawdza, czy kolejka jest pusta
    private:
        Node<T> *front; //Początek kolejki
        Node<T> *back; //Koniec kolejki
        int size; //Aktualna liczba elementów w kolejce
};

void printTab(int [], int);
void radixSort(int [], int); //Sortowanie pozycyjne

int main()
{
    cout << "Sortowanie pozycyjne\n";
    int tab[] = {7, 3, 5, 0, 1, 6, 21, 5, 9, 8, 7, 13};
    int n = sizeof(tab) / sizeof(int); //Obliczenie liczby elementów, można też tak sizeof(tab) / sizeof(*tab)
    cout << "n = " << n;
    cout << "Tablica wejściowa: ";
    printTab(tab, n);
    radixSort(tab, n); //Wywołanie funkcji sortowania przez zliczanie
    cout << "Tablica posortowana: ";
    printTab(tab, n);
    
    return 0;
}

template <typename T> Node<T>::Node(T value) : value(value), next(NULL)
{
    cout << "Tworzę obiekt typu Node ...\n";
}

template <typename T> MyQueue<T>::MyQueue() : front(NULL), back(NULL), size(0)
{
    cout << "Tworzę obiekt typu MyQueue ...\n";
}

template <typename T> void MyQueue<T>::enqueue(T element)
{
    Node<T> *node = new Node<T>(element); //Tworzenie nowego węzła przechowującego element
    if(!size) //Jeśli kolejka jest pusta
    {
        node->next = NULL;
        front = node;
        back = front; //Jeden element w kolejce jest jej początkiem i końcem
    }
    else
    {
        back->next = node;
        back = node; //Nowy węzeł staje się ostatnim elementem w kolejce
    }

    size++;
}

template <typename T> T MyQueue<T>::dequeue()
{
    if(!size) //Jeśli kolejka jest pusta
        throw invalid_argument("Kolejka jest pusta!\n");
    
    Node<T> *tmpNode = front;
    T tmpValue = tmpNode->value;
    front = front->next; //Przesuwanie początku kolejki;
    delete tmpNode; //Usuwanie elementu kolejki z pamięci
    size--;
    
    return tmpValue;
}

template <typename T> void MyQueue<T>::showQueue()
{
    if(size) //Jeśli kolejka jest pusta
    {
        Node<T> *tmpNode = front;
        do
        {
            cout << tmpNode->value << "<-";
            tmpNode = tmpNode->next;
        }
        while(tmpNode != NULL);
        cout << endl;
    }
}

template <typename T> bool MyQueue<T>::isEmpty()
{
    return size == 0; //Zwraca TRUE, jeśli kolejka jest pusta
}

void printTab(int tab [], int n)
{
    for(int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
}

void radixSort(int tab[], int n)
{
   //Tworzy dziesięć pojemników na cyfry (0 - 9)
   MyQueue<int> * buckets = new MyQueue<int>[10];
   //Wyszukuje największy element.
   int largestElement = tab[0];
   for(int i = 0; i < n; i++)
   {
      if(largestElement < tab[i])
         largestElement = tab[i];
   }
 
   //Iteruje po każdej cyfrze, używając wartości wykładniczej (10^exp).
   for(int exp = 1; largestElement / exp > 0; exp *= 10)
   {
      //Iteruje po elementach tablicy.
      for(int i = 0; i < n; i++)
      {
         // Przenosi element do odpowiedniego pojemnika.
         buckets[(tab[i] / exp) % 10].enqueue(tab[i]);
      }
 
      //Odtwarza tablicę, zaczynając od najmniejszej cyfry w pojemnikach.
      //Wyzerowuje licznik przed odtworzeniem tablicy.
      int arrCounter = 0;
      for(int i = 0; i < 10; i++)
      {
         // Pobiera wszystkie elementy z pojemników.
         while(!buckets[i].isEmpty())
            //Pobiera element z przodu, umieszcza go w tablicy i usuwa z kolejki.
            tab[arrCounter++] = buckets[i].dequeue();
      }
   }
   
   delete [] buckets; //Usuwanie 10 kolejek
}