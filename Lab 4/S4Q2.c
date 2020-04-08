#include <stdio.h>
#include <stdlib.h>

/* Ruben van Breda,
    19200704
*/


void copyArrayIndexWay(char * const newArray1, const char * const originalArray1);
void copyPointerWay(char *newArray2, const char *originalArray2);

int main(void){

    char originalArray1[] ="COMP10120";
    char originalArray2[] = "COMP10110";
    char *newArray1; // Declare an pointer to a address of char base type
    char *newArray2; // Declare an pointer to a address of char base type

    /*Set the size equal to the,
    (the amount of memory allocated to the array) in bytes / (the amount of memory allocated to the 0 index of the array) in bytes 
    to give the cardinality of the sets  */
    int size1 = sizeof(originalArray1) / sizeof(originalArray1[0]); 
    int size2 = sizeof(originalArray2) / sizeof(originalArray2[0]);

    /*  Dynamically allocate a single large block of memory with the specified sizes of size1 and size2 for the arrays. */
    newArray1 = malloc(sizeof(char) * size1);
    newArray2 = malloc(sizeof(char) * size2);
    

    copyPointerWay(newArray2,originalArray2);
    copyArrayIndexWay(newArray1,originalArray1);
    printf("%s\n",newArray1);
    printf("%s",newArray2);

 
   
   


    return 0;
}

void copyPointerWay(char *newArray2, const char *originalArray2){
    /* While the address pointer is not empty*/
    while(*originalArray2 != '\0'){
        
        *newArray2 = *originalArray2;
        // Increment the address at which the array is pointing too by the memory size allocated to an element.
        // Which in this case, increment by the memory allocated to a type of char, 1 byte. 
        // Do the same for newArray2, moving along the single block size of 10 bytes by 1 byte each loop. 
        originalArray2+=sizeof(originalArray2[0]);
        newArray2+=sizeof(originalArray2[0]); 
    }
}

void copyArrayIndexWay(char * const newArray1, const char * const originalArray1){
    int i = 0;
    // While the index of i in the array is not null
    while(originalArray1[i] != '\0'){
        // Assign the element of i in the new array to the value of i in original array
        newArray1[i] = originalArray1[i];
        i++;
    }
    
}

