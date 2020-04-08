#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Created by Ruben van Breda 19200704

#define MAX 6 // the max aount of numbers for the lottery


int Random(int upperLimit); // Return a random integer from 1 to the upper limit passed into the function.
bool isNumInArray(int checkNum, int list[MAX],int length); // Check if a number num is already in the array list and return true if it is found.
void GenerateLotteryNumbers(int popArray[MAX]); // Generates a random set of numbers that comply with the rules of the national-lottery UK.




int main(void){
    
    int lottery[MAX]; // Declare a array to store the lottery numbers.
    GenerateLotteryNumbers(lottery); // Call function
    /*  Output the numbers in the array */
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\n",lottery[i]);
    }
    
    return 0;
}
// Pick 5 main numbers from 1-39 and 1 Thunderball from 1-14.
void GenerateLotteryNumbers(int popArray[MAX]){

    for (int i = 0; i < MAX; i++)
    {   
        int rnum; // An integer to store the random number for the lottery.
        // Check if we are on the 6th number, as it is a random number 1 - 14
        if(i == MAX -1){
            rnum = Random(14); // Thunderball 1 -14
            // Check that the new random number has not already been chosen.
            while (isNumInArray(rnum, popArray, MAX))
            {
                rnum = Random(14);
            }
            popArray[i] = rnum;
        }
        // For numbers 1-5 are random numbers 1 - 39
        else{
            rnum = Random(39); // Main numbers 1 - 39
            // Check that the new random number has not already been chosen.
            while (isNumInArray(rnum, popArray, MAX))
            {
                rnum = Random(39);
            }
            popArray[i] = rnum;
        }
        
    }
 
}
/*  Generate a random number */
int Random(int upperlimit){
    return rand() % upperlimit + 1;
}
// Check if a number num is already in the array list and return true if it is found.
bool isNumInArray(int num,int list[MAX],int length){

    for (int i = 0; i < length; i++)
    {   
        // Checks if the current number in the list is equal to the check num
        if(list[i] == num){
            return true;
        }
    }

    return false;
    

}



