/* Copyright 2022 An Nguyen anetw@uw.edu*/


//Internal features and helper functions for Point3d.c


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



// A point in 3D that has 3 coordinates x, y, z
typedef struct point3d {
    int32_t x;   
    int32_t y;
    int32_t z;
} Point3d;


// Mallocs space for a Point3d 
// and assign the three int32_t x, y, z arguments to the x, y, z fields.
// Returns the assigned pointer to Point3d 
Point3d* Point3d_Allocate(int32_t x, int32_t y, int32_t z);

//Scales the x, y, z fields of the pointed-to struct by the given n value
void Point3d_Scale(Point3d* ptd, int32_t n);

//Constructs a Point3d with x, y, z equal to zero, and return a copy of the struct
Point3d Point3d_GetOrigin();