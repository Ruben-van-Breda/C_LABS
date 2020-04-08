#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Created by Ruben van Breda 19200704

#define MAX_ROW 20
#define MAX_COL 20
#define MAX_ARRAY_LEN 20


int Random(int lowerBound,int upperLimit); // Return a random integer from 1 to the upper limit passed into the function.
bool isNumIn2DArray(int checkNum, int list[][MAX_COL],int r,int c); // Check if a number num is already in the array list and return true if it is found.

void Populate2DArray(int *a,int rowLen,int colLen);

void Display2DArray(int *a,int r, int c);
void DisplayArray(int a[MAX_ARRAY_LEN],int len);



int Intersection(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN],int output[MAX_ARRAY_LEN],int rowLen,int colLen);
void ProductOfTwo2DArrays(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN],int output[][MAX_ARRAY_LEN],int rowLen,int colLen);

void SumOfTwo2DArrays(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN],int output[][MAX_ARRAY_LEN],int rowLen,int colLen);
void SumOfTwo2DArraysByRow(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN],int output[MAX_ARRAY_LEN],int rowLen,int colLen);
//void SumOfTwo2DArraysByRow(int *a,int *b,int output[MAX_ARRAY_LEN],int rowLen,int colLen);

void SumOfTwo2DArraysByCol(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN],int output[MAX_ARRAY_LEN],int rowLen,int colLen);

int main(void){
     
    int row;
    int col;
    row = MAX_ROW+1; // initialize to a value above the upper bound
    col = MAX_COL+1; // initialize to a value above the upper bound

    // -- Declare the necessary arrays --
    int A[MAX_ARRAY_LEN][MAX_ARRAY_LEN];
    int B[MAX_ARRAY_LEN][MAX_ARRAY_LEN];

    int productAB[MAX_ARRAY_LEN][MAX_ARRAY_LEN];
    int sumAB[MAX_ARRAY_LEN][MAX_ARRAY_LEN];
    int sumRowAB[MAX_ROW];
    int sumColAB[MAX_COL];
    int intersectionAB[MAX_ARRAY_LEN];
    

    // Set random seed
    srand(time(NULL));

    //Get Input from user
    while(col>MAX_COL||col<=0){
        printf("Enter the amount of rows and columns for both Matrices: ");
        scanf("%d", &col);
        printf("OUT");
    }

    while(row>MAX_ROW||row<=0){
        printf("Enter the amount of rows for both Matrices: ");
        scanf("%d",&row);
    }


   printf("OUT");


    // Logic Of Program
    Populate2DArray(A,row,col);

    Populate2DArray(B,row,col);

    printf("_______Matrix A_______\n");
    Display2DArray(A,row,col); 
    printf("\n\n_______Matrix B_______\n");
    Display2DArray(B,row,col);

    printf("\n\nProduct of A and B\n");
    ProductOfTwo2DArrays(A,B,productAB,row,col);
    Display2DArray(productAB,row,col);

    printf("\n\nSum of A and B\n");
    SumOfTwo2DArrays(A,B,sumAB,row,col);
    Display2DArray(sumAB,row,col);
    
    printf("\n\nSum by Row of A and B\n");
    SumOfTwo2DArraysByRow(A,B,sumRowAB,row,col);

    DisplayArray(sumRowAB,row);

    printf("\n\nSum by Col of A and B\n");
    SumOfTwo2DArraysByCol(A,B,sumColAB,row,col);
    DisplayArray(sumColAB,row);
    printf("\n");
    int commonElements = Intersection(A,B,intersectionAB,row,col);
    printf("\nThere are %d elements in common of A and B\n",commonElements);


   
    

    return 0;
}

// void Display2DArray(int a[][MAX_COL],int row, int col){
//     for (int r = 0; r < row; r++)
//     {   printf("\n");
//         for (int c = 0; c < col; c++)
//         {
//             printf("%d ",a[r][c]);
//         }
        
//     }
// }
void Display2DArray(int *a,int row, int col){

    // Print 2D array
    for (int r = 0; r < row; r++)
    {   printf("\n");
        for (int c = 0; c < col; c++)
        {
            printf("%d ",a[r*MAX_ARRAY_LEN+c]);
        }
        
    }
}

void DisplayArray(int a[MAX_ARRAY_LEN],int len){

    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}

int Intersection(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN], int out[MAX_ARRAY_LEN],int rowLen,int colLen){
    /*  Return the count of common elements found in both matrix A and matrix B*/
    int commonElements = 0;
    //Ensure that the same number is not counted twice.
    int occurrence = 0;
    
    for (int r = 0; r < MAX_ARRAY_LEN; r++)
    {
        for (int c = 0; c < MAX_ARRAY_LEN; c++)
        {
           int num = a[r][c];
           if(isNumIn2DArray(num,b,rowLen,colLen)){
               //Check for WOW
               if(a[r][c] == b[r][c]){
                   printf("\nWOW\n");
                   printf("Number at row %d and column %d is %d in both matrices",r,c,num);
               }
               out[commonElements] = num;
               //Ensure that the same number is not counted twice.
               occurrence = 0;
               // Loop through the output out array
               for(size_t i = 0; i < MAX_ARRAY_LEN;i++){
                   if(num==out[i]){
                       occurrence++;
                   }
                   
                }
            if(occurrence >= 1){
                
                commonElements++;

                
            }
        }
        
        }
        
    }

    
    if(commonElements==0){
        printf("\nNo elements in common.\n");
    }
    // Return commonElements
    return commonElements;
} 

void ProductOfTwo2DArrays(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN], int out[][MAX_ARRAY_LEN],int row,int col){
    
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
           // Store the product of the matrix A and B into the array out
           out[r][c] = a[r][c] * b[r][c];
        }    
    } 
}
void SumOfTwo2DArrays(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN], int out[][MAX_ARRAY_LEN],int rowLen,int colLen){
    
  

    for (int r = 0; r < rowLen; r++)
    {
        for (int c = 0; c < colLen; c++)
        {
           // Sum of matrix A and B
           out[r][c] = a[r][c] + b[r][c];
        }    
    } 
}
// void SumOfTwo2DArraysByRow(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN], int out[],int rowLen,int colLen){
    
//     for (int r = 0; r < rowLen; r++)
//     {
//         for (int c = 0; c < colLen; c++)
//         {
           
//            out[r] += a[r][c] + b[r][c];
//         }    
//     } 
// }

// void SumOfTwo2DArraysByRow(int *a,int *b, int out[],int rowLen,int colLen){
    
//     //Initialize out array
//     for(size_t i = 0;i<rowLen;i++){
//         out[i] = 0;
//     }

//     for (int r = 0; r < rowLen; r++)
//     {
//         for (int c = 0; c < colLen; c++)
//         {
           
//            out[r] += a[r*MAX_ARRAY_LEN*c] + b[r*MAX_ARRAY_LEN*c];
//         }    
//     } 
// }

void SumOfTwo2DArraysByRow(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN],int out[],int rowLen,int colLen){
    
     //Initialize out array
    for(size_t i = 0;i<rowLen;i++){
        out[i] = 0;
    }

    for (int r = 0; r < rowLen; r++)
    {
        for (int c = 0; c < colLen; c++)
        {   //Sum rows the matrices
            out[r] += a[r][c] + b[r][c];
        }
    }
}

void SumOfTwo2DArraysByCol(int a[][MAX_ARRAY_LEN],int b[][MAX_ARRAY_LEN],int out[],int rowLen,int colLen){
    
     //Initialize out array
    for(size_t i = 0;i<rowLen;i++){
        out[i] = 0;
    }

    for (int c = 0; c < colLen; c++)
    {
        for (int r = 0; r < rowLen; r++)
        {
            //Sum col the matrices
            out[c] += a[r][c] + b[r][c];
        }
    }
}


void Populate2DArray(int *a, int rowLen,int colLen){
    //printf("entered");
    for (size_t r = 0; r < rowLen; r++)
    {
        for (size_t c = 0; c < colLen; c++)
        {
            int randNum = Random(100,1500);
            while(isNumIn2DArray(randNum,a,rowLen,colLen)){
                randNum = Random(100,1500);
            }
            a[r*MAX_ARRAY_LEN+c] = randNum;
        }
        
    }
    
}
/*  Generate a random number */
int Random(int lowerBound,int upperlimit){
    return rand() % (upperlimit-lowerBound) + 1 + lowerBound;
}

// Check if a number num is already in the array list and return true if it is found.
bool isNumIn2DArray(int num,int list[][MAX_COL],int r,int c){

    for (int i = 0; i < r; i++)
    {   
        for (int j = 0; j < c; j++)
        {
            // Checks if the current number in the list is equal to the check num
            if(list[i][j] == num){
                return true;
            }
        }
        
        
    }

    return false;
    

}
// bool isNumIn2DArray(int num,int *list,int r,int c){

//     for (int i = 0; i < r; i++)
//     {   
//         for (int j = 0; j < c; j++)
//         {
//             // Checks if the current number in the list is equal to the check num
//             if(list[i*MAX_ARRAY_LEN+j] == num){
//                 return true;
//             }
//         }
        
        
//     }

//     return false;
    

// }


