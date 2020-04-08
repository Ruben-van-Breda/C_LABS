#include<stdio.h>
#include<stdbool.h>

// Prac1 question 3
// Program to determine if a number is prime.
// Ruben van Breda 19200704
bool isPrimeNumber(int num); // Function prototype returns true if a given number is prime
int main(void)
{
    int number;
    bool isPrime = true; 

    printf("Enter number:\n");
    scanf("%d",&number);
    
    if(isPrimeNumber(number)){
        printf("%d is a prime number\n",number); return 0;
    }
    printf("%d is not a prime number\n",number); return 0;

}

bool isPrimeNumber(int num){
    for(int i = 2;i<num/2;i++){
       // Check if some previous integer is a factor of the given number
       if(num%i == 0){
            return false;
       }

    }
    return true;
}