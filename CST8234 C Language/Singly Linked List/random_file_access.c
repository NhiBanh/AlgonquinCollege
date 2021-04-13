/*****************************************************************************
 FILE      :  random_file_access.c
 PROGRAM   :  Single Linked List
 AUTHOR    :  Nhi Banh
 STUDENT_NUMBER: 040 932 192
*****************************************************************************/
/***********************************************
* Include C library headers.
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***********************
clientInfo struct
************************/
struct clientInfo
{
  int AccNo;
  char lastName[20];
  char firstName[20];
  double accBalance;
};

/***********************************************
* Function prototypes.
***********************************************/
void textFile();
void updateRecord();
void newRecord();
void deleteRecord();
/**********************************************
* Function Name: Main
* PURPOSE: Manage clientInfo records in a file
* INPUT: none
* RETURN:  0
***********************************************/
int main(void)
{
  int loop = 1;/*Main loop*/
  int option; /*Menu option*/
  /*Loop until quit*/
  while (loop)
  {
    printf("\nSelect an Option:\n");
    printf("1) Store accounts in text file.\n");
    printf("2) Update an existing record.\n");
    printf("3) Create a new record.\n");
    printf("4) Delete an existing record.\n");
    printf("5) Exit.\n");

    if(scanf("%d",&option) != 1)
    {
      printf("Invalid! input must be an integer.\n");
      while( getchar() != '\n' ); /*clear input buffer*/
    }
    else
    {
      if(option == 1)
      {
        textFile();
      }
      else if(option == 2)
      {
        updateRecord();
      }
      else if(option == 3)
      {
        newRecord();
      }
      else if(option == 4)
      {
        deleteRecord();
      }
      else if(option == 5)
      {
        printf("\nQuitting...\n\n");
        loop = 0;
        break;
      }
      else
      {
        printf("Invalid Option!!!\n");
      }

    }
  }

  return EXIT_SUCCESS;
}
/**********************************************
* Function Name:textFile
* PURPOSE: Store formated list of all accounts in
* accounts.txt
* INPUT: none
* RETURN: none
***********************************************/
void textFile()
{
    FILE *dataFile;/*File pointer, for data file*/
  FILE *accountsFile;/*File pointer for accounts file*/
  struct clientInfo client;

  /*Open the credit datafile in read mode binary*/
  dataFile = fopen("credit.dat", "rb");

  /*Check if file opened successfully*/
  if(dataFile == NULL)
  {
    printf("Error opening credit.dat\n");
    exit(1);
  }

  /*Open accounts.txt file in write mode (override previous data) */
  accountsFile = fopen("accounts.txt", "w");

  /*Check if file opened successfully*/
  if(accountsFile == NULL)
  {
    printf("Error opening accounts.txt\n");
    exit(1);
  }

  /*Add accounts.txt header*/
  fprintf(accountsFile, "%s  %-20s  %-20s  %-15s\n", "accNo-", "lastName", "firstName", "accBalance");
  /*Iterate and read each record in data file*/
  while( fread( &client, sizeof( struct clientInfo ), 1, dataFile ) ){
    /*Check if record is present in file*/
    if(client.AccNo != 0){
      /*Write new record into accountsFile*/
      fprintf(accountsFile, "%-3d     %-20s  %-20s  %-15.2f\n", client.AccNo, client.lastName, client.firstName, client.accBalance);
    }

  }

  fclose(accountsFile);  /*Close the accounts file*/
  fclose(dataFile);  /*Close the data file*/
}

/**********************************************
* Function Name:updateRecord
* PURPOSE: Update existing record
* INPUT: none
* RETURN: none
***********************************************/
void updateRecord(){
  FILE *dataFile;
  int accNum = 0;
  char balInput[30];
  double newBalance;
  struct clientInfo client;

  /*Open the credit datafile in update mode*/
  dataFile = fopen("credit.dat", "rb+");

  /*Check if file opened successfully*/
  if(dataFile == NULL)
  {
    printf("Error opening credit.dat\n");
    exit(1);
  }

  /*Loop until valid number*/
  while(1)
  {
    /*Prompt for account Number*/
    printf("Enter account to update (1-100):");

    if(scanf("%d",&accNum) != 1)
    {
      printf("\nInvalid! input must be an integer.\n");
      while( getchar() != '\n' ); /*clear input buffer*/
    }
    else
    {
      /*Check that account is within range*/
      if(accNum >=1 && accNum <=100){

        /*Check if account exists at provided account number position*/
        fseek(dataFile, accNum*sizeof(struct clientInfo), SEEK_SET);

        /* read client infor at account number position*/
        fread(&client,sizeof(struct clientInfo),1,dataFile);

        /*Check if account can be added a position*/
        if(client.AccNo == 0){
          printf("The record is empty\n");
          break;
        }
        else
        {
          /*Print account info*/
          printf("%d %10s %10s %10.2f\n",client.AccNo,client.firstName,client.lastName,client.accBalance);

          while(1){
            printf("Enter charge (+) or payment (-):");

            /*Read number as string*/
            scanf("%s", balInput);

            /*Check that + or minus is the first char*/
            if( balInput[0] == '+' || balInput[0] == '-')
            {
              newBalance = atof(balInput);
              /*Modify account balance*/
              client.accBalance += newBalance;

              /*Seek to position of account number*/
              fseek(dataFile, accNum*sizeof(struct clientInfo), SEEK_SET);

              /*Write the updated data to the file*/
              fwrite(&client, sizeof(struct clientInfo), 1, dataFile);

              printf("%d %10s %10s %10.2f\n",client.AccNo,client.firstName,client.lastName,client.accBalance);

              break;
            }
            else
            {
              printf("Enter + or - before number\n");
            }
          }

          break;
        }
      }
      else
      {
        printf("\nInvalid account number, must be between (1-100)\n");
      }
    }
  }
  fclose(dataFile);/*Close the data file*/
}
/**********************************************
* Function Name:newRecord
* PURPOSE: Create a new record
* INPUT: none
* RETURN: none
***********************************************/
void newRecord(){
  FILE *dataFile;
  int accNum = 0;
  int count;
  int i;
  char input[50];
  char * argArr[3];
  char * token;
  struct clientInfo client;

  /*Open the credit datafile in update mode*/
  dataFile = fopen("credit.dat", "rb+");

  /*Check if file opened successfully*/
  if(dataFile == NULL)
  {
    printf("Error opening credit.dat\n");
    exit(1);
  }

  /*Loop until valid number*/
  while(1)
  {
    /*Prompt for account Number*/
    printf("Enter new account number (1-100):");

    if(scanf("%d",&accNum) != 1)
    {
      printf("\nInvalid! input must be an integer.\n");
      while( getchar() != '\n' ); /*clear input buffer*/
    }
    else
    {
      /*Check that account is within range*/
      if(accNum >=1 && accNum <=100){

        /*Check if account exists at provided account number position*/
        fseek(dataFile, accNum*sizeof(struct clientInfo), SEEK_SET);

        /* read client infor at account number position*/
        fread(&client,sizeof(struct clientInfo),1,dataFile);

        /*Check if account can be added a position*/
        if(client.AccNo == 0){

          while( getchar() != '\n' ); /*clear input buffer*/

          /*Prompt for info*/
          while(1){

            printf("Enter lastName FirstName balance\n");

            /*Grab string from user*/
            fgets(input, sizeof(input), stdin);

            /*Split string by token, spaces*/
            token = strtok(input, " ");

            count  = 0;
            i = 0;
            /*Loop to explode string into inputs*/
            while (token != NULL)
            {
               if(i<3)
               {
                  argArr[i] = token;
                  i++;
               }
               count++;
               token = strtok(NULL, " ");
            }

            if(count > 3){
              printf("Invalid number of arguments!\n");
            }
            else  /*Valid number of arguments*/
            {

              /*Data to add*/
              client.AccNo = accNum;
              strcpy( client.lastName, argArr[0] );
              strcpy( client.firstName, argArr[1]);
              client.accBalance = atof(argArr[2]);

              /*Seek to position of account number*/
              fseek(dataFile, accNum*sizeof(struct clientInfo), SEEK_SET);

              /*Write the new data to the file*/
              fwrite(&client, sizeof(struct clientInfo), 1, dataFile);

              break;
            }
          }
          break;
        }
        else
        {
          /*Print error and exit back to main*/
          printf("Account already exists!\n");
          break;
        }

      }
      else
      {
        printf("\nInvalid account number, must be between (1-100)\n");
      }
    }
  }

  fclose(dataFile);  /*Close the data file*/
}

/**********************************************
* Function Name:deleteRecord
* PURPOSE: Update existing record
* INPUT: none
* RETURN: none
***********************************************/
void deleteRecord()
{
    FILE *dataFile;
    int accNum = 0;
    struct clientInfo client;

  /*Open the credit datafile in update mode*/
  dataFile = fopen("credit.dat", "rb+");

  /*Check if file opened successfully*/
  if(dataFile == NULL)
  {
        printf("Error opening credit.dat\n");
        exit(1);
  }

  /*Loop until valid number*/
  while(1)
  {
    /*Prompt for account Number*/
    printf("Enter account to delete (1-100):");

    if(scanf("%d",&accNum) != 1)
    {
      printf("\nInvalid! input must be an integer.\n");
      while( getchar() != '\n' ); /*clear input buffer*/
    }
    else
    {
      /*Check that account is within range*/
      if(accNum >=1 && accNum <=100)
      {
        /*Check if account exists at provided account number position*/
        fseek(dataFile, accNum*sizeof(struct clientInfo), SEEK_SET);

        /* read client infor at account number position*/
        fread(&client,sizeof(struct clientInfo),1,dataFile);

        /*Check if account can be added a position*/
        if(client.AccNo == 0)
        {
          printf("The record is empty\n");
          break;
        }
        else /*Account exists*/
        {

          /*Set data to defaults*/
          client.AccNo = 0;
          strcpy(client.firstName, "");
          strcpy(client.lastName, "");
          client.accBalance = 0.0;

          /*Check if account exists at provided account number position*/
          fseek(dataFile, accNum*sizeof(struct clientInfo), SEEK_SET);

          /*Write the default data to the file*/
          fwrite(&client, sizeof(struct clientInfo), 1, dataFile);

          break;
        }
      }
      else
      {
        printf("\nInvalid account number, must be between (1-100)\n");
      }
    }
  }
  fclose(dataFile);  /*Close the data file*/
}