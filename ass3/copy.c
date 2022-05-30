#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define INPUT_SIZE 10000
#define ARRAY_SIZE 100
#define TAG_SIZE 25

/**
 * Step 1: read file through stdin
 * Step 2: store file in an array
 * Step 3: find the beginning of the first tag
 *      3.1: make sure it is not the forbidden type 
 * Step 4: assign pointer to beginning of tag 
 * Step 5: find end of tag
 * Step 6: use pointer to hold address 
 * Step 7: count occurrences of tag
 * Step 8: print tag and number of occurrences
 */


char findTagFront(char *input){
    int i = 0;
    int k;
    char tag[TAG_SIZE] = "";
    char *frontptr = strstr(input, "<");
    // if(*frontptr == NULL)
    //     return NULL;
    
    frontptr++;
    //for(k = 0; k < strlen(input); k++)
    if(!isalpha(*frontptr) && *frontptr != '<'){
        frontptr = strstr(input, "<");
        frontptr++;
    }   

    while(isalpha(*frontptr)){
        tag[i] = *frontptr;
        frontptr++;
        i++;
    }
    int count = countTags(input, tag);
    if(tag != "")
    printf("%s \t %d\n", tag, count);
    return *tag;  
}

// char *findTagBack(char *input, char *frontptr){
//     char *backptr = frontptr;
//     if(backptr == NULL)
//         return NULL;
    
//     backptr++;
//     while(isalpha(*backptr)){
//         backptr++;
//     }   

//     if(!isalpha(*backptr)){
//         backptr--;
//         printf("back: %c\n", *backptr);
//     }
//     return backptr;  
// }

int countTags(char *input, char *tag){
    int i;
    int j;
    int found;
    int count = 0;
    int inputLength = strlen(input);
    int tagLength = strlen(tag);

    for(i = 0; i <= inputLength - tagLength; i++){
        found = 1;
        for(j = 0; j < tagLength; j++){
            if(input[i+j] != tag[j]){
                found = 0;
                break;
            }
        }
        if(found == 1)
            count++;
    }
    return count;
}

char *storeInput(char *input, int inputSize){
    input[inputSize];
    char *c = fgets(input, INPUT_SIZE, stdin);
    while(c != NULL){        
        printf("%s\n", input);
        char tag = findTagFront(input);
        //char *backptr = findTagBack(input, frontptr);
        c = fgets(input, INPUT_SIZE, stdin);
    }
    return input;
}