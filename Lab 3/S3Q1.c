#include <stdio.h>

/*
    Write a C program which is used to keep track of the number of cars in the local multistory carpark.
    The program should have four functions, one which is called when a car enters the carpark and one which is called when a car leaves the carpark. 
    It costs €5 to enter the carpark and a separate function should keep a track of the total amount of money that has been taken and print that to the screen. 
    The final function should report the current number of cars in the carpark. 
    Provide test code in the main function ( by calling your functions) to demonstrate the program. 
    The program must demonstrate the use of a global variable and a local static variable.
*/
int car_count = 0;
double money = 0;

#define COST 5

void EnteredCarPark();
void LeavesCarPark();
int AmountOfCars();
void AmountOfMoney();

int main(void){

    EnteredCarPark();
    EnteredCarPark();
    EnteredCarPark();
    AmountOfMoney();


    
    return 0;
}

void EnteredCarPark(){
    
    car_count++;
    
}

int AmountOfCars(){
    return car_count;
}
void AmountOfMoney(){
    double total = 0;
    for (int i = 1; i < car_count; i++)
    {
        printf("%d €%d\n",i,COST);
        total += COST;
    }
    printf("TOTAL : €%.2lf\n\n",total);
    
}

