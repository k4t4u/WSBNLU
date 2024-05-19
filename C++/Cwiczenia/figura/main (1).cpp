#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main(int argc, char** argv) {

  Circle c(1, 1, 3);
  Rectangle r(0, 1, 5, 6);
  c.print();
  cout << "Area = " << c.getArea() << endl;
  r.print();
  cout << "Area = " << r.getArea() << endl;

  return 0;
}
