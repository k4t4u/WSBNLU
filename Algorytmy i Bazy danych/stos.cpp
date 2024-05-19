#include <iostream>
using namespace std;
enum stackState {EMPTY, OK, FULL};

class MyStack
{
    public:
        MyStack(int); //Konstruktor klasy MyStack
        ~MyStack(); //Destruktor klasy MyStack
        void push(int); //Połóż element na stosie
        int pop(); //Zdejmij element ze stosu
    private:
        int* numbers;
        int maxSize;
        int top;
        stackState state;
};

MyStack::MyStack(int maxSize)
{
    cout<<"Tworzenie stosu ...\n";
    numbers = new int[maxSize];
    this->maxSize = maxSize;
    top = 0;
    state = EMPTY; 
}

MyStack::~MyStack()
{
    cout<<"Usuwanie stosu ...\n";
    delete [] numbers;
}

void MyStack::push(int element)
{
    if(state != FULL)
        numbers[top++] = element;
    else
        cout<<"Stos jest pełny!\n";
    if(top == maxSize)
        state = FULL;
    else
        state = OK;
}

int MyStack::pop()
{
    int element;
    if(state != EMPTY)
        element = numbers[--top];
    else
        throw invalid_argument("Stos jest pusty!\n");
    if(top == 0)
        state = EMPTY;
    else
        state = OK;
    
    return element;
}

int main()
{
    cout<<"Stos liczb.\n";
    MyStack st(3);
    st.push(3);
    st.push(5);
    cout<<st.pop()<<endl;
    st.push(7);
    st.push(2);
    st.push(13);
    try {
        cout<<st.pop()<<endl<<st.pop()<<endl<<st.pop();
        cout<<st.pop()<<endl;
    }
    catch(invalid_argument e)
    {
        cout << "\nProblem " << e.what() << "\n";
    }
    st.push(2);
    st.push(13);
    st.push(2);
    st.push(13);
    return 0;
}

