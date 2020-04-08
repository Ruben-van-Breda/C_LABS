#include <stdio.h>
#include <stdlib.h>

/* Ruben van Breda 
    s8q2 
    19200704
   
   Hide Assignment Information
Instructions
Use dynamic memory allocation (calloc, realloc) to write a C Program which achieves the

following:

• Prompts the user to enter the type (integer or float) and number of elements they

wish to store in an array

• Create sufficient memory to store the array

• Ask the user to enter each of the values they want to store

• After all elements have been entered and stored in the array, calculate the average

and print to the screen.

• Ask the user if there are more elements to be added to the array, if yes, prompt the

user to enter the number of additional elements.

• Reallocate sufficient memory to the array to store the new number of elements

• Ask the user to enter each of the new values they want to store

• After all the new elements have been entered and stored in the array, calculate the

average and print to the screen.
    */


//enum Type to reference what data type is needed
typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} TYPE;

void array_input(int *n_ptr, float *n_ptr2,float *sum, int element_count,TYPE n_type);

int main(void){


    int *ptr; // a pointer to an int
    float *ptr2; // a pointer to a float
    int n,n2; // the number of elements for the array, n2-> the amount of elements to be added to n elements 
    int data_type,size_factor,response;
    float sum = 0;


    printf("Enter the data type:\n1) Integer\n2) Float\n");
    scanf("%d", &data_type);

    printf("Enter the amount of elements: ");
    scanf("%d", &n);


    //Check what data type the user specify
    switch(data_type){
        //INTEGER
        case 1:
            size_factor = sizeof(int);
            ptr = (int*)malloc(n * size_factor); //Allocate memory to the pointer

            if(ptr == NULL){
                printf("Error! memory not allocated\n");
                exit(0);
            }
            array_input(ptr,ptr2,&sum,n,INT);
            //print the average of the elements entered by the user
            printf("average is %.2f\n",sum/n);
            //Prompt user
            printf("Are there more elements to be added to the array?:\n1)Yes\n2)No\n");
            scanf("%d",&response);
            //If they said yes and want to add more elements
            if(response == 1){
                printf("Enter how many elements to be added: ");
                scanf("%d", &n2);
                ptr = (int*)calloc(n2,n2*size_factor);

                if (ptr == NULL)
                {
                    printf("Error! memory not allocated\n");
                    exit(0);
                }
                //Get the input for the new elements
                for (int i = n; i < n+n2; i++)
                {   
                    printf("a[%d] -> ",i);
                    scanf("%d", ptr + i);
                    sum += *(ptr + i);
                }
                // print the average of the elements entered by the user.
                printf("average is %.2f\n",sum/(n+n2));

            }
        //Free the memory of the ptr address.
        free(ptr);
        break;
        //FLOAT
        case 2:
            size_factor = sizeof(float);
            ptr2 = (float*)malloc(n * size_factor); //Allocate memory to the pointer

            if(ptr2 == NULL){
                printf("Error! memory not allocated\n");
                exit(0);
            }
            // Get User input for the elements of the array.
            array_input(ptr,ptr2,&sum,n,FLOAT);
            printf("average is %.2f\n",sum/n);
            
            //Prompt user
            printf("Are there more elements to be added to the array?:\n1)Yes\n2)No\n");
            scanf("%d",&response);
            //If the user wants to add more elements
            if(response == 1){
                printf("Enter how many elements to be added: ");
                scanf("%d", &n2);
                ptr2 = (float*)calloc(n2,n2*size_factor); //Reallocate memory to the pointer ptr2

                if (ptr2 == NULL)
                {
                    printf("Error! memory not allocated\n");
                    exit(0);
                }

                // Enter the new elements from n
                for (int i = n; i < n+n2; i++)
                {   
                    printf("a[%d] -> ",i);
                    scanf("%f", ptr2 + i);
                    sum += *(ptr2 + i);
                }

                printf("average is %.2f\n",sum/(n+n2));
            }

        free(ptr2); // free the memory allocated to the pointer

        break;

        default:
            printf("Error unknown type\n");
            exit(0);

    }
    
    

    return 0;
}



void array_input(int *n_ptr, float *n_ptr2,float *sum, int element_count,TYPE n_type){

    //This function is asks the user to enter the elements up to element_count
    // Depending on the type passed through the appropriate code will be executed according to the type.

    printf("Enter the elements:\n");
    if(n_type == INT){
        //Loop through and retrieve the values from the user
        for (size_t i = 0; i < element_count; i++)
        {
            printf("a[%d] -> ",i);
            scanf("%d", n_ptr + i);
            *sum += *(n_ptr + i);
        }
    }
    else if(n_type == FLOAT){
        //Loop through and retrieve the values from the user
        for (size_t i = 0; i < element_count; i++)
        {
            printf("a[%d] -> ",i);
            scanf("%f", n_ptr2 + i);
            *sum += *(n_ptr2 + i);
        }
    }

    
   
}