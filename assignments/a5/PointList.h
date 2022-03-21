#ifndef POINTLIST_H
#define POINTLIST_H

#include <stdio.h>
#include "Point2D.h"

typedef struct pointlist{
    // a dynamic array which acts like a list of cartesian points 
    PointList pointList[];

    // keeps track of how many points are in the array
    int length;

    // keeps track of the maximum number of elements in the array
    int maxLength;

} PointList;

//constructor
PointList* mallocPointList();

// calls createPoint2D from Point2D
// calls addPoint2DtoList
// returns updated list
PointList* addCoordstoList(PointList* pPLThis, double xcoord, double ycoord); 

// returns Point2D at index n from the list
Point2D* getPointfromList(PointList* pPLThis, int n);

// returns updated list after adding a new Point2D
PointList* addPoint2DtoList(PointList* pPLThis, Point2D* pPt2D);

// frees each indexed point in list
// frees PointList struct
// returns nothing
void freePointList(PointList* pPLThis);

#endif