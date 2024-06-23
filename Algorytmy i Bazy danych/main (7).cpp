#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap
{
    public:
        BinaryHeap(); //Konstruktor
        bool isEmpty(); //Sprawdza, czy kolejka priorytetowa jest pusta
        void insert(int key); //Wstawia nowy element do kolejki priorytetowej
        int extractMax(); //Pobiera element najwyższego rzędu przed usunięciem go z kolejki priorytetowej
        int getMax(); //Pobiera element najwyższego rzędu

    private:
        vector<int> vect;
        int size;

        //Pomocnicze funkcje nawigacyjne
        int parent(int i)
        {
            return i / 2; //Przesunięcie bitowe i >> 1
        }
        int left(int i)
        {
            return 2 * i; //Przesunięcie bitowe i << 1
        }
        int right(int i)
        {
            return 2 * i + 1; //Przesunięcie bitowe (i << 1) + 1
        }

        void shiftUp(int index);
        void shiftDown(int i);
};

int main()
{
    cout << "Kopiec binarny - kolejka priorytetowa\n";
    
    //Instancjonuje kolejkę priorytetową.
    BinaryHeap *priqueue = new BinaryHeap();

    //Sprawdza, czy kolejka priorytetowa jest pusta.
    //Powinno zwrócić TRUE.
    cout << "Czy kolejka jest pusta? ";
    bool b = priqueue->isEmpty();
    if(b)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl;

    //Wstawia nowy element.
    priqueue->insert(3);
    cout << "Wstawia 3 do kolejki" << endl;

    //Ponownie prawdza, czy kolejka priorytetowa jest pusta - powinno zwrócić FALSE.
    cout << "Czy kolejka jest pusta? ";
    b = priqueue->isEmpty();
    if(b)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl;

    //Wstawia inne elementy.
    priqueue->insert(43);
    priqueue->insert(13);
    priqueue->insert(21);
    cout << "Wstawia 43, 13 i 28 do kolejki";
    cout << endl;

    //Sprawdza największy element - powinien mieć wartość 43.
    cout << "getMax() = ";
    cout << priqueue->getMax();
    cout << endl;

    //Usuwa największy element.
    cout << "extractMax() = ";
    cout << priqueue->extractMax();
    cout << endl;

    //Sprawdza największy element - powinien mieć wartość 21.
    cout << "getMax() = ";
    cout << priqueue->getMax();
    cout << endl;
    
    return 0;
}

BinaryHeap::BinaryHeap()
{
    //Czyszczenie wektora
    vect.clear();

    //Korzeń będzie miał indeks 1, więc ustawiamy indeks 0 jako „obojętny”
    vect.push_back(-1);

    //Pusty kopiec binarny nie zawiera żadnych elementów
    size = 0;
}

bool BinaryHeap::isEmpty()
{
    //Kopiec jest pusty, jeśli size = 0
    return size == 0;
}

void BinaryHeap::shiftUp(int index)
{
    //Nie robi niczego z korzeniem
    if(index == 1)
        return;

    if(vect[index] > vect[parent(index)])
    {
        //Zamienia elementy pozycjami
        swap(vect[index], vect[parent(index)]);

        //Wywołuje się rekurencyjne aż do korzenia
        shiftUp(parent(index));
    }
}

void BinaryHeap::insert(int key)
{
    //Dodaje nowy element do wektora
    if (size + 1 >= (int)vect.size())
        vect.push_back(0);

    //Zapisuje klucz w ostatniej pozycji wektora
    vect[++size] = key;

    //Przenosi element w górę
    shiftUp(size);
}

void BinaryHeap::shiftDown(int index)
{
    //Nic nie robi, jeśli podany indeks nie istnieje
    if(index > size)
        return;

    //Inicjalizuje swapId
    int swapId = index;

    //Porównuje z lewym dzieckiem, o ile istnieje
    if (left(index) <= size && vect[index] < vect[left(index)])
        swapId = left(index);

    //Porównuje z prawym dzieckiem, o ile istnieje
    if (right(index) <= size && vect[swapId] < vect[right(index)])
        swapId = right(index);

    //Zamienia miejsca z większym z dwojga dzieci
    if (swapId != index)
    {
        //Zamienia pozycje z większym z dwojga dzieci
        swap(vect[index], vect[swapId]);

        //Wywołuje się rekurencyjnie aż do indeksu
        shiftDown(swapId);
    }
}

int BinaryHeap::extractMax()
{
    //Największa wartość znajduje się w korzeniu
    int maxVal = vect[1];

    //Zamienia miejscami z ostatnim istniejącym liściem
    std::swap(vect[1], vect[size--]);

    //Poprawie strukturę kopca w dół
    shiftDown(1);

    //Zwraca największą wartość
    return maxVal;
}

int BinaryHeap::getMax()
{
    //Zwraca klucz korzenia
    return vect[1];
}