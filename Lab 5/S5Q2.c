#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Ruben van Breda. 19200704

void reverseArray(int arraySize, int a[]);
void randomiseArray(int arraySize, int a[]);
void printArray(int arraySize, int a[],void (*arrayFunction)(int arraySize, int a[]));
bool isNumInArray(int arraySize,int num, int a[]);


void Results(int a, int b, int(*calculator)(int a, int b));

int main(void){
    int myArray[11] = {2,4,6,8,10,12,14,16,18,20};
    int input; // User Input
    int len = sizeof(myArray)/sizeof(int);
    len-=1; // Bytes get rid of the trailing 0
    
    printf("Enter Action for given array :\n1) Reverse Array\n2) Randomise Array.\n");
    scanf("%d",&input); // User input

    //Print Array
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ",myArray[i]);
    }
    printf("\n");

    // Logic
    if(input==1){
        printf("______Reverse______\n");
        printArray(len,myArray,reverseArray);
    }
    else if(input ==2){
        printf("______Randomise______\n");

        printArray(len,myArray,randomiseArray);
    }
    
    
    return 0;
}

void reverseArray(int arraySize, int a[]){

    int counter = arraySize;
    int last = arraySize - 1; //last int in array
    for(counter = 0;counter<arraySize/2;counter++){
        // Check that a at index counter is not null.
        if(a[counter] != '\0'){
            //SWAP
            int swap = a[counter];
            a[counter] = a[last];
            a[last] = swap;
            last--;
        }

       
        
    }

    
    
}

void randomiseArray(int arraySize, int a[]){
    
    //Set random seed
    srand(time(NULL));
    // Array to store all used indieces used
    int usedIndex[arraySize];

    for (size_t i = 0; i < arraySize; i++)
    {
        // Create a random number
        int rnum = rand()%(arraySize);
        // Check that the random number has not been used already.
        while(isNumInArray(arraySize,rnum,usedIndex)){
            rnum = rand()%arraySize;
        }
        //Set the rnum as a number that has been used
        usedIndex[i] = rnum;
        //SWAP
        int swap = a[i];
        a[i] = a[rnum];
        a[rnum] = swap;
        
    }

    



}

bool isNumInArray(int arraySize, int num, int a[]){
    //int len = sizeof(a)/sizeof(int);
    //int usedIndex[arraySize];

    for (size_t i = 0; i < arraySize; i++)
    {
       if (a[i] != '\0')
       {
            if (a[i] == num)
            {
                return true;
            }
       }
    }

    return false;
}
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[])){

    (*arrayFunction)(arraySize,a);
    
    //Print Array
    for (size_t i = 0; i < arraySize; i++)
    {
        printf("%d ",a[i]);
    }
    
}



