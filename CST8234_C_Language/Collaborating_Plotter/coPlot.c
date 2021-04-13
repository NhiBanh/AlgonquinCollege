#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverse(char* string);

/*struct function: all variables will paased */
struct theNameOfTheWorld {
    char bitO[100] ; /*Input character*/
    int num1; /*The first num of input*/
    int num2; /*The second num of input*/
    int sum; /*The result */
    char * string; /*input the reserve string*/
};



int main(){
    struct theNameOfTheWorld command;

    while(1){

        printf(">> Please enter a command to run.\n");
        scanf("%s", command.bitO);

        /*If the use wanna exit*/
        if (strcmp(command.bitO, "exit") == 0 || strcmp(command.bitO,"EXIT") == 0)
        {
            printf("Have a great day. \n Good Bye!");
            break;
        /*If user input is bitwise OR of the two specified integers*/
        } else if(strcmp(command.bitO, "bit_or") == 0|| strcmp(command.bitO, "BIT_OR") == 0 )

        /*strcmp true false */
        {
            /*Scan number from user*/
            scanf("%d%d", &command.num1, &command.num2);

            /*Doing bit or*/
            command.sum = command.num1 | command.num2;

            /*print the sum result*/
            printf("%d\n", command.sum);

         /*If user input is bit_and. Bitwise AND of the two specified integers*/
        } else if(strcmp(command.bitO, "bit_and") == 0 || strcmp(command.bitO, "BIT_AND") == 0 )
        {
            /*Scan number from user*/
            scanf("%d%d", &command.num1, &command.num2);

            /*Doing bit_and*/
            command.sum = command.num1 & command.num2;

            /*print the sum result*/
            printf("%d\n", command.sum);
         /*If user input is bit_xor. bitwise XOR of the two specified integers*/
        } else if(strcmp(command.bitO, "bit_xor") == 0 || strcmp(command.bitO, "BIT_XOR") == 0 )
        {
            /*Scan number from user*/
            scanf("%d%d", &command.num1, &command.num2);

            /*Doing bit_xor*/
            command.sum = command.num1 ^ command.num2;

            /*print the result*/
            printf("%d\n", command.sum);
        /*if user input is bit_shift_left. shift the bits of the integer s k bits to the left*/
        } else if(strcmp(command.bitO, "bit_shift_left") == 0 || strcmp(command.bitO, "BIT_SHIFT_LEFT") == 0) 
        {
            /*Scan number from user*/
            scanf("%d%d", &command.num1, &command.num2);

            /*Doing bit_shift_left*/
            command.sum = command.num1 << command.num2;

            /*print the sum result*/
            printf("%d\n", command.sum);

        /*if user input is bit_shift_right. shift the bits of the integer s k bits to the right4*/
        } else if(strcmp(command.bitO, "bit_shift_right") == 0|| strcmp(command.bitO, "BIT_SHIFT_RIGHT") == 0)
        {
            /*Scan number from user*/
            scanf("%d%d", &command.num1, &command.num2);

            /*Doing bit_shift_left*/
            command.sum = command.num1 >> command.num2;

            /*print the sum result*/
            printf("%d\n", command.sum);
      
        } else if (strcmp(command.bitO, "reverse")==0){
            
            /*Scan the next string of the reverse*/
            scanf("%s", command.string);

            /*call reverse function*/
            reverse(command.string);

            /*print the string result*/
            printf("%s\n", command.string);
        }
        else /*Invalid input*/
        {
            printf("Invalid command! Please try again.\n");
            while( getchar() != '\n' ); /*clear input buffer*/
        }

    }
    /**/
    return EXIT_SUCCESS;
}

/*Reverses a string using pointers*/
void reverse(char * string)
{
    
    int length;
    int count;

    char * begin;
    char * end;
    char temp;

    length = strlen(string);
    /*begin and end are whole string*/
    begin  = string;
    end    = string;

    /*set end to the last char in the string*/
    for (count = 0; count < length - 1; count ++)
    {
        end++; 
    }

    /* iterate through half the string swapping char on both sides */
    for (count = 0; count < length/2; count++)
    {

        temp   = *end; /*set temp to the last char*/
        *end   = *begin; /*set end address char to begin char*/
        *begin = temp; /*change begin char to temp char*/

        /*troubleshoot*/
        /*
        printf("Temp: %c %x\n", temp, temp);
        printf("end: %s %x\n", end, end);
        printf("begin: %s %x\n", begin, begin);
        printf("Length: %d\n", length);
        printf("Count: %d\n", count);
        */

        begin++; /*increment begin pointer address*/
        end--; /*decrement end pointer address*/

        /*troubleshoot*/
        /*
        printf("end af: %s %x\n", end, end);
        printf("begin af: %s %x\n\n", begin, begin);
        */
    
    }
}