#include <stdio.h>


// Created by Ruben van Breda 19200704

int DecToBin(int num); // Function prototype to convert decimal to binary
int main(void){
    int input;
    scanf("%d",&input);
    printf("%d",DecToBin(input));
    return 0;
}

int DecToBin(int num){
    // Base case
    if(num==0){
       
        return 0;
    }

    else
    {
        int rem = num % 2;
        return rem + 10 * IntToBin(num/2);
    }
}