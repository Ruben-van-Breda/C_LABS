#include <stdio.h>

#define MAX 30
//Structures
typedef struct zip_custs{
    int zip_code;
    int customer_count;
}zip_custs;
//Prototypes
void write_to_dat_file(struct zip_custs *n_zc,int len);

const char *CUSTOMERS_FILE_PATH = "customers.dat";

int main(void){

    int myCustomers [5][2] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22}, {85446, 88}};
    zip_custs zc[5] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22}, {85446, 88}};
    write_to_dat_file(zc,5);

    return 0;
}

void write_to_dat_file(struct zip_custs *n_zc,int n_len){

    FILE *fp;
    int myCustomers [5][2] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22}, {85446, 88}};

    if((fp = fopen(CUSTOMERS_FILE_PATH,"rb+")) == NULL){perror("Error"); exit(0);}
    //Loop through the customers
    for (int i = 0; i < n_len; ++i) {
        printf("%d ",n_zc[i].zip_code);
        printf("%d ",n_zc[i].customer_count);
        //Write to the dat file
        fwrite(n_zc,sizeof(zip_custs),1,fp);
    }
    fclose(fp);






}

