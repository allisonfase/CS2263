#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Strings.h"
#include "Student.h"
#include "BusRoute.h"

int main(int argc, char** argv){
    char* terminators = "\n\0";

    // read file with stops in it
    char* filename = argv[1];
    if(filename == NULL){
        printf("wow no filename given, y u do dis?\n");
        return 1;
    }
    printf("filename: %s\n", filename);
    FILE* routeFile = fopen(filename, "rb");

    // -> take the first line, giving us # of bus routes
    char* firstLine = getfString(routeFile, terminators);
    printf("First line:\n%s\n", firstLine);

    // *-> use the first line to determine how much memory to allocate
    // *-> for an array of bus routes
    int numRoutes = atoi(firstLine);
    printf("Number of routes: %d\n", numRoutes);
    BusRoute** routes = (BusRoute**)calloc(numRoutes, sizeof(BusRoute*));

    // each bus route is on its own line, so the file has
    // numRoutes + 1 
    // lines
    // -> for each following line:
    char* secondLine = NULL;
    int i = 0;
    for(i = 1; i <= numRoutes; i++){
    // we start at i = 1 because we have already consumed the first line
        int currentArrayIndex = i - 1;

        // use a space terminator to separate the values
        char* numStopsString = getfString(routeFile, " \0");
        int numStops = atoi(numStopsString);

        printf("Number of stops: %s | %d\n", numStopsString, numStops);

        // *-> construct a new bus route
        routes[currentArrayIndex] = mallocBusRoute(numStops); // needs numStops
        // *-> construct a new pointlist
        PointList* pointList = (PointList*)mallocPointList(numStops);
        
        // *-> first number in line is how many stops
        // *-> second number is the x coordinate of the first stop
        // *-> third number is the y coordinate of the first stop
        // *-> then a string, the bus route name
        
        char* stopXCoord = NULL;
        char* stopYCoord = NULL;
        char* routeName = NULL;

        double x = 0;
        double y = 0;
        int j = 0;
        for(j = 0; j < numStops; j++){
            stopXCoord = getfString(routeFile, " ");
            stopYCoord = getfString(routeFile, " ");
            printf("String coords: (%s, %s)\n", stopXCoord, stopYCoord);
            
            x = atof(stopXCoord);
            y = atof(stopYCoord);
            printf("Double coords: (%f, %f)\n", x, y);

            Point2D* p2d = createPoint2D(x, y);

            // populating bus stops on the route
            addPoint(routes[currentArrayIndex], p2d, j);
        }

        routeName = getfString(routeFile, "\n");

        printf("Route name: %s\n", routeName);
        setRouteName(routes[currentArrayIndex], routeName);

        printf("============================================\n");

    }
    //
    // make empty array of students
    Student studentList[1024] = {0};

    // read in student 
    // -> for each line:
    while(1){
        char c = getchar();
        if(c == EOF){
            return 0;
        }
        else{
            ungetc(c, stdin);
        }
        // *-> construct a new student
        char* studentXCoord = getfString(stdin, " ");
        char* studentYCoord = getfString(stdin, " ");
        char* studentName = getfString(stdin, "\n\0");

        printf("String coords: (%s, %s)\n", studentXCoord, studentYCoord);
        printf("Student name: %s\n", studentName);
        double x = atof(studentXCoord);
        double y = atof(studentYCoord);
        printf("Double coords: (%f, %f)\n", x, y);

        Point2D* studentsHouse = createPoint2D(x, y);

        double closestDistance = 100000000000000;
        char* closestName = NULL;
        for(i = 0; i < numRoutes; i++){
            BusRoute* currentRoute = routes[i];
            for(int j = 0; j < currentRoute->numStops; j++){
                Point2D* currentStop = getPoint(currentRoute, j);
                double currentDistance = getDistancePoint2D(currentStop, studentsHouse);
                if (currentDistance < closestDistance){
                    // printf("Found new closest\n");
                    closestDistance = currentDistance;
                    closestName = duplicateString(currentRoute->routeName);
                }
            }
        }

        printf("Best route for [%s] is [%s]\nWith a bus stop distance of [%f]\n", studentName, closestName, closestDistance);
        printf("====================================================================\n");
        // *-> first number is x coordinate
        // *-> second number is y coordinate
        // *-> then a string for the student's name
        //
        // for each student:
        // -> for each bus route:
        // *-> set first stop as closest
        // *-> for each bus stop:
        // **-> if this stop is closer than the closest
        // ***-> set this stop as the closest
        // -> print student name and bus route (and distance for funsies lol)
    }
    return 0;
}
