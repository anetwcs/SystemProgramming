/* Copyright 2022 An Nguyen anetw@uw.edu*/


#include "Point3d.h" 


// Mallocs space for a Point3d 
// and assign the three int32_t x, y, z arguments to the x, y, z fields.
// Returns the assigned pointer to Point3d 
Point3d* Point3d_Allocate(int32_t x, int32_t y, int32_t z) {
    Point3d* p = (Point3d*) malloc(sizeof(Point3d));

    if (p == NULL) {
        //Out of memory
        return NULL;
    }

    //Assigns the given values to the coordinates
    p->x = x;
    p->y = y;
    p->z = z;

    //Returns a pointer to the allocated Point3d 
    return p;
}

//Scales the x, y, z fields of the pointed-to struct by the given n value
void Point3d_Scale(Point3d* ptd, int32_t n) {
    ptd->x *= n;
    ptd->y *= n;
    ptd->z *= n;
}

//Constructs a Point3d with x, y, z equal to zero, and return a copy of the struct
Point3d Point3d_GetOrigin() {
    Point3d og = {0,0,0};
    return og;
}
