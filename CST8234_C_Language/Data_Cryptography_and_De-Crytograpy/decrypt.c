/**
 * File: crypto.c
 * Purpose: To print the decrypted integer
 * Author: Nhi Banh
 * Student Number: XXX XXX XXX
**/

#include<stdio.h>
#include<stdlib.h>

#define DIGITS 4

int crypto(int inputNum);
int decrypto(int inputNum);
int countDigit(int inputNum);

int main()
{
    int loop = 1; /*loop*/
    int num; /* user input number*/
    int count; /* count the number of digits */
    int decryptNum; /* decrypt number */


    while(loop)
    {
        /*prompt for number*/
        printf( "Enter a four digit number:\n" ); 

        if ( scanf("%d", &num) == 1 ) {
            /*count the number*/
            count = countDigit(num);

            /* check if right amount of digits */
            if(count == DIGITS)
            {

                decryptNum = decrypto(num);
                printf("Decrypted number of %d is %d\n" , num, decryptNum);

                loop = 0; /* out of loop */
                break;
            } else 
            {
                /* invalid number of digits */
               printf("Invalid number of digits\n");
            }
        } else 
        {
            /* invalid number of digits */
            printf("Invalid! input must be an integer.\n");
            fflush(stdin); /*flush standard input*/
            while( getchar() != '\n' ); /*clear input bufferasdd*/
        }
    }
    return EXIT_SUCCESS;
}

/*
12566 input
8923 pre swap
2389 post swap
*/

int crypto( int inputNum )
{
    int x = 0; /* array index */
    int digArr[DIGITS]; /* store digits */
    int crypt = 0; /* returned crypt number */

    /* iterate through each digit (digits are backwards) */
    while(inputNum != 0 )
    {
        digArr[x] = (inputNum + 7) % 10;
        inputNum /= 10; /* go to next digit */
        x++;
    }

    /* swap to finish encryption */
    crypt = digArr[1];
    crypt = crypt * 10 + digArr[0];
    crypt = crypt * 10 + digArr[3];
    crypt = crypt * 10 + digArr[2];

    return crypt;
}

int countDigit(int inputNum)
{
    int count = 0;

    /* count digits */
    while(inputNum != 0)
    {
        inputNum /= 10;
        ++count;
    }
    return count;
}

int decrypto( int inputNum ) 
{
    int decrypt = 0; /* the returned decrypted number */
    int digArr[DIGITS]; /* store digits */
    int fixArr[DIGITS]; /* fixed array (digits un split) */
    int x = 0; /* used for array index */

    /* get each number and store in array */
    while( inputNum != 0)
    {
        digArr[x] = inputNum % 10; /* store number in array */
        inputNum /= 10; /* go to next digit */
        x++;
    }

    /* reserve split the numbers */
    fixArr[0] = digArr[1];
    fixArr[1] = digArr[0];
    fixArr[2] = digArr[3];
    fixArr[3] = digArr[2];

    /* decrypt back to original number */
    /* to use modulor on negative integer need to ( a % b + b) % b to get proper return */
    decrypt = ((fixArr[0] - 7) % 10 + 10) % 10;
    decrypt = decrypt * 10 + (((fixArr[1] - 7) % 10 + 10) % 10);
    decrypt = decrypt * 10 + (((fixArr[2] - 7) % 10 + 10) % 10);
    decrypt = decrypt * 10 + (((fixArr[3] - 7) % 10 + 10) % 10);

    return decrypt;
}
