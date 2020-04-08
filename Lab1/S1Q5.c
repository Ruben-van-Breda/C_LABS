#include<stdio.h>
#include<math.h>

//Prac1 question 5
//Ruben van Breda 19200704
int main(void){

    double rad; //Declaring a var to store the users input for the radians of the circle
    printf("Enter the radius of the circle:\n"); 
    scanf("%lf",&rad); // User Input

    double area = M_PI*pow(rad,2); // Calculate the area
    double cir = 2*M_PI*rad; // Calculate the circumference
    //Display results to the user
    printf("The area is %.2lf\n",area);
    printf("The circumference is %.2lf\n",cir);


    return 0;
}