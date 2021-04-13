/*****************************************************************************
 FILE      :  Employee.c
 PROGRAM   :  Assignment 2, Employee database implementation using linked list
 AUTHOR    :  Nhi Banh
 STUDENT_NUMBER: 040 932 192
*****************************************************************************/
/***********************************************
* Include C library headers.
***********************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***********************************************
 Include private library headers.
***********************************************/
#include "Employee.h"

/**********************************************
* Function Name:Main
* PURPOSE: Runs main logic for employee database
* INPUT: none
* RETURN: EXIT_SUCCESS
***********************************************/
int main ()
{
    Employee * empLL = NULL;/*Head of Employee linked list*/
    int size = 0;/*Keep track of employees in Linked List*/
    char inputMain[10] ; /*Input character*/

    /*Print Menu 1 time*/
    printf("Choose one of the following options\n");
    printf("[1] Insert data of another employee\n");
    printf("[2] Modify existing employee information\n");
    printf("[3] Delete an employee's data\n");
    printf("[4] Shows all database entries\n");
    printf("[q] To quit\n");

    while (1)
    {
        printf("You pressed: ");
        /*Get input*/
        fgets(inputMain, sizeof(inputMain), stdin);

        /* Remove trailing newline*/
        if ((strlen(inputMain) > 0) && (inputMain[strlen (inputMain) - 1] == '\n')){
            inputMain[strlen (inputMain) - 1] = '\0';
        }

        if ( strcmp(inputMain, "q") == 0 || strcmp(inputMain, "Q") == 0 )
        {
            printf("Have a nice time!");
            break;
        }
        else if (strcmp(inputMain, "1") == 0 )
        {
            employee_add(&empLL, &size);
             printf("What would you like to do next?\n");
        }
        else if (strcmp(inputMain, "2") == 0)
        {
            employee_update(&empLL, &size);
          printf("What would you like to do next?\n");
        }
        else if (strcmp(inputMain, "3") == 0)
        {
            employee_remove(&empLL, &size);
            printf("What would you like to do next?\n");
        }
        else if (strcmp(inputMain, "4") == 0)
        {
            print_employees(empLL, &size);
            printf("What would you like to do next?\n");
        }
        else
        {
            printf("Not accepted. Enter a valid option number [1-4 or q]\n");
        }
    }

    /*Free allocated memory*/
    employee_destroy(&empLL);

    return EXIT_SUCCESS;
}

/**********************************************
* Function Name:print_employees
* PURPOSE: Prints employees in linked list
* INPUT: pointer to head of linked list, size of list
* RETURN: none
***********************************************/
void print_employees(Employee  * empll, int * size)
{
    printf("Total number of employees: %d\n", *size);

    if(empll == NULL)
    {
        printf("Empty List\n");
    }
    while (empll != NULL) 
    {
        printf("%s %c %d %s\n", empll->name, empll->gender, empll->age, empll->job);
        empll = empll->next;
    }
}

/**********************************************
* Function Name:employee_search_insert
* PURPOSE: Finds first instance of name in employee db
* INPUT: pointer to head of linked list, name to search,
* RETURN: none
***********************************************/
void employee_search_insert(Employee**head, char * srcname, int field)
{
    int fIndex = 0;/*Start index at 0*/
    int found = -1;
    int strSize;
    char tempName[MAX_NAME_LENGTH*2];
    char name[MAX_NAME_LENGTH];
    char job[MAX_JOB_LENGTH];
    char tempjob[MAX_JOB_LENGTH*2];
    char gender;
    int age;
    Employee * curEmp = *head;  /*Set current to point to head*/

    /*Iterate through LL*/
    while (curEmp != NULL) 
    {
        /*Check if name matches current employee name*/
        if(strcmp(srcname, curEmp->name) == 0)
        {
            found = fIndex;
            break;/*Break loop, no need to continue*/
        }

        curEmp = curEmp->next;
        ++fIndex;
    }

    /*Get data to insert*/
    if(found >=0)
    {
        /*Get Name*/
        if(field == 1)
        {
            /*Loop for name to update*/
            while (1)
            {
                /*Prompt for name(string)*/
                printf("Enter the new name: ");

                fgets(tempName, sizeof(tempName), stdin);

                /* Remove trailing newline*/
                if ((strlen(tempName) > 0) && (tempName[strlen (tempName) - 1] == '\n'))
                {
                    tempName[strlen (tempName) - 1] = '\0';
                }

                strSize = strlen(tempName);

                /*Truncate to max size*/
                if(strSize > MAX_NAME_LENGTH)
                {
                    strncpy(name, tempName, MAX_NAME_LENGTH);
                    name[MAX_NAME_LENGTH] = '\0'; /* '\0' is end the string */
                }
                else
                {
                    strcpy(name, tempName);
                }
                break;
            }

            /*Update name*/
            strcpy(curEmp->name, name);
        }

        /*Gender*/
        if(field == 2)
        {

            while(1)
            {
                /*Prompt for gender (char)*/
                printf("Enter the new gender: ");
                scanf(" %c", &gender );

                if(gender == 'F' || gender == 'f' || gender == 'M' || gender == 'm' )
                {
                    break;

                } else
                {
                    printf("Invalid input ( f or m )");
                    while( getchar() != '\n' ); /*clear input buffer*/
                }
            }

            /*Update gender*/
            curEmp->gender = gender;
        }

        /*Age*/
        if(field == 3)
        {
            while(1)
            {
                /*Prompt for age (int)*/
                printf("Enter the new age: ");

                if(scanf("%d",&age) != 1)
                {
                    printf("Invalid! input must be an integer.");
                }
                else
                {
                    while( getchar() != '\n' ); /*clear input buffer*/
                    break;
                }
            }

            /*Update age*/
            curEmp->age = age;
        }

        /*Job Profile*/
        if(field  == 4)
        {
            while (1)
            {
                /*Prompt for job profile(string)*/
                printf("Job Profile: ");

                fgets(tempjob, sizeof(tempjob), stdin);

                strSize = strlen(tempjob);

                /* Remove trailing newline*/
                if ((strlen(tempjob) > 0) && (tempjob[strlen (tempjob) - 1] == '\n'))
                {
                    tempjob[strlen (tempjob) - 1] = '\0';
                }

                /*Truncate to max size*/
                if(strSize > MAX_JOB_LENGTH)
                {
                    strncpy(job, tempjob, MAX_JOB_LENGTH);
                    job[MAX_JOB_LENGTH] = '\0'; /* '\0' is end the string */
                } 
                else
                {
                    strcpy(job, tempjob);
                }
                break;
            }

            /*Update job*/
            strcpy(curEmp->job, job);
        }
        printf("Modified Employee Information: %s %c %d %s\n",curEmp->name, curEmp->gender, curEmp->age, curEmp->job );
    }
    else
    {
        printf("Employee with the name \"%s\" does not exist\n", srcname);
    }
}
/**********************************************
* Function Name:employee_add
* PURPOSE: Adds an employee to the linked list database
* INPUT: pointer to head of linked list, size of list
* RETURN: none
***********************************************/
void employee_add(Employee **head, int* size )
{
    /*Initialize variables*/
    char tempName[MAX_NAME_LENGTH*2];
    char name[MAX_NAME_LENGTH];
    char job[MAX_JOB_LENGTH];
    char tempjob[MAX_JOB_LENGTH*2];
    char gender;
    int age;
    int strSize;
    Employee * curEmp;/*Current employee in list*/
    Employee * newEmp;/*New employee pointer*/

    if(*size >= MAX_EMPLOYEES)
    {
        printf("Database full, Cannot add any new employees\n");
    }
    else
    {

        /*Get new Employee Name*/
        while (1)
        {
            /*Prompt for name(string)*/
            printf("Enter name: ");

            fgets(tempName, sizeof(tempName), stdin);

           /* Remove trailing newline*/
           if ((strlen(tempName) > 0) && (tempName[strlen (tempName) - 1] == '\n'))
           {
                tempName[strlen (tempName) - 1] = '\0';
           }

           strSize = strlen(tempName);

           /*Truncate to max size*/
           if(strSize > MAX_NAME_LENGTH)
           {
                strncpy(name, tempName, MAX_NAME_LENGTH);
                name[MAX_NAME_LENGTH] = '\0'; /* '\0' is end the string */
           }    
           else
           {
                strcpy(name, tempName);
           }
            break;
        }

        /*Get new employee gender*/
        while (1)
        {
            /*Prompt for gender (char)*/
            printf("Enter Gender: ");
            scanf(" %c", &gender );

            if(gender == 'F' || gender == 'f')
            {
                gender = 'F';
                break;
            }
            else if(gender == 'M' || gender == 'm')
            {
                gender = 'M';
                break;
            }
            else
            {
                printf("Invalid input ( f or m )");
                while( getchar() != '\n' ); /*clear input buffer*/
            }
        }

        /*Get new employee age*/
        while (1)
        {
            /*Prompt for age (int)*/
            printf("Enter Age: ");

            if(scanf("%d",&age) != 1)
            {
                printf("Invalid! input must be an integer.");
            }
            else
            {
                while( getchar() != '\n' ); /*clear input buffer*/
                break;
            }

        }

        /*Get new employee job profile*/
        while (1)
        {
            /*Prompt for job profile(string)*/
            printf("Job Profile: ");

            fgets(tempjob, sizeof(tempjob), stdin);

            strSize = strlen(tempjob);

            /* Remove trailing newline*/
            if ((strlen(tempjob) > 0) && (tempjob[strlen (tempjob) - 1] == '\n'))
            {
                tempjob[strlen (tempjob) - 1] = '\0';
            }

            /*Truncate to max size*/
            if(strSize > MAX_JOB_LENGTH)
            {
                strncpy(job, tempjob, MAX_JOB_LENGTH);
                job[MAX_JOB_LENGTH] = '\0'; /* '\0' is end the string */
            } 
            else
            {
                strcpy(job, tempjob);
            }
            break;
        }

        /*Allocate memory for new employee*/
        newEmp = malloc(sizeof(Employee));
        /*Save Employee info onto heap*/
        strcpy( newEmp->name, name);
        strcpy( newEmp->job, job);
        newEmp->gender = gender;
        newEmp->age = age;

        curEmp = *head;/*Set the current employee to the head of LL*/

        /*Find Insertion point*/
        /*Check if we are adding to head of list*/
        if(curEmp == NULL || strcmp(newEmp->name, curEmp->name) < 0 ) /*First Item in list*/
        {
            /*Point newEmp tp end of list (so NULL)*/
            newEmp->next = *head;
            *head = newEmp;/*Point head to newEmployee*/
        }
        else
        {
            /*Iterate through linked list until proper positon is found for insertion*/
            while (curEmp->next != NULL && strcmp( newEmp->name, curEmp->next->name ) >= 0)
            {
                curEmp = curEmp->next;/*Point to next node in list*/
            }

            newEmp->next = curEmp->next;
            curEmp->next = newEmp;
        }

        /*Print succes message*/
        printf("Newly Added Employee Information: %s %c %d %s\n", newEmp->name, newEmp->gender, newEmp->age, newEmp->job);

        /*Update size*/
        ++ *size;
    }
}
/**********************************************
* Function Name:employee_update
* PURPOSE: Update employee data
* INPUT: pointer to head of linked list
* RETURN: none
***********************************************/
void employee_update(Employee **head, int * size)
{
    /*Variables*/
    char feature[30];
    char tempName[MAX_NAME_LENGTH*2];
    int flag = 0;

    if(*size == 0)
    {
        printf("No employees in database to update. Please add one.\n");
    }
    else
    {
        /*Get feature to update*/
        while(1)
        {
            printf("Enter the employee feature you wish like to modify\n");
            printf("You entered: ");

            fgets(feature, sizeof(feature), stdin);

            /* Remove trailing newline*/
            if ((strlen(feature) > 0) && (feature[strlen (feature) - 1] == '\n'))
            {
                feature[strlen (feature) - 1] = '\0';
            }

            if( strcmp(feature, "Name") == 0 || strcmp(feature, "name") == 0 )
            {
                flag = 1;
                break;
            }
            else if( strcmp(feature, "Gender") == 0 || strcmp(feature, "gender") == 0 )
            {
                flag = 2;
                break;
            }
            else if( strcmp(feature, "Age") == 0 || strcmp(feature, "age") == 0 )
            {
                flag = 3;
                break;
            }
            else if( strcmp(feature, "Job profile") == 0 || strcmp(feature, "job profile") == 0 )
            {
                flag = 3;
                break;
            }
            else
            {
                printf("Invalid feature (Name, gender, age, job profile): ");
            }
        }

        /*Get name of employee to change*/
        printf("Enter the name of the employee you wish to change\n");
        fgets(tempName, sizeof(tempName), stdin);

        /* Remove trailing newline*/
        if ((strlen(tempName) > 0) && (tempName[strlen (tempName) - 1] == '\n'))
        {
            tempName[strlen (tempName) - 1] = '\0';
        }

        /*Find Employee, prompt and insert data*/
        employee_search_insert(head, tempName, flag);
    }
}
/**********************************************
* Function Name:employee_remove
* PURPOSE: Removes aemployee data or entire employee from list
* INPUT: pointer to head of linked list, size of list
* RETURN: none
***********************************************/
void employee_remove(Employee**head, int * size)
{
    /*Variables*/
    char srcValue[MAX_NAME_LENGTH];
    char tmpName[MAX_NAME_LENGTH];
    int found;
    int match = 0;
    int fIndex = 0;
    char gndMatch = 0;
    char confirm;
    Employee * curEmp = *head; /*Set currEmp to point to head*/
    Employee * prevEmp = NULL;/*Pointer to previous employee in list*/

    if(*size == 0)
    {
        printf("No employees in database to delete. Please add one.\n");
    }
    else
    {
        printf("Enter the employee feature (name, gender, age, job profile) you wish to delete:\n");
        fgets(srcValue, sizeof(srcValue), stdin);

        /* Remove trailing newline*/
        if ((strlen(srcValue) > 0) && (srcValue[strlen (srcValue) - 1] == '\n'))
        {
            srcValue[strlen (srcValue) - 1] = '\0';
        }

        /*Check if F is string given*/
        if(strcmp(srcValue, "f") == 0 || strcmp(srcValue, "F") == 0 )
        {
            gndMatch = 'F';
        }

        /*Check if M is string given*/
        if(strcmp(srcValue, "m") == 0 || strcmp(srcValue, "M") == 0 )
        {
            gndMatch = 'M';
        }

        /*Loop through all possible matches*/
        while(1)
        {
            found = -1;

            /*Iterate through LL, until first match*/
            while (curEmp != NULL) 
            {
                /*Check if name matches current employee name*/
                if(strcmp(srcValue, curEmp->name) == 0)
                {
                    found = fIndex;
                    break;/*Break loop, no need to continue*/
                }

                /*Check if gender matches value*/
                if(gndMatch != 0)
                {
                    if(gndMatch == curEmp->gender)
                    {
                        found = fIndex;
                        break;/*Break loop, no need to continue*/
                    }
                }

                /*Check if age matches value*/
                if(atoi(srcValue) == curEmp->age)
                {
                    found = fIndex;
                    break;/*Break loop, no need to continue*/
                }

                /*Check if Job matches*/
                if(strcmp(srcValue, curEmp->job) == 0)
                {
                    found = fIndex;
                    break;/*Break loop, no need to continue*/
                }
                prevEmp = curEmp;
                curEmp = curEmp->next;
                ++fIndex;
            }

            /*Check that */
            if(found >= 0)
            {
                /*Display found employee and prompt if correct*/
                printf("Is this the employee you wish to discard from the database? Please confirm [y/n]\n");
                printf("%s %c %d %s\n", curEmp->name, curEmp->gender, curEmp->age, curEmp->job);
                printf("You pressed: ");

                /*Loop for input*/
                while(1)
                {
                    scanf(" %c",&confirm);
                    getchar(); /* To consume the newline */

                    if ( confirm == 'y' || confirm == 'Y' )
                    {
                        match = 1;/*Exit loop*/
                        break;
                    }
                    else if( confirm == 'n' || confirm == 'N' )
                    {
                        curEmp = curEmp->next;/*Go to next employee*/
                        break;/*Continue search*/
                    }
                    else
                    {
                        printf("Invalid Input Enter [y or n]\n");
                        while( getchar() != '\n' ); /*clear input buffer*/
                    }
                }
            }

            /*If match, or end of list break outer loop*/
            if(match == 1 || curEmp == NULL)
            {
                break;
            }
        }/*end while*/

        if(match == 1)
        {
            /*remove current employee from list*/
            strcpy(tmpName, curEmp->name);

            /*check if at head*/
            if(prevEmp == NULL)
            {
                /*Set head to point to next employee*/
                *head = curEmp->next;
                free(curEmp);/*Free the current Employee from list*/
            }
            else /*All other Instances, middle to tail*/
            {
                /*Set previous next to point tp curEmp next*/
                
                free(curEmp);/*Free currEmp*/
            }

            /*Print success delete*/
            printf("Employee Named %s deleted successfully\n", tmpName);

            /*Update size*/
            -- *size;
        }
        else
        {
            /*Print cannot find message*/
            printf("Can not find Employee with that data.\n");
        }
    }
}

/**********************************************
* Function Name:employee_destroy
* PURPOSE: Frees all employee data
* INPUT: pointer to head of linked list
* RETURN: none
***********************************************/
void employee_destroy(Employee **head)
{
    Employee *curEmp = *head;
    Employee *freeEmp;

    while (curEmp->next != NULL)
    {
        freeEmp = curEmp;
        curEmp = curEmp->next;

        if(freeEmp != NULL)
        {
            free((void *)freeEmp);
        }
    }

    /*Set head to null*/
    *head = NULL;
}
