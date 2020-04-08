#include <stdio.h>
#include <stdbool.h>

// Created by Ruben van Breda 19200704

void CalcDayOfWeek(int day,int month,int year); // Function prototype to return the day of week given the date in DD/MM/YY
bool isLeapYear(int n_year); // Function prototype to takes in a year and returns a bool true if year is a leap year.
int main(void){

    int d,m,y; // Declare variables for our day,month and year

    /*  Get input from the user */
    printf("Please enter the year:\n");
    scanf("%d", &y);

    printf("Please enter the month (1-12):\n");
    scanf("%d", &m);

    printf("Please enter the day of month:\n");
    scanf("%d", &d);

    //Call the function CalcDayOfWeek
    CalcDayOfWeek(d,m,y);
    return 0;
}

void CalcDayOfWeek(int day, int month, int year){
    // https://en.wikipedia.org/wiki/Zeller's_congruence
    //https://www.geeksforgeeks.org/zellers-congruence-find-day-date/

    // An array to store the maximum days of each month
    int maxDaysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Check if the given year is a leap year
    if(isLeapYear(year)){
        maxDaysInMonth[1]++; // Increase the max days for feb to 29
    }
    //Check that the input is in bounds
    if(day > maxDaysInMonth[month-1] || day <= 0){
        
        printf("There is not %d days in the month\n",day);
    }    
    
   // Modify values foe the algorithm to work as attended.
   // It uses the last 2 months of the previous year.
    if(month == 1){
        month = 13;
        year--;
    }
    if(month == 2){
        
        month = 14;
        year--;
    }

    int K = (year%100);
    int J = year/100;

    /*Zeller’s congruence is an algorithm devised by Christian Zeller
     to calculate the day of the week for any Julian or Gregorian calendar date.*/
    int h = (day + ( (13*(month+1))/5 ) + K + (K/4) + (J/4) - (2*J) ) % 7;
    
    h = ((h+5)%7) + 1; // Change h so that monday starts at 1
   
    
    //Clean up
    if(month == 13 || month == 14){
        year++;
        month-=12;
    }

    /*  Output the day to the user according to the value h obtained above with Zeller’s congruence algorithm. */
    switch(h){
        case 1:
            printf("%d/%d/%d is a Monday\n",day,month,year);
            break;
        case 2:
            printf("%d/%d/%d is a Tuesday\n",day,month,year);
            break;
        case 3:
            printf("%d/%d/%d is a Wednesday\n",day,month,year);
            break;
        case 4:
            printf("%d/%d/%d is a Thursday\n",day,month,year);
            break;
        case 5:
            printf("%d/%d/%d is a Friday\n",day,month,year);
            break;
        case 6:
            printf("%d/%d/%d is a Saturday\n",day,month,year);
            break;
        case 7:
            printf("%d/%d/%d is a Sunday\n",day,month,year);
            break;
        default:
            printf("Error unexpected h value\n");
           
    }
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