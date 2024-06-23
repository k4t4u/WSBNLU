#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

int main(){

    // function template  sqr<T>
    cout << sqr(4) << endl;             // 16
    cout << sqr(14.5) << endl;          // 210.25

    // function template mod<N>
    cout << mod<5>(131) << endl;        // 1
    cout << mod<7>(131) << endl;        // 5

    // function template print
    std::vector<int> v = {1, 21, 34, 4, 15};
    print(v);                    // 1 21 34 4 15

    std::list<double> l = {1, 2.1, 3.2, 6.3};
    print(l);                    // 1 2.1 3.2 6.3

    double tab[] = {1.2, 3.4, 5.5};
    print(tab);                  // 1.2 3.4 5.5

    // function template applyFun
    auto w = applyFun(v, sqr<int>);
    print(w);  // 1 441 1156 16 225


    auto w3 = applyFun(w, [](int a){return mod<0>(a, 3);}  );
    print(w3); // 4 444 1159 19 228


    auto l2 = applyFun(l, sqr<double>);
    print(l2); // 1 4.41 10.24 39.69

    double a[] = {1, 2, 3, 4};
    process<double, sin, 4> (a);
    print(a);  // 0.841471 0.909297 0.14112 -0.756802

    return 0;
}
/**
16
210.25
1
5
1 21 34 4 15
1 2.1 3.2 6.3
1.2 3.4 5.5
1 441 1156 16 225
4 444 1159 19 228
1 4.41 10.24 39.69
0.841471 0.909297 0.14112 -0.756802
*/
