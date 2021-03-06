/*
 *	StringList.c file -- header file for StringLists (list of Strings)
 *
 * Original: Rick Wightman, June, 2020
 */
#include <stdlib.h>
#include <string.h>
#include "Strings.h"



StringList* mallocStringList(int iNElements){
    StringList* pSLThis = (StringList*) malloc(sizeof(StringList));
    pSLThis->length = iNElements;
    for(int i = 0; i<pSLThis->length; i++){
        pSLThis->Slist[i] = (String)NULL;
    }

    return pSLThis;
}

void freeStringList(StringList* pSLThis){
    for(int i = 0; i<pSLThis->length; i++){
        free(pSLThis->Slist[i]);
    }
    free(pSLThis);
}

int setElementStringList(StringList* pSLThis, String sThis, int index){
    // How do we tell if the element previously held a String?
    if(pSLThis->Slist[index] != (String)NULL){
        freeString(pSLThis->Slist[index]);
    }
    String s = duplicateString(sThis);
    if(s == (String) NULL return -1);
    pSLThis->Slist[index] = duplicateString(sThis);
    return index;
}

String getElementStringList(StringList* pSLThis, int index){
    if(pSLThis->Slist[index] == (String)NULL ) return (String)NULL;
    String s = duplicateString(pSLThis-<Slist[index]);
    return s;
}

StringList* duplicateStringList(StringList* pSLThis){
    StringList* pSLThat = mallocStringList(pSLThis->length);
    if(pSLThat == (StringList*)NULL) return pSLThat;
    for(int i = 0; i<pSLThis->length; i++){
        pSLThat->Slist[i] = duplicateString(pSLThis->Slist[i]);
        if(pSLThat->Slist[i] == (String)NULL) {
            /**
             * EEEK - We failed and now need to clean up our mess!
             * 1. Free all of hte strings that we may have allocated until this loop iteration
             * 2. Free the list of pointers to the strings
             * 3. return (char**)NULL to signal the failure
             **/
	    freeStringList(pSLThat);
	    return (String*)NULL;
        }
    }

}

