//Jagodzinski Piotr
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double poleTrojkata(double x, double y, double z) {
    double s = (x + y + z) / 2;

    return sqrt(s * (s - x) * (s - y) * (s - z));
}

int main() {
    double x, y, z;

    cin >> x >> y >> z;

    cout << fixed << setprecision(3) << poleTrojkata(x, y, z) << endl;

    return 0;
}