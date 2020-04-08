#include <stdio.h>
#include <stdarg.h>

//Ruben van Breda 19200704

int adder(int args,...);
int multiplier(int args,...);
int myPrinter(const char *format,...);


int main(void){

    printf("Sum = %d\n",adder(2,41,2));
    printf("Product = %d\n",multiplier(2,4,3));
    myPrinter("cdd",'R',99,87);


}



int adder(int args,...){
    va_list ap;
    /* initialize ap for num number of arguments */
    va_start(ap,args);
    int sum = 0;
    for (size_t i = 0; i < args ; i++)
    {
        sum += va_arg(ap,int);

    }
    

    va_end(ap);
    return sum;
}


int multiplier(int args,...){
    va_list ap;
    /* initialize ap for num number of arguments */
    va_start(ap,args);
    int product = 1;
    for (size_t i = 0; i < args ; i++)
    {
        product *= va_arg(ap,int);

    }
    
    /* clean memory allocated for ap */
    va_end(ap);
    return product;
}

int myPrinter(const char *format,...)
{
    //Takes in a string of arguments and prints the arguments accroding to their type given in the string
    va_list args;
    int count;
    /* initialize ap for num number of arguments */
    va_start(args, format);
    char c; // Declare a char var if a char is an argument.

    while (*format != '\0') {
        switch (*format++) {
            case 's':
                fprintf(stdout, "%s\n", va_arg(args, const char *));
                break;
            case 'c':
                c = (char)va_arg(args, int);
                printf("%c\n",c);
                // fprintf(stdout, "%c\n", count, c);
                break;
            case 'd':
                fprintf(stdout, "%d\n", va_arg(args, int));
                break;
            case 'f':
                fprintf(stdout, "%f\n", va_arg(args, double));
                break;
        }
    }
    va_end(args);
    return 0;
}

