#include <stdio.h>


// Created by Ruben van Breda 19200704

int multi(int num,int times); // Function prototype
int main(void){
    int num,times;

    /*  Get Input */
    printf("Enter the number:\n");
    scanf("%d",&num);
    printf("Enter the size of the multiplication table:\n");
    scanf("%d",&times);
    printf("\n");
    multi(num,times); // Call the function
    return 0;
}

int multi(int num,int times){
    static int count = 1; // A counter to count how many times the multiplication has taken place.
    //Check if the counter has reached the times the user inputed.
    // Base case
    if(count>=times+1){
       
        return 1;
    }

    printf("%d\n",num*count); // Output the result to terminal
    count++; // Increase the counter
    return multi(num,times); // Recursive step

    
}