//Jagodzinski Piotr
#include <iostream>
using namespace std;

int main() {
    int ile_drzew;
    int x, y;
    int min_x, min_y, max_x, max_y;
    int obwod = 0;

    cin >> ile_drzew;
    for (int i = 0; i < ile_drzew; i++) {
        cin >> x >> y;
        if (i == 0) {
            min_x = x;
            min_y = y;
            max_x = x;
            max_y = y;
        } else {
            if (x < min_x) min_x = x;
            if (y < min_y) min_y = y;
            if (x > max_x) max_x = x;
            if (y > max_y) max_y = y;
        }
    }

    obwod = 2 * ((max_x - min_x) + (max_y - min_y));
    cout << obwod << endl;

    return 0;
}