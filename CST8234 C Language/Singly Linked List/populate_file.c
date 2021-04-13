/*****************************************************************************
 FILE      :  populate_file.c
 PROGRAM   :  Populate File
 AUTHOR    :  Nhi Banh
 STUDENT_NUMBER: XXX XXX XXX
*****************************************************************************/
/***********************************************
* Include C library headers.
***********************************************/
#include <stdio.h>

struct clientInfo
{
  int AccNo;
  char lastName[20];
  char firstName[20];
  double accBalance;
};

int main(void)
{
  int i; /*counter used to count from 1-100*/
  struct clientInfo randomClient = {0, "", "", 0.0}; /*create clientInfo with default information*/

  FILE *fptr;
  if( ( fptr = fopen("credit.dat", "wb" ) ) == NULL )
  {
    printf("File could not be opened");
  }
  else
  {
    for( i=1; i<=100; i++ ) /*output 100 random blank records to file*/
    {
      fwrite(&randomClient, sizeof(struct clientInfo), 1, fptr);
    }
    fclose(fptr);
  }
 return 0;
}
