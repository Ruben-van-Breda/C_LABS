#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>


// Ruben van Breda 19200704
/*
    S7Q1 Program -> Take an input of n words, these are jumbled up and random word is printed.
*/

#define MAX_CHAR 20

bool isNumInArray(int arraySize, int num, int a[]);
void randomiseArray(char *a[MAX_CHAR],int arraySize);
void Swap(char a[MAX_CHAR],int index1,int index2); // Swap two index1,index2 values of an array.

int main(void){

    int n;
    char *words[MAX_CHAR];

    // ___Input___
    puts("Please enter the number of words(entries): ");
    scanf("%d",&n);

    if(words == NULL){
        puts("Memory not allocated.");
        exit(0);
    }
    else{
        //  INPUT
        printf("Please enter words:\n");
        for (size_t i = 0; i < n; i++)
        {
            words[i] = (char*)calloc(MAX_CHAR,sizeof(char)); // Allocate memory
            scanf("%s",words[i]);

        }

        randomiseArray(words,n);
        printf("\nRandomised List\n");
        //  Display Array
        for (int j = 0; j < n; ++j) {
            printf("%s\n",words[j]);
        }

        //  Print out random word
        int rnum = rand()%(n);
        //printf("rnum => %d",rnum);
        printf("\nRandom Word -> %s\N",words[rnum]);

    }
   

    return 0;
}

// Swap two index1,index2 values of an array.
void swap(char *a[MAX_CHAR],int i1,int i2){

      char *temp[MAX_CHAR];
      strcpy(temp,a[i1]);
      strcpy(a[i1],a[i2]);
      strcpy(a[i2],temp);
}

void randomiseArray(char *a[MAX_CHAR],int arraySize){

    //Set random seed
    srand(time(NULL));
    // Array to store all used indieces used
    int usedIndex[arraySize];

    for (size_t i = 0; i < arraySize; i++)
    {
        // Create a random number
        int rnum = rand()%(arraySize);
        // Check that the random number has not already been used.
        while(isNumInArray(arraySize,rnum,usedIndex)){
            rnum = rand()%arraySize;
        }
    
        //SWAP
        swap(a,i,rnum);
     
        //Add the rnum as a number to the list of indices already used.
        usedIndex[i] = rnum;

    }




}

bool isNumInArray(int arraySize, int num, int a[]){
   
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