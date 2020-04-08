#include<stdio.h>
#include<stdbool.h>

// Prac1 question 4
// Program to determine if a given year is a leap year.
// Ruben van Breda 19200704

bool isLeapYear(int n_year); // Function prototype to takes in a year and returns a bool true if year is a leap year.
int main(void)
{
    int year;
    
    printf("Enter the year:\n");
    scanf("%d",&year);

    if(isLeapYear(year)){
        printf("%d is a leap year.",year); return 0; 
    }
   
    printf("%d is not a leap year.",year); return 0;

}

/* isLeapYear checks if the given int year is a leap year and returns 
    true if it is and false if the year is not a leap year */
bool isLeapYear(int n_year){
    if(n_year%4 == 0){    // Checks if year is a factor of 4
        if(n_year%100 == 0){  // Checks if year is a factor of 100
            if(n_year%400 == 0){    // Checks if year is a factor of 100
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}