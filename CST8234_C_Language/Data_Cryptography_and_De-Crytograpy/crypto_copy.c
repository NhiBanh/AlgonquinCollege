/**
 * File: crypto.c
 * Purpose: To print the encrypted integer
 * Author: Nhi Banh
 * Student Number: XXX XXX XXX
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define DIGITS 4
int main() 
{
  int loop = 1; /*loop*/
  char num; /* user input */
  int checkNum; /* check number */
  int encNum; /*the current number */
  int digits[DIGITS]; /* array to hold digits for swap */
  int i ; /* count of array index */
  int count; /*count the number of digit */
  int cryptNum; 

  /*loop for input */
  while(loop)
  {
    /*prompt for number */
    printf( "Enter a four digit integer number:\n" ); 
    
    if(scanf("%d", &num) == 1)
    {
      count = 0; /* make sure the count begin at 0 */
      checkNum = num;

      /*count digits */
     
      while(checkNum != 0) 
      {
      checkNum /= 10;
       ++count;
      }

      /*check if right amount of digits */
      if(count == 4)
      {
        checkNum = num;
        i = 0;

        /*replace each digit by adding 7 to each digit, then, dividing by 10 */
        /*getting remainder after dividing by 10 */
        /* 
          1256 
          1 + 7 % 10 = 8
          2 + 7 % 10 = 9
          5 + 7 % 10 = 2
          6 + 7 % 10 = 3
      
          1256 = 8923 ==>  2389
        */
        while(checkNum != 0)
        {
          encNum = checkNum % 10;
          digits[i] = (encNum + 7) % 10;
          
          checkNum /= 10; /* go to next digits */
          i++;
        }

        /*printf("Encrypted number of %d is %ld%ld%ld%ld \n", num, digits[0], digits[1], digits[2], digits[3]); */

        /*swap number  */
        
        cryptNum = digits[1];
        cryptNum = cryptNum * 10 + digits[0];
        cryptNum = cryptNum * 10 + digits[3];
        cryptNum = cryptNum * 10 + digits[2];
       

        /*print the encrypt number */
        printf("Encrypted number of %d is %d\n", num, cryptNum);
      
        /*get out loop */
        loop = 0; 
        break;

      }else
      {
        /*intvalid number of digits */
        printf("Invalid number of digits %d in %d\n", count, num);
      }

    }else
    {
      printf("Invalid!, input must be an integer.\n");
      fflush(stdin); /*flush standard input*/
      while( getchar() != '\n' ); /*clear input bufferasdd*/

    }
  }
  return EXIT_SUCCESS;
} 
