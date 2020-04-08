#include<stdio.h>

//Prac1 question 1
//Ruben van Breda 19200704

#define MAX_HEIGHT 10
int main(void){

    int count = 0; double avg = 0;
    int heights[MAX_HEIGHT];
    int tallest = -100000; //Defualt value, smaller than any probable height
    int smallest = 100000; //Defualt value,greater than any probable height

    /*  Input   */
    printf("enter the number of people:\n");
    scanf("%d",&count); // store the number of people in count
    // Loop through and get input for the heights from the user
    for(int i = 0;i<count;i++){
        scanf("%d",&heights[i]);
    }

    /*  Logic   */

    // Loop through the heights
    for (int i = 0; i < count; i++)
    {
        avg += heights[i];
        if(heights[i]>=tallest){
            tallest = heights[i];
        }

        if(heights[i]<=smallest){
            smallest = heights[i];
        }
    }
    avg = avg / count;
    // Output
    printf("Avg = %.2f\nTallest = %d\nSmallest = %d\n", avg, tallest, smallest);
    return 0;
}