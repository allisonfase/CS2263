#include "BusRoute.h"
#include "Strings.h"
#include <stdio.h>

BusRoute* mallocBusRoute(int numStops){
  // Accept number of bus stops
  
  // Allocate memory for each point2d (bus stop)
  BusRoute* route = (BusRoute*)malloc(sizeof(BusRoute));
  route->pList = mallocPointList(numStops);
  route->numStops = numStops;

  return route;
}

void freeBusRoute(BusRoute* route){
  freeString(route->routeName);
  freePointList(route->pList);
  free(route);
}

void addPoint(BusRoute* route, Point2D* point, int n){
  // route - bus route to add a stop to
  // point - the stop to be added
  // n - ??? maybe a counter to know where we are in the list
  setElementPointList(route->pList, point, n);
}

Point2D* getPoint(BusRoute* route, int n){
  // route - the route from which we get the stop
  // n - the index of the stop in the list
  Point2D* p = getElementPointList(route->pList, n);
  return p;
}

void setRouteName(BusRoute* route, char* routeName){
  route->routeName = duplicateString(routeName);
}

char* getRouteName(BusRoute* route){
  return route->routeName;
}