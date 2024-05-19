#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Figura { 
public:
  Figura(double x=0, double y=0)
  : x(x), y(y){
  }
  double getX() const { return x; }
  double getY() const { return y; }

  void setX( double x) { this->x = x; }
  void setY( double y) { this->y = y; }
  virtual void print() const {
    cout << "(" << x << "," << y << ")";
  }
  void move( double dx, double dy){
    x += dx;
    y += dy;
  }

    virtual double getArea() const = 0;
    
protected:
  double x, y;
};

