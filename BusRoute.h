#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <stdio.h>
#include "Point2D.h"
#include "PointList.h"

typedef struct busroute{
  char* routeName;
  PointList* pList;
  int numStops;
} BusRoute;

BusRoute* mallocBusRoute(int numStops);

void freeBusRoute(BusRoute* route);
void addPoint(BusRoute* route, Point2D* point, int n);

Point2D* getPoint(BusRoute* route, int n);

void setRouteName(BusRoute* route, char* routeName);
char* getRouteName(BusRoute* route);

#endif
