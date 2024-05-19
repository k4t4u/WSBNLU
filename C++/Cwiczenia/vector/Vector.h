#include <iostream>

class Vector {
    int dim;    // dimension of an array (size of vector)
    double *x;  // an array of coordinates
    //double x[dim];
  public:
    Vector(int dimension = 1);

    // access to coordinates: index start with 1
    double at(int index) const {return x[index-1];}

    double & at(int index) {return x[index-1]; }

    // konstruktor kopiujący
    Vector(const Vector & v) : dim(v.dim) {
      x = new double[v.dim];
      for(int i=0; i<v.dim; ++i){
        x[i] = v.x[i];
      }
    }

    // operator przypisania
    Vector & operator=(const Vector & v){        
      dim = v.dim;
      delete[] x;
      x = new double[v.dim];
      for(int i=0; i<v.dim; ++i){
        x[i] = v.x[i];
      }
      return *this;
    }

    // * destruktor that frees memory
    ~Vector(){
      delete[] x;
    }


    // friend function declaration
    friend std::ostream & operator<< (std::ostream & out, const Vector & v);

};

//  a + b
// Vector operator+(const Vector & a, const Vector & b){
  
// }