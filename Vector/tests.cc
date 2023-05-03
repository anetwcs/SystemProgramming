/* Copyright 2022 An Nguyen anetw@uw.edu*/


#include <cstdlib>
#include <iostream>
#include "Vector.h"
using std::cout;
using std::endl;
using vector333::Vectoc;


int main() {
    // constructor testing
    Vector v1;
    cout << "vector v1 expected value is (0,0,0), actual is: " << v1 << endl;
    Vectoc v2(3, 0, -1);
    cout << "vector v2 expected value is (3,0,-1), actual is: " << v2 << endl;
    Vector v3(v2);
    cout << "vector v3 expected value is (3,0,-1), actual is: " << v1 << endl;


    // //operation and assignment testing
    // v1 = v2 + v3;
    // cout << "vector v1 expected value is (6,0,-2), actual is: " << v1 <<endl;

    // cout << "expected dot product of v2 and v3 is (9, 0, 1), actual is: " << v2*v3 <<endl;
    // cout << "expected sclar product of 3 and 1 is (18, 0, -6), actual is: " << 3*v1 <<endl;
    return EXIT_SUCCESS;
}