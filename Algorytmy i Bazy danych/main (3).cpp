#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    Node(T value); //Konstruktor
    T value; //Pole na przechowywanie danych
    Node<T> *next; //Wskaźnik do następnego elementu
};

template <typename T> Node<T>::Node(T value) : value(value), next(NULL)
{
    cout << "Tworzę obiekt typu Node ...\n";
}

template <typename T>
class MyQueue
{
    public:
        MyQueue(); //Konstruktor
        void enqueue(T element); //Wstawianie elementu na koniec kolejki
        T dequeue(); //Zwracanie elementu z początku kolejki
        void showQueue(); //Wypisanie wszystkich elementów kolejki
    private:
        Node<T> *front; //Początek kolejki
        Node<T> *back; //Koniec kolejki
        int size; //Aktualna liczba elementów w kolejce
};

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

int main()
{
    cout<<"Kolejka (FIFO)\n";
    
    cout << "Tworzenie kolejki do przechowywania elementów typu int ...\n"; 
    MyQueue<int> mq1;
    cout << "Elementy kolejki:\n";
    mq1.showQueue();
    
    cout << "Dodanie elementu do kolejki ...\n";
    mq1.enqueue(2);
    cout << "Elementy kolejki:\n";
    mq1.showQueue();
    
    cout << "Dodanie kolejnych elementów do kolejki ...\n";
    mq1.enqueue(3);
    mq1.enqueue(5);
    mq1.enqueue(7);
    mq1.enqueue(11);
    cout << "Elementy kolejki:\n";
    mq1.showQueue();
    
    cout << "Usuwanie elementu z kolejki ...\n";
    cout << mq1.dequeue() << endl;
    cout << "Elementy; kolejki:\n";
    mq1.showQueue();
    
    cout << "Usuwanie pozostałych elementów z kolejki ...\n";
    cout << mq1.dequeue() << endl;
    cout << mq1.dequeue() << endl;
    cout << mq1.dequeue() << endl;
    cout << mq1.dequeue() << endl;
    cout << "Elementy kolejki:\n";
    mq1.showQueue();
    
    cout << "Usuwanie elementu z pustej kolejki ...\n";
    try
    {
        cout << mq1.dequeue() << endl;
    }
    catch(invalid_argument ex)
    {
        cout << "Błąd: " << ex.what() << endl;
    }
    cout << "Elementy kolejki:\n";
    mq1.showQueue();
    
    cout << "Tworzenie kolejki do przechowywania elementów typu string ...\n"; 
    MyQueue<string> mq2;
    cout << "Elementy kolejki:\n";
    mq2.showQueue();
    
    cout << "Dodanie elementu do kolejki ...\n";
    mq2.enqueue("Ala");
    cout << "Elementy kolejki:\n";
    mq2.showQueue();
    
    cout << "Dodanie kolejnych elementów do kolejki ...\n";
    mq2.enqueue("ma");
    mq2.enqueue("kota");
    mq2.enqueue("Kot");
    mq2.enqueue("lubi Alę.");
    cout << "Elementy kolejki:\n";
    mq2.showQueue();
    
    cout << "Usuwanie elementu z kolejki ...\n";
    cout << mq2.dequeue() << endl;
    cout << "Elementy kolejki:\n";
    mq2.showQueue();
    
    cout << "Usuwanie pozostałych elementów z kolejki ...\n";
    cout << mq2.dequeue() << endl;
    cout << mq2.dequeue() << endl;
    cout << mq2.dequeue() << endl;
    cout << mq2.dequeue() << endl;
    cout << "Elementy kolejki:\n";
    mq2.showQueue();
    
    cout << "Usuwanie elementu z pustej kolejki ...\n";
    try
    {
        cout << mq2.dequeue() << endl;
    }
    catch(invalid_argument ex)
    {
        cout << "Błąd: " << ex.what() << endl;
    }
    cout << "Elementy kolejki:\n";
    mq2.showQueue();
    
    return 0;
}