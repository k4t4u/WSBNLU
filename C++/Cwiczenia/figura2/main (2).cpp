#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Rysunek.h"




int main(int argc, char** argv) {

  Circle c(1, 1, 3);
  Rectangle r(0, 1, 5, 6);
  // c.print();
  // cout << "Area = " << c.getArea() << endl;
  // r.print();
  // cout << "Area = " << r.getArea() << endl;

  Rysunek rysunek;
  rysunek.dodaj(c);
  rysunek.dodaj(r);
  rysunek.dodaj(new Rectangle(4,5,4,5));
  rysunek.dodaj(new Circle(6.,6., 4));

  rysunek.narysuj(); // wypisz obiekty 

  cout << "Pole = " << rysunek.calkowitePole() << endl;
  
  return 0;
}
