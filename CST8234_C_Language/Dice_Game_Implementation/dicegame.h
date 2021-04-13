/*****************************************************************************
 FILE      :  dicegame.h
 PROGRAM   :  Dice Game Implementation
 AUTHOR    :  Nhi Banh
 STUDENT NUMBER: 040 932 192
*****************************************************************************/

/***********************************************
* Declare constants
***********************************************/
#define WON 0
#define LOSE 1
#define QUIT 2

/***********************************************
* Global Variables
***********************************************/
int wallet;
int wins;
int losses;

/***********************************************
* Function prototypes.
***********************************************/
int playGame();/*Dice game logic*/
int rollDice();/*Rolls dice*/
int playAgain();/*Prompts user if they want to play again*/
int doBet();/*Handle betting logic*/
