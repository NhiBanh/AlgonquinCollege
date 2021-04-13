/*****************************************************************************
 FILE      :  dicegame.c
 PROGRAM   :  Dice Game Implementation
 AUTHOR    :  Nhi Banh
 STUDENT NUMBER: 040 932 192
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

/******************************************************
* Function Name: playGame
* PURPOSE: main gaime logic, rolls dice, and checks winner
* INPUT: none
* RETURN: WON (0), LOSE (1)
******************************************************/
int playGame()
{
  int flag = -1;/*Return value of function*/
  int count = 0;/*Current round*/
  int p[2] = {0,0};/*Array for player dice*/
  int c[2] = {0,0};/*Array for computer dice*/
  int psum;/*Player dice sum*/
  int csum;/*Computer dice sum*/
  int pm = 0;/*Point match int*/
  int pChar;/*Player input*/

  /*clear input buffer to remove /n from input*/
  while( getchar() != '\n' );

  printf("\n\t\t\tROLL THE DICE [ENTER} QUIT TO [q]\n");

  /*Loop for player input (enter or q)*/
  while(1){

    pChar = getchar();/*get character */

    /*check that enter was pressed*/
    if(pChar == '\n'){
      break;/*Exit loop*/
    }
    else if(pChar == 'q' || pChar == 'Q') /*Quit game*/
    {
      flag = QUIT;/*Exit game*/
      break;
    }
    else /*Invalid input*/
    {
      printf("Invalid! press ENTER key to Continue or Q to quit\n");
      while( getchar() != '\n' ); /*clear input buffer*/
    }
  }

  /*If user did not quit*/
  if (flag == -1)
  {
    /*Print table head*/
    printf("----------------------------------------------------------------\n");
    printf(" ROLL NUM    DICE#1    DICE#2    TOTAL ROLL    POINT MATCH\n");
    printf("----------------------------------------------------------------\n");

    /*Game logic*/
    while(1)
    {
      count++;/*Increment round*/
      p[0] = rollDice();/*Roll player dice 1*/
      p[1] = rollDice();/*Roll player dice 2*/
      c[0] = rollDice();/*Roll computer dice 1*/
      c[1] = rollDice();/*Roll computer dice 2*/

      psum = p[0] + p[1];/*Calculate player dice sum*/
      csum = c[0] + c[1];/*Calculate computer dice sum*/

      /*Print round results*/
      printf("%9d%10d%10d%14d%15d\n\n", count, p[0], p[1], psum, pm);

      /*check player Logic first*/
      /*check player has won*/
      if(psum == 7 || psum == 11 || psum == pm)
      {
        /*Check if first roll*/
        if(count == 1){
          printf("Congratulations you roll %d and win on your first try!!!\n", psum);
        }
        else /*All other rolls*/
        {
          printf("Congratulations you roll %d and win!!!\n", psum);
        }

        flag = WON;
        break;
      }
      else if(psum == 2 || psum == 3 || psum == 12)/*Check player has lost*/
      {
        /*Check if first roll*/
        if(count == 1){
          printf("Sorry, you roll %d and lose on your first try!!!\n", psum);
        }
        else/*All other rolls*/
        {
          printf("Sorry, you roll %d and lose!!!\n", psum);
        }

        flag = LOSE;
        break;
      }
      else if(csum == 7 || csum == 11 || csum == pm)/*Check if computer won*/
      {
        /*Check if first roll*/
        if(count == 1){
          printf("Sorry, computer roll %d and you lose at first try!!!\n", csum);
        }
        else /*All other rolls*/
        {
          printf("Computer roll %d and you lose!!!\n", csum);
        }

        flag = LOSE;
        break;
      }
      else if(csum == 2 || csum == 3 || csum == 12)/*Check if computer lost*/
      {
        /*Check if first roll*/
        if(count == 1){
          printf("Congratulations computer roll %d and win on your first try!!!\n", csum);
        }
        else /*All other rolls*/
        {
          printf("Computer roll %d and you win!!!\n", csum);
        }

        flag = WON;
        break;
      }
      else /*all other conditions*/
      {
        /*Check if pm has not been set*/
        if(pm == 0)
        {
          pm = psum;/*Set point match*/
        }
      }
    }/*end while*/
  }
  return flag;
}

/******************************************************
* Function Name: rollDice
* PURPOSE: Uses rand() to roll a dice
* INPUT: none
* RETURN: random number from 1 to 6
******************************************************/
int rollDice()
{
  return rand() % 6 + 1;
}

/******************************************************
* Function Name: playAgain
* PURPOSE: Asks user if they want to continue playing
* INPUT: none
* RETURN: 0 if yes, 1 if no
******************************************************/
int playAgain(){
  char anotherGame;
  int ret = 0;/*return value*/

  /*Prompt to play another game*/
  while(1){
    /*Check if not first game*/
    if( wins > 0 || losses > 0 )
    {
      /*Prompt to play another game*/
      printf("Another game[y/n]\n");

      /*Capture result*/
      anotherGame = getchar();

      /*If yes*/
      if(anotherGame == 'Y' || anotherGame == 'y')
      {
        ret = 0;
        while( getchar() != '\n' );
        break;
      }
      else if(anotherGame == 'N' || anotherGame == 'n')/*if no*/
      {
        ret = 1;
        break;
      }
      else /*Invalid input*/
      {
        printf("Invalid! Input...\n");
        while( getchar() != '\n' ); /*clear input buffer*/
      }
    }
    else /*First game*/
    {
      break;/*Exit loop on first game */
    }
  }/*end while loop*/

  return ret;
}

/******************************************************
* Function Name: doBet
* PURPOSE: Asks user if they want to bet and handles setting bet amount
* INPUT: none
* RETURN: 0 on not betting, bet amount if betting
******************************************************/
int doBet(){
  char bInput;/*input if betting*/
  int betIncrements = 0;/*input for bet*/
  int ret = 0;/*return value*/

  /*Betting logic loop*/
  while(1)
  {
    /*Prompt for bet*/
    printf("Do you want to bet[y/n]\n");

    /*Get answer*/
    bInput = getchar();

    /*if yes, get bet amount*/
    if(bInput == 'Y' || bInput == 'y')
    {
      /*Check if wallet is empty*/
      if(wallet <= 0){
        printf("Sorry, You are out of money. Cannot bet. Playing game without a bet.\n");
        break;
      }
      else /*Allowed to bet*/
      {
        /*Loop for bet amount*/
        while(1)
        {
          /*Prompt for bet amount*/
          printf("You have $%d, total number of $5 if %d \n", wallet, wallet/5);
          printf("How many $5 do you want to bet [1-%d]\n", wallet/5);

          /*Validate amount is integer*/
          if(scanf("%d", &betIncrements) != 1 )
          {
            printf("Invalid! Input must be an Integer. \n");
            while(getchar() != '\n');/*flush the input*/
          }
          else
          {
            /*Validate amount is good number*/
            if(betIncrements > 0 && betIncrements <= wallet/5 )
            {
              ret = betIncrements * 5;/*Set return to bet amount*/
              break;
            }
            else /*Invalid amount*/
            {
              printf("Invalid! Please enter a valid amount of $5 increments\n");
            }
          }
        }/*end while loop*/
      }
      break;/*end loop*/
    }
    else if (bInput == 'N' || bInput == 'n')
    {
      ret = 0;
      break;
    }
    else /*Invalid input*/
    {
      printf("Invalid! Input must be a single character. \n");
      while(getchar() != '\n');
    }
  }/*end while loop*/
  return ret;
}
