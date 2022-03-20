#ifndef STRINGS_H
#define STRINGS_H

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
char* mallocString(int stringsize);

// just a cover function for free()
void freeString(char* s);

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(char* s);

// create a duplicate of string list sl
// return it
// return (char**)NULL on failure
// uses other Strings module functions
char** duplicateStringList(char** sl,int n);

// Return an allocated string from an open file,
// Stop reading when any character is in terminators list
// return allocated string or (char*)NULL
char* getfString(FILE* pFIn, char* terminators);
char* getString(char* terminators);

#endif