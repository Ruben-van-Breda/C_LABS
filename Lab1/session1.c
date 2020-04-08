#include <stdio.h>
#include <math.h>
int main()
{
    //--------  Question 1
    int i, j, k;
    int max, avg, min;

    printf("Enter the first height value :");
    scanf("%d", &i);

    printf("Enter the second height value :");
    scanf("%d", &j);

    printf("Enter the third height value :");
    scanf("%d", &k);

    if (i >= j && i >= k)
        max = i;
    else if (j >= i && j >= k)
        max = j;
    else
        max = k;

    if (i <= j && i <= k)
        min = i;
    if (j <= i && j <= k)
        min = j;
    if (k <= i && k <= j)
        min = k;

    int sum = i + j + k;
    avg = sum / 3;

    printf("The largest number is %d \n", max);
    printf("The smallest number is %d \n", min);
    printf("The average number is %d \n", avg);

    // -----------question 2

    unsigned long long value;
    int noOfDigits;
    int sumOfNumbers = 0;
    printf("How many digits: ");
    scanf("%d", &noOfDigits);

    printf("Enter your student number :");
    scanf("%llu", &value);
    int newDivider = noOfDigits - 1;

    for (int i = 0; i < noOfDigits; i++)
    {
        int denominator = pow(10, newDivider);
        int newValue = value / denominator;
        sumOfNumbers = sumOfNumbers + newValue;
        printf("%d \n", newValue);
        value = value % denominator;

        newDivider = newDivider - 1;
    }
    printf("The sum of the numbers is %d \n", sumOfNumbers);


    //--------------- question 3

    bool isPrime(int n)
    {
        int i;
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return i == n;
    }

    int main(void)
    {
        int n;
        printf("enter a number to check if it is prime: ");
        scanf("%d", &n);
        isPrime(n) ? printf("is prime") : printf("not prime");
        return 0;
    }

    //------------------ question 4

    int main(void)
    {
        int year;
        printf("Enter a year to see if it is a leap year: \n");
        scanf("%d", &year);
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    printf("%d is a leap year. \n", year);
                }
                else
                {
                    printf("%d is not a leap year. \n", year);
                }
            }

            else
            {
                printf("%d is a leap year. \n", year);
            }
        }
        else
        {
            printf("%d is not a leap year. \n", year);
        }
        return 0;
    }

    //------------------------ question 5
#define PI 3.14159265358979323846

    int main()
    {
        double radius, area, circumference;

        printf("Please enter the radius: ");
        scanf("%lf", &radius);
        if (radius < 0)
        {
            printf("Radius value cannot be negative \n");
        }
        else
        {
            area = PI * radius * radius;
            circumference = 2 * PI * radius;
            printf("\nThe area of the circle is %.2lf and the circumference of the circle is %.2lf", area, circumference);
        }
        return 0;
    }