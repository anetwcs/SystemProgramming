/* Copyright 2022 An Nguyen anetw@uw.edu*/

#ifndef _VECTOR_H_
define _VECTOR_H_

#include <iostream>
using std::ostream;
using namespace std;

namespace vector333 {
    class Vector {
        public:
         
        // default constructor
        Vector();
        
        // (x, y, z) constructor
        Vector(const float x, const float y, const float z) ;

        // copy constructor
        Vector(const Vector &v);

        // deconstructor
        ~Vector();

        // assign operator
        Vector &operator = (const Vector &opt);
        
        // update assigned values
        Vector &operator+= (const Vector &opt);
        Vector &operator-= (const Vector &opt);
        
        // dot product 
        friend double operator*(const Vector &v1, const Vector &v2);

        // scalar multiplication
        friend Vector operator*(const double k, const Vector&v);
        friend Vector operator*(const Vector &v, const double k);

        // stream output
        friend ostream & operator << (ostream &out, const Vector &v);

        private:
       
       
       

    };
    // sum and subtraction
    Vector operator+(const Vector &a, const Vector &b);
    Vector operator-(const Vector &a, const Vector &b);
}

#endif  

