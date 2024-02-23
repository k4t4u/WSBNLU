// Jagodzinski Piotr
#include<iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int *liczby = new int[n];
    for(int i = 0; i < n; i++)
        cin >> liczby[i];
    
    for(int i = 0; i < n; i+=2)
        cout << liczby[i] << " ";
    
    cout << "\n";
    
    for(int i = 1; i < n; i+=2)
        cout << liczby[i] << " ";
    
    delete[] liczby;
    return 0;
}