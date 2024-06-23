#include <iostream>

using namespace std;
//Węzeł drzewa binarnego
struct BTN
{
    int key;
    BTN *left;
    BTN *right;
};

BTN *addBTN(int); //Funkcja tworząca nowy węzeł struktury BTN
void printBT(BTN*); //Funkcja drukująca drzewo od wskazanego miejsca

int main()
{
    cout << "Drzewo binarne\n";
    BTN *root = NULL;
    cout << "Sadzenie drzewa\n";
    printBT(root);
    cout << endl;
    
    cout << "Wzrost drzewa\n";
    root = addBTN(100); //Dodanie korzenia
    printBT(root);
    cout << endl;
    
    root->left = addBTN(200); //Dodanie lewego potomka korzenia
    root->right = addBTN(300); //Dodanie prawego potomka korzenia
    printBT(root);
    cout << endl;
    
    root->left->left = addBTN(201); //Dodanie lewego potomka lewego potomka korzenia
    root->left->right = addBTN(202); //Dodanie prawego potomka lewego potomka korzenia
    printBT(root);
    cout << endl;
    
    root->right->left = addBTN(301); //Dodanie lewego potomka prawego potomka korzenia
    root->right->right = addBTN(302); //Dodanie prawego potomka prawego potomka korzenia
    printBT(root);
    cout << endl;
    
    printBT(root->left); //Drukowanie lewej części poddrzewa binarnego
    cout << endl;
    
    printBT(root->right); //Drukowanie prawej części poddrzewa binarnego
    cout << endl;
    
    return 0;
}

BTN *addBTN(int key)
{
    BTN *node = new BTN; //Tworzenie nowego węzła
    node->key = key; //Przypisanie klucza
    //Inicjalizacja wskaźników lefti i right
    node->left = NULL;
    node->right = NULL;
    
    return node; //Zwracanie nowego węzła
}

void printBT(BTN *node)
{
    if(node == NULL)
        return;
        
    printBT(node->left);
    cout << node->key << " ";
    printBT(node->right);
}