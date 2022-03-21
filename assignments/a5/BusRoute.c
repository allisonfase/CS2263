#include <stdio.h>
#include "Point2D.h"
#include "PointList.h"

typedef struct busroute{
  char* routeName;
  PointList pList;
  int numStops;
} BusRoute;

BusRoute* mallocBusRoute(int numStops){
  // Accept number of bus stops
  
  // Allocate memory for each point2d (bus stop)
  BusRoute* route = (BusRoute*)malloc(sizeof(BusRoute));
  
  // Check that all allocations were successful
  // -> Return error code/null pointer if unsuccessful
  // -> Return pointer to allocated bus route if successful

  // Other conditions? Edge cases?
}

void addPoint(BusRoute* route, Point2D point, int n){
  // route - bus route to add a stop to
  // point - the stop to be added
  // n - ??? maybe a counter to know where we are in the list

  // Fail conditions:
  // point already in list of stops 
  // -> don't allow for duplicates
  // route is full 
  // -> print error message

  // If no failure conditions are met, the point is successfully added to the list

}

Point2D* getPoint(BusRoute* route, int n){
  // route - the route from which we get the stop
  // n - the index of the stop in the list

  // Fail conditions:
  // the index value n is greater than route length
  // -> return null
  // route is uninitialized (null pointer)
  // -> return null

  // If no failures, return pointer to the bus stop at the given index
}
