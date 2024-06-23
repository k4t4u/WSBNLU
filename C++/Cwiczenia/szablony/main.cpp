
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include "Punkt.h"

using namespace std;

template <typename T> T sqr(T x) { return x * x; }

template <int M> int mod(int x) { return x % M; }

template <> int mod<0>(int x) { return x; }

template <typename T> void print(const T &data) {
  for (auto elem : data) {
    cout << elem << " ";
  }
  cout << endl;
}

template <typename V, typename F> V apply(const V &v, F f) {
  auto r = v;
  for (auto &elem : r) {
    auto tmp = f(elem);
    elem = tmp;
  }
  return r;
}




int main() {

  Punkt<int> A(1, 2.1);
  cout << A << endl; // (1, 2)
  Punkt<double> B(2, 3.1);
  cout << B << endl; // (2, 3.1)
  B.setX(5.5);
  cout << B << endl; // (5.5, 3.1)

  // function template  sqr<T>
  cout << sqr(4) << endl;    // 16
  cout << sqr(14.5) << endl; // 210.25

  // function template mod<N>
  cout << mod<5>(131) << endl; // 1
  cout << mod<7>(131) << endl; // 5

  // function template print
  std::vector<int> v = {1, 21, 34, 4, 15};
  print(v); // 1 21 34 4 15

  std::list<double> l = {1, 2.1, 3.2, 6.3};
  print(l); // 1 2.1 3.2 6.3

  double tab[] = {1.2, 3.4, 5.5};
  print(tab); // 1.2 3.4 5.5

  // function template applyFun
  auto w = apply(v, sqr<int>);
  print(w); // 1 441 1156 16 225

  auto w2 = apply(w, mod<5>);
  print(w2);

  auto l2 = apply(l, sqr<double>);
  print(l2); // 1 4.41 10.24 39.69

  auto l3 = apply(l2, mod<5>);
  print(l3);

  auto w3 = apply(w, mod<0>);
  print(w3); // 4 444 1159 19 228

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
