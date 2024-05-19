#include "Vector.h"

Vector::Vector(int dimension) : dim(dimension) {
  if (dim < 1)
    dim = 1;
  x = new double[dim];
}

std::ostream &operator<<(std::ostream &out, const Vector &v) {
  out << "(";
  for (int i = 0; i < v.dim - 1; ++i) {
    out << v.x[i] << ", ";
  }
  out << v.x[v.dim - 1] << ")";
  return out;
}
