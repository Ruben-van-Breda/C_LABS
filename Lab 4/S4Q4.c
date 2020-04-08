#include <stdio.h>
#include <stdbool.h>

/* Ruben van Breda,
    19200704
*/

bool isVowel(char ch);
bool isNum(char ch);
char ToLowerCase(char ch);

int main(void){

    char *str; // Declare a pointer to a address of char base type
    int vowels = 0;
    int consts = 0;
    int numbers = 0;
    
    printf("Enter a string (max 100 characters with no spaces):\n");
    fgets(str,100,stdin); // Gets input from user
    
    /* While the memory address at which the pointer pointing to is not empty*/
    while(*str != '\0'){
        
        // Checks if the next byte of the str pointer which is interpreted as char is a vowel 
        if(isVowel(*str)){
            vowels++;
        }
        // Checks if the ASCII code of the current byte is a character [A-Z,a-z]
        else if((*str >= 65 && *str<=90) || (*str>=97 && *str<=122)){
            //Checks if the letter is not a vowel i.e its a Consonant
            if(!isVowel(*str)){
                consts++;
            }
        }
        // Checks if the current byte is a digit
        else if(isdigit(*str)){
            numbers++;
        }
        
        //Increment the address at which the array is pointing too by the memory size allocated to a element.
        str+=sizeof(str[0]);
    }
    // Output the results to user
    printf("Number of Vowels in String: %d\nNumber of Consonants in String: %d\nNumber of Integers in String: %d",vowels,consts,numbers);

    return 0;
}

bool isVowel(char ch){

    char vowels[5] = "aeiou";
    for (size_t i = 0; i < 5; i++)
    {
        if(ToLowerCase(ch) == vowels[i]){
            return true;
        }
    }
    
    return false;
}

bool isNum(char ch){

    if((ch >= 65 && ch<=90) || (ch>=97 && ch<=122)){
            return false;
    }
    
    //Any ascii code not a letter, this does not cover all the other characters on the ASCII table.
    else{
        return true;
    }
}

char ToLowerCase(char ch){
    //  Checks if the character is in UpperCase
    if(ch >= 65 && ch<=90){
        ch += 32; // Change character to lowercase
    }

    return ch;
}