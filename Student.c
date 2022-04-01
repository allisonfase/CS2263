#include <stdio.h>
#include "Point2D.h"
#include "Student.h"


Student* createStudent(char* name, Point2D* location){
  Student* student = (Student*)malloc(sizeof(Student));
  student->name = name;
  student->location = *location;

  return student;
}
