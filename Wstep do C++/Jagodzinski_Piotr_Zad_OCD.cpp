// Jagodzinski Piotr
#include <iostream>
using namespace std;

int main() {
    long long doPotegi;
    cin >> doPotegi;
    int cyfry[] = {6, 2, 4, 8};
    if(doPotegi == 0) cout << 1 << endl;
    else cout << cyfry[doPotegi % 4] << endl;

    return 0;
}