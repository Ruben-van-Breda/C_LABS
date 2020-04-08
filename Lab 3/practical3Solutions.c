#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Question 1

int numberOfCars = 0;

void enterCarPark(void)
{
    numberOfCars++;
    calculateSum();
}

void exitCarPark(void)
{
    if (numberOfCars > 0)
    {
        numberOfCars--;
    }
}

int calculateSum(void)
{
    static int sum = 0; //static
    sum += 20;
    printf("Current Sum: %d\n", sum);
    return sum;
}

int currentnumberOfCars(void)
{
    return numberOfCars;
}

//Question 2
bool checkDuplicates(int rows, int columns, int array[][columns], int entry)
{
    /*
    Checks for copy values in the array
    - Accepts the row and column count, array under consideration and the value checked for
    - returns a boolean
  */

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j] == entry)
            {
                return false;
            }
        }
    }
    return true;
}

void populateTheArrays(int rows, int columns, int array[][columns])
{
    /*
    Populates the array (in place) with random values, checks for duplicates using the checkDuplicates method.
  */
    int entry;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            entry = rand() % 1401 + 100;
            while (!checkDuplicates(rows, columns, array, entry))
            {
                entry = rand() % 1401 + 100;
            }
            array[i][j] = entry;
        }
    }
}

void cellProduct(int rows, int columns, int firstArray[][columns], int secondArray[][columns], int cellByCellProductOfBothArrays[][columns])
{
    /*
    Performs a cell by cell prod operation on two arrays (in place)
  */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cellByCellProductOfBothArrays[i][j] = firstArray[i][j] * secondArray[i][j];
        }
    }
}

void cellSum(int rows, int columns, int firstArray[][columns], int secondArray[][columns], int cellByCellSumOfBothArrays[][columns])
{
    /*
     Performs a cell by cell sum operation on two arrays (in place)
  */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cellByCellSumOfBothArrays[i][j] = firstArray[i][j] + secondArray[i][j];
        }
    }
}

void rowSum(int rows, int columns, int firstArray[][columns], int secondArray[][columns], int rowByRowSumOfBothArrays[])
{
    /*
     Performs a row by row sum operation on two arrays (in place)
  */

    int sumA;
    int sumB;
    for (int i = 0; i < rows; i++)
    {
        sumA = 0;
        sumB = 0;
        for (int j = 0; j < columns; j++)
        {
            sumA += firstArray[i][j];
            sumB += secondArray[i][j];
        }
        rowByRowSumOfBothArrays[i] = sumA + sumB;
    }
}

void columnSum(int rows, int columns, int firstArray[][columns], int secondArray[][columns], int columnByColumnSumOfBothArrays[])
{
    /*
     Performs a column by column sum operation on two arrays (in place)
  */

    int sumA;
    int sumB;
    for (int i = 0; i < columns; i++)
    {
        sumA = 0;
        sumB = 0;
        for (int j = 0; j < rows; j++)
        {
            sumA += firstArray[j][i];
            sumB += secondArray[j][i];
        }
        columnByColumnSumOfBothArrays[i] = sumA + sumB;
    }
}

int intersectionOfBothArrays(int rows, int columns, int firstArray[][columns], int secondArray[][columns])
{
    /*
     Performs an intersection on both arrays for similar values.
     - Calls checkDuplicates()
     - returns the number of similar elements in both arrays
  */
    int elements = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (!checkDuplicates(rows, columns, secondArray, firstArray[i][j]))
            {
                elements++;
            }
        }
    }
    return elements;
}

void wowChecker(int rows, int columns, int firstArray[][columns], int secondArray[][columns])
{
    /*
     Performs cell-wise intersection on both arrays
     - prints wow if it occurs
  */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (firstArray[i][j] == secondArray[i][j])
            {
                printf("Wow ! \n");
            }
        }
    }
}

void prettyPrintArray(int rows, int columns, int array[][columns])
{
    /*
     Helper function to print 2D array
  */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%7d ", array[i][j]);
        }
        puts("");
    }
}

// Question 3

void matrixMuplication(int row1, int col1, int row2, int col2, int firstArray[][col1], int secondArray[][col2], int ResultArray[row1][col2])
{
    int sum;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            sum = 0;
            for (int k = 0; k < row2; k++)
            {
                sum += firstArray[i][k] * secondArray[k][j];
            }
            ResultArray[i][j] = sum;
        }
    }
}

int main(void)
{

    srand(time(NULL));

    int rows = 0;
    int columns = 0;

    printf("How many rows: ");
    scanf("%d", &rows);
    printf("How many columns: ");
    scanf("%d", &columns);

    // declare array objects
    int firstArray[rows][columns], secondArray[rows][columns], cellByCellProductOfBothArrays[rows][columns], cellByCellSumOfBothArrays[rows][columns];
    int rowByRowSumOfBothArrays[rows], columnByColumnSumOfBothArrays[columns];

    // int ResultArray[row1][col2]; //abide by the conditions of matrix multiplication

    populateTheArrays(rows, columns, firstArray);
    populateTheArrays(rows, columns, secondArray);
    cellProduct(rows, columns, firstArray, secondArray, cellByCellProductOfBothArrays);
    cellSum(rows, columns, firstArray, secondArray, cellByCellSumOfBothArrays);
    rowSum(rows, columns, firstArray, secondArray, rowByRowSumOfBothArrays);
    columnSum(rows, columns, firstArray, secondArray, columnByColumnSumOfBothArrays);

    printf("-------Array 1-------------\n");
    prettyPrintArray(rows, columns, firstArray);
    printf("-----------------------------\n");

    printf("-------Array 2--------------\n");
    prettyPrintArray(rows, columns, secondArray);
    printf("-----------------------------\n");

    printf("------Array Product (cell)---------------------\n");
    prettyPrintArray(rows, columns, cellByCellProductOfBothArrays);
    printf("------------------------------------------------\n");

    printf("------Array Sum (cell)--------------------------\n");
    prettyPrintArray(rows, columns, cellByCellSumOfBothArrays);
    printf("------------------------------------------------\n");

    printf("-------Array Sum (rows)--------------------------\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d ", rowByRowSumOfBothArrays[i]);
    }
    printf("\n------------------------------------------------\n");

    printf("--------Array Sum (column)----------------------\n");
    for (int i = 0; i < columns; i++)
    {
        printf("%d ", columnByColumnSumOfBothArrays[i]);
    }
    printf("\n------------------------------------------------\n");

    // prints intersection counts
    printf("Number of elements: %d\n", intersectionOfBothArrays(rows, columns, firstArray, secondArray));
    wowChecker(rows, columns, firstArray, secondArray);

    return 0;
}
