/*****************************************************************************
 FILE      :  banh0007_A1.c
 PROGRAM   :  Dice Game Implementation
 AUTHOR    :  Nhi Banh
 STUDENT_NUMBER: 040 932 192
*****************************************************************************/
/***********************************************
* Include C library headers.
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/***********************************************
 Include private library headers.
***********************************************/
#include "dicegame.h"

/***********************************************
* Set Global Variables
***********************************************/

/**********************************************
* Function Name: Main
* PURPOSE: Runs main logic of dice game
* INPUT: none
* RETURN:  0
***********************************************/
int main()
{
  int result = 0;/*Result from play game*/
  int flag = 0;/*Flag for main game loop*/
  int bet = 0;/*Bet amount*/
  int rem = 0;/*Remaining in wallet*/

  /*Set globals*/
  wallet = 50;/*Set starting wallet amount*/
  wins = 0;/*set default wins*/
  losses = 0;/*Set default losses*/

  /*To seed random, to make it unique each program execution*/
  srand(time(NULL));

  /*Main game loop*/
  while(flag == 0)
  {
    /*Check if user wants to play another game*/
    flag = ( playAgain() ) ? 1 : 0;
    //flag = playAgain // same as flag = ()

    if(flag ==1) break;

    /*Get bet amount*/
    bet = doBet();

    /*Check if player is not betting*/
    if(bet == 0){
      /*Play game*/
      result = playGame();

      /*Increment wins*/
      if(result == WON){
        wins++;
      }

      /*Increment losses*/
      if(result == LOSE){
        losses++;
      }

      /*Check if player quit*/
      if(result == QUIT){
        flag = QUIT;
        break;
      }

    }
    else /*Player is betting*/
    {
      rem = wallet - bet;/*set remainder in wallet*/
      printf("You bet: %d\n", bet);  /*Print bet amount*/

      /*Play game*/
      result = playGame();

      /*Increment wins, and calculate wallet*/
      if(result == WON){
        wins++;
        wallet = bet + ( bet * 3) + rem;
      }

      /*Increment losses, and calculate wallet*/
      if(result == LOSE){
        losses++;
        wallet = wallet - bet;
      }

      /*Check if player quit*/
      if(result == QUIT){
        flag = 1;
        break;
      }
    }

    /*Print wallet*/
    printf("Your remaining money is at $%d \n", wallet);


  }/*End main while loop*/

  /*Print final game stats*/
  printf("Thank you for your playing\n");
  printf("You won %d and lost %d games!\n", wins, losses);
  printf("Your remaining money is %d\n", wallet);

  return EXIT_SUCCESS; /*Exit*/
}
