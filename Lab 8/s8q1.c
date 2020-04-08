#include <stdio.h>
#include <stdlib.h>

typedef struct county{
    char *longName;
    char *shortName;
    unsigned int population;
}county;

typedef struct town{
    char *name;
    unsigned int population;
    struct county aCounty;
} town;


int main(void){
    FILE *file; //file = countries.txt file pointer
    struct county counties[10];
    county *myCounty[5];
    if((file = fopen("counties.txt","rb")) == NULL){
        puts("File cannot be opened\n");
    }
    else{
       
        
        char longName[30];
        
        int index = 0;

        // while(fread(&county,sizeof(county),1,file) == 1){
        //     printf("Name: %s \n", county->longName);
          
        // }
        while(!feof(file)){
            myCounty[index] = (county *)malloc(sizeof(county));
            myCounty[index]->longName = (char *)malloc(sizeof(char)*10);
            myCounty[index]->shortName = (char *)malloc(sizeof(char)*10);

            fscanf(file,"%s %s %d\n",myCounty[index]->longName,myCounty[index]->shortName,&myCounty[index]->population);
            
            printf("%s ",myCounty[index]->longName);
            index++;

        //     //fscanf(file,"%s %s %d\n",&myCounty.longName,&myCounty.shortName,&myCounty.population);

        //     struct county *countyList = (struct county*)malloc(sizeof(county));
        //     if(countyList == NULL){
        //         printf("Errer allocating memory for var countyList");
        //     }


            
        // //     fread(*c,sizeof(struct county),1,file);
        //         fscanf(file,"%s %s %d",&c->longName,&c->shortName,&c->population);
        // //     printf("%s %s %d\n",c->longName,c->shortName,c->population);
        }

        // // printf("%s %s %d\n",&myCounty[0].longName,&myCounty[0].shortName,&myCounty[0].population);



        
        fclose(file);

    }

    //free(myCounty);
    return 0;
}

// void ReadLinesFromFile(char sentence[MAX_LINES][MAX_CHAR],char *filePath){
//         //Populates the given array with the content of a file

//         FILE *file; // File pointer
//         char line[MAX_CHAR]; // A char array to store the text
//         int lineCount = 0; //The current LineCount


//         file = fopen(filePath,"r"); // Open/Read file in the current directory
//         if(file == NULL){
//             printf("Could not open file %s",filePath);

//         }


//         int lineLength = 0;
//         //Initialise the sentence array.
//         for (int j = 0; j < MAX_LINES; ++j) {
//             for (int i = 0; i < MAX_CHAR; ++i) {
//                 sentence[j][i] = '\0';
//             }
//         }
//         // Read the content of the file
//         while(fgets(line,MAX_CHAR,file)){
//             //Loop through the characters in line
//             for (int i = 0; i <= strlen(line); i++) {

//                 if(line[i] == '\n'){
//                     sentence[lineCount][lineLength] = '\0';
//                 }

//                 if(line[i] != '\n'){
//                     //Populate the sentence array with line
//                     sentence[lineCount][lineLength] = line[i];
//                     lineLength++;
//                 }


//             }


//             lineCount++; // Increase the lineCount
//             lineLength = 0; // Reset the lineLength

//         }

//         if(sentence[lineCount][lineLength] == '\0' && lineLength == 1){
//             lineCount--;
//         }

//         fclose(file); // Close the file

// }