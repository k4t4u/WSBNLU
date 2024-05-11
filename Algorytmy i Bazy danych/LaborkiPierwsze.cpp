//
// Created by k4tpa on 27.04.2024.
//


#include <iostream>
using namespace std;

int sumIter(int); //Suma kolejnych liczb naturalnych - iteracja
int sumRec(int); //Suma kolejnych liczb naturalnych - rekurencja
int sumMat(int); //Suma kolejnych liczb naturalnych - wzor matematyczny
int fibRec(int); // Wyznaczenie n-tego wyrazu ciagu Fibonacciego - rekurencja

int main()
{
    cout<<"Algorytmy"<<endl;
    cout<<"Sumowanie liczb naturalnych."<<endl;

    int n = 10;
    cout << "sumIter = " << sumIter(n) << endl;
    cout << "sumRec = " << sumRec(n) << endl;
    cout << "sumMat = " << sumMat(n) << endl;

    cout << endl << "Fibonacci" << endl;
    cout << "fibRec = " << fibRec(n) << endl;

    return 0;
}

int sumIter(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += i;

    return sum; //zwracana wartosc sumy
}

int sumRec(int n)
{
    if (n <= 1) // warunek zatrzymania rekurencji

        return n;

    return n + sumRec(n -  1);
}

int sumMat(int n)
{
    return (1 + n) * n / 2;
}

int fibRec(int n)
{
    if(n <= 1)
        return n;

    return fibRec(n - 1) + fibRec(n - 2);
}