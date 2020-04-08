#include<stdio.h>

//Prac1 question 2
//Ruben van Breda 19200704

#define MAX_LEN 7
int main(void)
{
    char sn[MAX_LEN];
    int sum = 0;

    printf("Enter student number:\n");
    scanf("%s",sn);

    for(int i = 0;i<=MAX_LEN;i++){
        sum += sn[i] - '0'; // the - '0' converts it from characters to ints ASCII table
        printf("%c\n",sn[i]);

       
    }
    // OUTPUT TO USERS
    printf("Sum = %d\n",sum);
    
    return 0;
}