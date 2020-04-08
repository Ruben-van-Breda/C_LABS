#include <stdio.h>
#include <string.h>


//Ruben van Breda. 19200704


#define MAX_LINES 80
#define MAX_CHAR 80

void ReadLinesFromFile(char sentence[MAX_LINES][MAX_CHAR],char *filePath);
void WriteToFile(char *filePath,char inputString[MAX_CHAR]);

void Display2DArray(char inputString[][MAX_CHAR], int lineCount);
int GetFileLineCount(char *filePath);

void GetWordsByIndex(char senetence[][MAX_CHAR], int lineCount, char words[MAX_LINES][MAX_CHAR], int wordNum);



char *filename = "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/Lab 5/myFile.txt";
char *fileOutput = "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/Lab 5/outputFile.txt";


int main(void){

    char const *CITY = "Dublin";
    char sentences[MAX_LINES][MAX_CHAR];

    
    //Read from File
    ReadLinesFromFile(sentences,filename);
    int lineCount = GetFileLineCount(filename); // Get the number of lines in file.

    
    char cities[MAX_LINES][MAX_CHAR];
    GetWordsByIndex(sentences, lineCount + 1, cities, 1); // Create an array with all the words at the specified position of each sentences for all the rows

    char share[MAX_LINES]; // An array for all the premission identitfiers (1 share, 0 no) on the input file.
 
    for (size_t i = 0; i < lineCount; i++)
    {
        //Get the character of the last character of the sentence. ( the premission )
        share[i] = sentences[i][strlen(sentences[i]) - 1];
    }

    // Loop through the cities
    for (size_t i = 0; i < lineCount; i++)
    {
        
        int s = share[i] - '0';

        //Check that the city is Dublin
        if (strcasecmp(cities[i], CITY) == 0)
        {
            //Check if the share is true (premission)
            if (s == 1)
            {
                printf("%s\n",sentences[i]);
                WriteToFile(fileOutput,sentences[i]); //Write to output file
            }
        }
    }

    return 0;
}

void ReadLinesFromFile(char sentence[MAX_LINES][MAX_CHAR],char *filename){
    //Populates the given array with the content of a file

    FILE *file;
    char line[MAX_CHAR];
    int lineCount = 0;

    //Initialise sentence
    for (int j = 0; j < MAX_LINES; ++j)
    {
        for (int i = 0; i < MAX_CHAR; ++i)
        {
            sentence[j][i] = '\0';
        }
    }


    //char *filename = "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/Lab 5/myFile.txt";
    file = fopen(filename, "r"); // Open/Read file in the current directory
    if (file == NULL)
    {
        printf("Could not open file %s", filename);
    }


    int lineLength = 0;

    //Initialise Arrat
    for (int j = 0; j < MAX_LINES; ++j)
    {
        for (int i = 0; i < MAX_CHAR; ++i)
        {
            sentence[j][i] = '\0';
        }
    }

    //Read contents
    while (fgets(line, MAX_CHAR, file))
    {

        //Loop through the characters in line
        for (int i = 0; i <= strlen(line); i++)
        {

            if (line[i] == '\n')
            {
                sentence[lineCount][lineLength] = '\0';
            }

            if (line[i] != '\n')
            {
                sentence[lineCount][lineLength] = line[i];
                //printf("%c",sentence[lineCount][lineLength]);
                lineLength++;
            }
        }

        lineCount++;
        lineLength = 0;
        //printf("\n");
    }

    if (sentence[lineCount][lineLength] == '\0' && lineLength == 1)
    {
        lineCount--;
    }

    fclose(file);
}
int GetFileLineCount(char *filePath){

    int lineCount = 0;
    FILE *file;
    char line[MAX_CHAR];

    char *filename = filePath;
    file = fopen(filename, "r"); // Open,Read file in the current directory
    if (file == NULL)
    {
        printf("Could not open file %s", filename);
    }

    //Read the file
    while (fgets(line, MAX_CHAR, file))
    {
        //Increase the lineCounter
        lineCount++;
    }

    fclose(file);
    return --lineCount;
}


void Display2DArray(char inputString[][MAX_CHAR], int lineCount){
    for (size_t i = 0; i < lineCount; i++)
    {
        printf("%s\n", inputString[i]);
    }
}

void GetWordsByIndex(char senetence[][MAX_CHAR], int lineCount, char words[MAX_LINES][MAX_CHAR], int wordNum){
    /*  Takes in a input string it populates the words with all words in the index of wordNum*/

    //Returns the word at the index of wordNum ignoring all whitespaces.
    int wordIndex = 0;
    int wordCharCount = 0;
    int count = -1;
    char str[MAX_CHAR];
    wordNum--; //1 is index 0

    //Initilize
    for (size_t i = 0; i < MAX_LINES; i++)
    {
        for (size_t j = 0; j < MAX_CHAR; j++)
        {
            words[i][j] = '\0';
        }
    }

    // Loop through the lines
    for (size_t i = 0; i < lineCount; i++)
    {
        //The number of words to skip till at wordNum index
        count = 0;
        wordCharCount = 0;
        for (size_t j = 0; j < MAX_CHAR; j++)
        {
            // End of word
            if ((senetence[i][j] == '\t') || (senetence[i][j] == ' ') || (senetence[i][j] == '\0'))
            {
                //While the count is not at word count increase count and move to next character
                if (count < wordNum)
                {
                    count++;
                    continue;
                }

                //Increase the word index
                wordIndex++;

                if (wordIndex >= wordNum)
                {

                    wordCharCount = 0;
                    break;
                }
            }
            // Check if count is at the right index for the word specified by wordNum
            if (count == wordNum)
            {
                if (senetence[i][j] != '\t' && senetence[i][j] != '\0')
                {
                
                    //set the words to the current character in sentence
                    words[wordIndex][wordCharCount] = senetence[i][j];
                    wordCharCount++;
                }
            }
        }


    }
}

void WriteToFile(char *fileOutput,char inputString[MAX_CHAR]){
    
    FILE *fp;
 
    fp = fopen(fileOutput, "a"); // Open/Read file in the current directory
    //Check that the file pointer is null
    if (fp == NULL)
    {
        printf("Error!");

    }
    const char *text = inputString;
    //Append to file the text 
    fprintf(fp,"%s\n",text);
    //Close the file
    fclose(fp);
}