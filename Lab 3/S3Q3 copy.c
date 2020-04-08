#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_ROW 20
#define MAX_COL 20

void Display2DMatrix(int matrix[][MAX_COL],int rowLen,int colLen);
void ProductOfMatrixAB(int a[][MAX_COL],int rowALen,int colALen,int b[][MAX_COL],int rowBLen,int colBlen,int output[][MAX_COL]);
int main(void){

    int row1 = -1,row2 = -1;
    int col1 = -1,col2 = -1;

    int A[MAX_ROW][MAX_COL];
    int B[MAX_ROW][MAX_COL];
    


    //Input 1

    // Get size
    while(row1>MAX_ROW||row1<=0){
        printf("Enter the amount of rows for matrix A: ");
        scanf("%d",&row1);
    }

    while(col1>MAX_COL||col1<=0){
        printf("Enter the amount of col for matrix A: ");
        scanf("%d",&col1);
    }
    // Get values for matrix
    printf("Please enter values for martix A:\n");
    for (size_t r = 0; r < row1; r++)
    {
        for (size_t c = 0; c < col1; c++)
        {
            scanf("%d",&A[r][c]);
        }
        
    }

    //  Input 2
    while(row2>MAX_ROW||row2<=0){
        printf("Enter the amount of rows for matrix B: ");
        scanf("%d",&row2);
    }
    // Get size
    while(col2>MAX_COL||col2<=0){
        printf("Enter the amount of col for matrix B: ");
        scanf("%d",&col2);
    }
    // Get values for matrix
    printf("Please enter values for martix B:\n");
    for (size_t r = 0; r < row2; r++)
    {
        for (size_t c = 0; c < col2; c++)
        {
            scanf("%d",&B[r][c]);
        }
        
    }
    
    printf("_______Matrix A_______\n");
    Display2DMatrix(A,row1,col1);

    printf("\n_______Matrix B_______\n");
    Display2DMatrix(B,row2,col2);

    //Matrix dimensions check
    if(row1==col2){
        int productAB[row1][col2];
        ProductOfMatrixAB(A,row1,col1,B,row2,col2,productAB);
        printf("\nPoduct of A and B\n");
        Display2DMatrix(productAB,row1,col2);
    }
    else{
        printf("Cant multiply %dx%d by %dx%d",row1,col1,row2,col2);
    }
    
    

    
    return 0;
}

void ProductOfMatrixAB(int a[][MAX_COL],int rowAlen,int colAlen,int b[][MAX_COL],int rowBlen,int colBlen,int output[][MAX_COL]){
    int sum = 0;
    int colCount = 0;

    //Initialize the output array
    
    for(size_t i = 0;i<rowAlen;i++){
        for(size_t j = 0;j<colBlen;j++){
            output[i][j] = 0;
        }
    }



    for (size_t i = 0; i < rowAlen; i++)
    {
        
        sum=0;
        for (size_t j = 0; j < colBlen; j++)
        {   
            
            for(size_t k = 0;k<colAlen;k++){
                output[i][j]+=a[i][k]*b[k][j];
            }

        }
       

        colCount++;
        
    }

    
}
 

void Display2DMatrix(int matrix[][MAX_COL],int rowLen,int colLen){
    for (size_t i = 0; i < rowLen; i++)
    {   
        printf("\n");
        for (size_t j = 0; j < colLen; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        
    }
    printf("\n");
    
}