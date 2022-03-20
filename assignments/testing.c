#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this functon is to input a string list
//and its size , then returns a copy of the list
char** duplicateStringList(int n, char ** source ) {
    //allocate memory for n char **
    char **newList = malloc(sizeof(char*) * n);
    //now copy all the strings
    int i;
    for(i = 0 ; i < n ; i++){
        //now duplicate each string
        newList[i] = strdup(source[i]);
    }
    //return the new list
    return newList;
}


int main(int argc, char *argv[]){
    //make a copy of the strings
    char** copy = duplicateStringList(argc , argv);
    //print all string
    int i;
    for(i = 0; i < argc; i++){
        printf("%s\n", copy[i]);
    }
   
    return EXIT_SUCCESS;
}

