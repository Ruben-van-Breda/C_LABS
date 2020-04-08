#include <stdio.h>
#include <stdlib.h>

/*  S7Q4 Ruben van Breda
    19200704
    
    Program -> take in seconds and format into D:H:M:S
    */

typedef struct Time
{
    int seconds;
    int min,hr,days;
} Time;

//: DEFINITIONS
//Seconds that make up:
#define MINUTE 60
#define HOUR 3600
#define DAY 86400


//: PROTOTYPES
void FormatTime(Time n_time);
void printTime(Time n_time);



    /* Time Calculator */
int main(void){

    int input;
    Time myTime;
    // Get user input
    printf("Please enter amount of seconds: ");
    scanf("%d",&myTime.seconds);
    //Call the function to calculate time 
    FormatTime(myTime);
    //Output result to user
    printTime(myTime);

    return 0;
}

void FormatTime(Time n_time){
    //Takes in a Time with the seconds assigned and calculates the corrosponding D:H:M:S format

    int day = n_time.seconds/DAY;
    // printf("Day %d\n",day);
    int remainder = n_time.seconds-(day*DAY);
    // printf("remainder %d\n",remainder);

    int hours = remainder/HOUR;
    // printf("Hour %d\n",hours);
    remainder = n_time.seconds-((n_time.seconds/HOUR)*HOUR);
    //printf("remainder %d\n",remainder);

    int min = remainder/MINUTE;
    //printf("min %d\n",min);
    remainder=n_time.seconds-((n_time.seconds/MINUTE)*MINUTE);
    //printf("remainder %d\n",remainder);

    int sec = remainder;
   // printf("sec %d\n",sec);

    //Assign new values to the Time struct
    n_time.days = day; n_time.hr = hours; n_time.min = min; n_time.seconds = remainder;
    

}

void printTime(Time t){
    //Proprerly format and print the time.
    if(t.days>0){
        if(t.days == 1){
            printf("%d day ",t.days);
        }
        else{
            printf("%d days ",t.days);
        }
    }
    if(t.hr>0){
        if(t.hr == 1){
            printf("%d hr ",t.hr);
        }
        else{
            printf("%d hrs ",t.hr);
        }
    }

    if(t.min>0){
       
        printf("%d min ",t.min);
        
    }
    if(t.seconds>0){
        printf("%d sec \n",t.seconds);
    }
}