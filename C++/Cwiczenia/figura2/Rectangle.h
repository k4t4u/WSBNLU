#pragma once
#include "Figura.h"
#include <iostream>
using namespace std;

class Rectangle:public Figura {
public:
  Rectangle(double x = 0, double y = 0, double width = 0, double height = 0)
      : Figura(x,y) {
    this->width = (width > 0) ? width : 0;
    this->height = std::max(0.0, height);
  }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  void setWidth(double width) { this->width = width; }
  void setHeight(double height) { this->height = height; }
  void print() const override {
    cout << " Rectangle position = (" << x << "," << y << ") width = " << width
         << " height = " << height << endl;
  }
  double getArea() const override { return width * height; }

protected:
  double width, height;
};
