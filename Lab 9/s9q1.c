#include <stdio.h>
#include <stdlib.h>

/*  Ruben van Breda 
    s9q1.c
    Write a C code snippet which creates 5 structs from the integer array (myCustomers) 
    and writes each struct to a binary file named cutomers.dat.
    19200704*/

#define NUM_OF_CUSTOMERS 5

//Structures
typedef struct zip_custs{
    int zip_code;
    int customer_count;
}zip_custs;

//Prototypes
void write_to_dat_file(struct zip_custs *n_zc,int len);
void convert_intArray_to_zipCustomer(int n_zc_array[][2],int array_size,zip_custs *out_zcPtr);
void FetchRecords();



const char *CUSTOMERS_FILE_PATH = "customers.dat";

int main(void){

    int myCustomers [5][2] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22}, {85446, 88}};
    zip_custs *zcPtr = (zip_custs *)malloc(sizeof(zip_custs) * NUM_OF_CUSTOMERS);

    convert_intArray_to_zipCustomer(myCustomers,NUM_OF_CUSTOMERS,zcPtr);
    write_to_dat_file(zcPtr,NUM_OF_CUSTOMERS);
    printf("Fetching the content\n");
    FetchRecords();


    
    
    printf("%d",zcPtr->customer_count);
    free(zcPtr);
    return 0;
}

void write_to_dat_file(struct zip_custs *n_zc,int n_len){

    FILE *fp;
    //Check that the file customers.dat exists else exit the program
    if((fp = fopen(CUSTOMERS_FILE_PATH,"rb+")) == NULL){perror("Error"); exit(0);}
    //Loop through the customers
    for (int i = 0; i < n_len; ++i) {
        printf("%d ",n_zc[i].zip_code);
        printf("%d ",n_zc[i].customer_count);
        //Write to the dat file
        fwrite(n_zc,sizeof(zip_custs),1,fp);
        n_zc++;//Increase the pointer n_zc
    }
    fclose(fp); //close the file 
}

void convert_intArray_to_zipCustomer(int n_zc_array[][2],int array_size,zip_custs *out_zcPtr){
    /*This function takes in a 2D integer array representing a customer[][] with 
        [*][0] -> zip code  
        [*][1] -> customer count in zip code area
        
        and converts it into a pointer struct of zip_custs 
        */
    //Loop through the customers
    for (size_t i = 0; i < array_size; i++)
    {   
        //assign the zipCode of the zcPtr to the zipCode of the current customer in the loop.
        out_zcPtr->zip_code = n_zc_array[i][0];
        //assign the customerCount of the zcPtr to the customerCount of the current customer in the loop.
        out_zcPtr->customer_count = n_zc_array[i][1];

        printf("%d %d\n",out_zcPtr->zip_code,out_zcPtr->customer_count);
        out_zcPtr++; //increase the zcPtr 
    }
}

void FetchRecords(){
    /*Fetch the data from a dat file, and printing the GameEnties to the console.*/
    FILE *fp;
    if((fp = fopen("customers.dat","rb")) == NULL){
        perror("File could not be found.");

    }
    //If the file is found
    else{

        while(!feof(fp)){
            // GameEntry entry = {"","","",1990,0,"",""}; //Create a new GameEntry
            zip_custs temp_zc = {0,0};

            int result = fread(&temp_zc,sizeof(zip_custs),1,fp);
            if(result != 0){
                printf("Fetched -> %d %d\n",temp_zc.zip_code,temp_zc.customer_count);
            }
        }
    }

    fclose(fp);
}

