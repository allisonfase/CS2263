#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define INPUT_SIZE 10000
#define ARRAY_SIZE 100
#define TAG_SIZE 25

char *storeInput(char *input, int inputSize);
char *findTagFront(char *input);
char *findTagBack(char *input);

int main(int argc, char *argv[]){
    char inputarr[INPUT_SIZE];
    char *tagFront;
    char *tagBack;
    int i;

    storeInput(inputarr, INPUT_SIZE);
    
    //findTagBack(inputarr);
    
    // for(i = 0; i < INPUT_SIZE; i++){
    //     printf("%s", inputarr);
    // }

    return EXIT_SUCCESS;
}