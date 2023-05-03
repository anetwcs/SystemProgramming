/* Copyright 2022 An Nguyen anetw@uw.edu*/

#include "Vector.h"
#include <iostream>
using std::ostream;

namespace vector333 {

    
    Vector::Vector {
        v_ = new float[3];
        v_[0] = 0;
        v_[1] = 0;
        v_[2] = 0;
    }

    Vector::Vector(const float x, const float y, const float z) {
        v_ = new float[3];
        v_[0] = x;
        v_[1] = y;
        v_[2] = z;
    }


    Vector::Vector(const Vector &vcop) {
        v_ = new float[3];
        v_[0] = vcop.v_[0];
        v_[1] = vcop.v_[1];
        v_[2] = vcop.v_[2];
    }

    Vector::~Vector(){
        delete[] v_;
    }

    // Vector assignment
    Vector &Vector::operator = (const Vector &opt) {
        v_[0] = opt.v_[0];
        v_[1] = opt.v_[1];
        v_[2] = opt.v_[2];
        return *this;
    }

    //sum assignment update
      Vector &Vector::operator += (const Vector &opt) {
        v_[0] += opt.v_[0];
        v_[1] += opt.v_[1];
        v_[2] += opt.v_[2];
        return *this;
    }

      //sum assignment update
      Vector &Vector::operator -= (const Vector &opt) {
        v_[0] -= opt.v_[0];
        v_[1] -= opt.v_[1];
        v_[2] -= opt.v_[2];
        return *this;
      }
      
      // dot product 
      double operator*(const Vector &v1, const Vector &v2) {
        return v1.v_[0]*v2.v_[0] + v1.v_[1]*v2.v_[1] + v1.v_[2]*v2.v_[2]; 
      }

      // scalar muliplication functions
      Vector operator*(const double k, const Vector &v) {
        return Vector(k*v.v_[0], k*v.v_[1], k*v.v_[2]);
      }

      Vector operator*(const Vector &v, const double k) {
        return Vector(k*v.v_[0], k*v.v_[1], k*v.v_[2]);
      }

      // stream output
      ostream & operator<<(ostream &out, const Vector &v) {
        out << "(" << v.v_[0] << "," << v.v_[1] << "," v.v_[2] ")";
        return out;
      }

      Vector operator+(const Vector &a, const Vector &b) {
        Vector temp = a;
        temp += b;
        return temp;
      }

        Vector operator-(const Vector &a, const Vector &b) {
        Vector temp = a;
        temp -= b;
        return temp;
      }
}

      

