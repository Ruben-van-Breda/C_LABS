#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct chain_element{
    int data;
    struct chain_element *next;
};
int main(void){
    FILE *file,*file2;
    file = fopen("counties.txt", "r");
    file2 = fopen("towns.txt", "r");

    size_t index = 0;

    if(file == NULL){
        printf("File not found");
        exit(0);
    }


    char countyName[20];
    char name[20];
    int population;
    fscanf(file2,"%s %d %s", countyName,&population,name);

    printf("%s\n",countyName);
    printf("%s\n",name);
    printf("%d\n",population);

    fscanf(file,"%s %s %u" , countyName,name,&population);

    printf("%s\n",countyName);
    printf("%s\n",name);
    printf("%d\n",population);


}
