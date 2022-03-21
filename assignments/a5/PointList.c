#include <stdio.h>
#include "Point2D.h"


//constructor
PointList* mallocPointList(){
    // allocates memory for PointList array
    // allocate memory for each element in PointList
    // checks to make sure memory is properly allocated
    // -> return error/null pointer is not allocated properly
    // -> return pointer to PointerList if allocated properly
}

// calls createPoint2D from Point2D
// calls addPoint2DtoList
// returns updated list
PointList* addCoordstoList(PointList* pPLThis, double xcoord, double ycoord){
    // pPLThis - PointList to add coords to
    // xcoord - x coordinate for point
    // ycoord - y coordinate for point

    // failure conditions:
    // PointList is null
    // -> print error message
    // -> return null pointer

    // success condition:
    // additional point added to PointList
    // -> return pointer to updated PointerList

} 

// returns Point2D at index n from the list
Point2D* getPointfromList(PointList* pPLThis, int n){
    // pPLThis - PointList to get point from
    // n - index of point to get

    // failure conditions:
    // n is greater than length of PointList
    // -> print error message
    // -> return null pointer
    // n is negative
    // -> print error message
    // -> return null pointer
    // PointList is null
    // -> print error message
    // -> return null pointer
    
    // success condition:
    // point is found in list
    // -> return Point2D pointer
}

// returns updated list after adding a new Point2D
PointList* addPoint2DtoList(PointList* pPLThis, Point2D* pPt2D){
    // pPLThis - PointList to add a Point2D
    // pPt2D - Point2D to add to PointList 

    // failure conditions:
    // PointList is null
    // -> print error message
    // -> return null pointer
    // Point2D is null
    // -> print error message
    // -> return null pointer

    // success condition:
    // -> if list is full **look up building dynamic arrays in c**
    // point is added to list
    // -> increment length
    // -> return updated PointList
}

// frees each indexed point in list
// frees PointList struct
// returns nothing
void freePointList(PointList* pPLThis){
    // pPLThis - PointList to be freed
}