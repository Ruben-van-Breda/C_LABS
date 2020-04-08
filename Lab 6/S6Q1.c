#include <stdio.h>

//Ruben van Breda 19200704

typedef struct GameEntry
{
    char title[30];
    char developer[30];
    char platform[30];
    unsigned int year;
    int borrowed;
    char whoBorrowed[30];
    char whenBorrowed[30];


    
} GameEntry;

int DisplayMenu();
void AddEntry();
void FetchRecords();

int main(void){
    //File Pointer
    FILE *fp;
    int input;

    while((input = DisplayMenu()) != 0){
        if (input == 1)
        {
            AddEntry();
        }
        if (input == 2)
        {
            FetchRecords();
        }
 
    }
    


    return 0;
}

int DisplayMenu(){

    /* Display a menu for the user to interact with 
    and return the users input */
    puts("_________Ultimate Games________\n");
    puts("1) Add Entry");
    puts("2) Fetch Records");
    puts("0) Exit\n");

    int input;
    scanf("%d",&input);
    return input;
}

void FetchRecords(){
    /*Fetch the data from a dat file, and printing the GameEnties to the console.*/
    FILE *fp;
    if((fp = fopen("games.dat","rb")) == NULL){
        puts("File could not be opened.");

    }
    //If the file is found
    else{


        printf("Title Platform Developer Year Borrowed by Whom and When\n"); 
        while(!feof(fp)){
            GameEntry entry = {"","","",1990,0,"",""}; //Create a new GameEntry
            int result = fread(&entry,sizeof(GameEntry),1,fp);
            if(result != 0){
                printf("%s %s %s %d %d %s %s\n",entry.title,entry.platform,entry.developer,entry.year,entry.borrowed,entry.whoBorrowed,entry.whenBorrowed);
            }
        }
    }

    fclose(fp);
}
void AddEntry(){

    /* Add a GameEntry to the games.dat file*/
    FILE *fp;

    if((fp = fopen("games.dat","rb+")) == NULL){
        puts("File could not be opened.");
            
        GameEntry entry = {"NULL","NULL","NULL",0,0,"NULL","NULL"};

        //Initialise and create a .dat file
        for (size_t i = 0; i < 100; i++)
        {
            fseek(fp,i * sizeof(GameEntry), SEEK_SET);
            fwrite(&entry,sizeof(struct GameEntry),1,fp);


        }
        fclose(fp);
        

    }
   
    // If file is found.
    else{
        puts("How many entries would you like to add: ");
        int len;
        scanf("%d",&len);
        GameEntry entry = {"","","",0,"",""}; // create a new GameEntry type 
        for(unsigned int  i = 0;i<len;i++){

            puts("Enter Entry's Details: Title Platform Developer Year, Borrowed, Whom, When");
            fscanf(stdin,"%s%s%s%d%d%s%s", entry.title,entry.platform,entry.developer, &entry.year,&entry.borrowed,entry.whoBorrowed,entry.whenBorrowed);
            printf("\n%s%s%s%d%d%s%s", entry.title,entry.platform,entry.developer, entry.year,entry.borrowed,entry.whoBorrowed,entry.whenBorrowed);
            fseek(fp,i * sizeof(GameEntry), SEEK_SET);
            fwrite(&entry,sizeof(struct GameEntry),1,fp);
        }
        fclose(fp);
    }
}