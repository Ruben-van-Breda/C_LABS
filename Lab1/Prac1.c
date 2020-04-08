#include<stdio.h>

//Prac1 question 1
//Ruben van Breda 19200704
int main(void){

    int count = 3;
    int heights[3] = {150, 156,132};
    double avg = 0;
    int tallest = heights[0]; //Assign the tallest to the first persons height
    int smallest = 100000; //Greater than any height


    // Loop through the heights
    for (int i = 0; i < count; i++)
    {
        avg += heights[i];
        if(heights[i]>=tallest){
            smallest = tallest;
            tallest = heights[i];
        }

        if(heights[i]<=smallest){
            smallest = heights[i];
        }
    }
    avg = avg / count;
    // Output
    printf("Avg = %.2f\nTallest = %d\nSmallest = %d", avg, tallest, smallest);
    return 0;
}