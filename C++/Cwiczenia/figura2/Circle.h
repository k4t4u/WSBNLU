#pragma once
#include "Figura.h"
#include <iostream>
#include <cmath>
using namespace std;

class Circle : public Figura
{ 
public:
  Circle(double x=0, double y=0, double radius=0)
  : Figura(x,y), radius(radius){
    if(radius < 0){
      radius = 0;
    }
  }
  double getRadius() const { return radius; }

  void setRadius( double radius) { 
    if(radius>=0)
      this->radius = radius; 
  }
  void print() const override {
    cout << "Circle centre = (" << x << "," << y << ") radius = " << radius << endl;
  }

  double getArea() const override{
    return M_PI * radius * radius;
  }
protected:
  double radius; 
};

