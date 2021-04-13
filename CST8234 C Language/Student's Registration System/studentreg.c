/*****************************************************************************
 FILE      :  studentreg.c
 PROGRAM   :  Student Registration System
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

/***********************************************
 Include private library headers.
***********************************************/
#include "studentreg.h"

/**********************************************
* Function Name: Main
* PURPOSE: Runs main logic of program
* INPUT: none
* RETURN:  0
***********************************************/
int main()
{
  int loop = 1;/*Main loop*/
  int x = 0;/*for loop counters*/
  int numStudents = 0; /*Keep track of number of students*/
  int numCourses = 0; /*Keep track of number of courses*/
  char * menuPromt = "Please enter a menu option:";/*Menu prompt*/
  char * invOption = "Invalid menu option...";/*Invalid option prompt*/
  int menuOption; /*Menu option from user*/

  /*Print welcome message*/
  printf("Welcome to the Student Registation System!\n\n");

  /*Get Student info*/
  numStudents = setStudentInfo();

  printf("\n");/*add a new line between prompts*/

  /*prompt for number of courses offered*/
  numCourses = setCourseInfo();

  /* Debug students, print to console
  for (x  = 0; x < numStudents; x++){
      printf("%d: %d\n",x, students[x]);
  }*/

  /* Debug courses, print to console
  for (x  = 0; x < numCourses; x++){
      printf("%d: %s\n",x, courses[x]);
  }*/

  /*Allocate memory for reg table*/
  regTable = (int**) malloc(sizeof(int*) * numStudents);

  /*Allocate memory for reg table items*/
  for (x  = 0; x < numStudents; x++){
    regTable[x] = (int *) calloc(numCourses, sizeof(int));
  }

  /*loop forever until quit option*/
  while (loop)
  {
    /*prompt for action,*/
    /* 1. Register student in course*/
    /* 2. Drop stuudent form course*/
    /* 3. Display Registration table*/
    /* 4. Quit Program*/
    printMenu();
    /*Get the menu option*/
    menuOption = getIntegerInput(menuPromt, invOption, invOption, 1, 4, DISABLED, DISABLED);

    /*Option 1: Add student to a course*/
    if(menuOption == 1)
    {
      /*update registration table, it will call to validate
        student id and course code. Calling with option add*/
      updateRegTable(numStudents, numCourses, REGISTER);
    }

    /*Option 2: Drop a student from a course*/
    if(menuOption == 2)
    {
      /*update registration table, it will call to validate
        student id and course code. Calling with option remove*/
      updateRegTable(numStudents, numCourses, DROP);
    }

    /*Option 3: Display the registration table*/
    if(menuOption == 3)
    {
      printRegTable(numStudents, numCourses);
    }

    /*Option 4: Quit*/
    if(menuOption == 4)
    {
      printf("\nQuitting...\n\n");
      loop = 0;
      break;
    }

  }/*end while*/

  /*Free memory before exit*/
  free(students);
  students = NULL;
  destroyCourses(numCourses);
  destroyRegtable(numStudents);

  return EXIT_SUCCESS;
}
/**********************************************
* Function Name: printMenu
* PURPOSE: Menu to console
* INPUT: none
* RETURN:  none
***********************************************/
void printMenu(){
  /*print main menu*/
  printf("\nMenu:\n");
  printf("1) Register student in course.\n");
  printf("2) Drop student from course.\n");
  printf("3) Display Registration table.\n");
  printf("4) Quit Program.\n");
}

/**********************************************
* Function Name: printRegTable
* PURPOSE: Prints the registration table
* INPUT: int numStudents: the number of students
* int numCourses: the number of courses
* RETURN:  none
***********************************************/
void printRegTable(int numStudents, int numCourses)
{
  int row,col;
  int counter = 0;
  printf("\n-----Registration Table-----\n\n");
  for(row = 0; row < numStudents; row++)
  {
    
    for(col = 0; col < numCourses; col++)
    {
      counter++;
      printf(" %d  ", regTable[row][col]);
      
    }
    printf("\n\n");
  }
}
/**********************************************
* Function Name: updateRegTable
* PURPOSE: Updates the registration table
* INPUT: int numStudents: the number of students
* int numCourses: the numbe rof courses
* int mode: 1 for add, 0 for remove
* RETURN:  none
***********************************************/
void updateRegTable(int numStudents, int numCourses, int mode)
{
  int stuIndex;
  int crsIndex;
  int val = 0;/*Value to set, default to 0*/

  /*Prompt and get student ID index*/
  stuIndex = validateStudentId(numStudents);

  /*Prompt and get course code index*/
  crsIndex = validateCourseCode(numStudents);

  /*check if mode is adding course*/
  if(mode == 1)
  {
    val = 1;
  }

  /*Set value in reg table*/
  regTable[stuIndex][crsIndex] = val;

}
/**********************************************
* Function Name: setStudentsInfo
* PURPOSE: To populate students array and get info needed
* INPUT: none
* RETURN:  size of array
***********************************************/
int setStudentInfo()
{
  int stuID; /*student number input*/
  int size;/*size for student array*/
  int x;/*For loop counter*/
  char * prompt1 = "How many Students will be registered:";/*String for prompt*/
  char * prompt2 = "Please enter 5 digit student ID for student";/*String for prompt*/
  char * small = "Invalid! input must be a positive integer.";/*String number too small*/
  char * large = "Invalid! input number too large (>100).";/*String for number too large*/

  /*prompt for number of students*/
  size = getIntegerInput(prompt1, small, large, MINITEMS, MAXITEMS, DISABLED, DISABLED);

  /*Allocate memory for students array, set values to 0*/
  students = (int*) calloc(size, sizeof(int));

  /*Loop to prompt for student numbers for each student*/
  for (x = 0; x < size; x++)
  {
    /*get student number input*/
    stuID = getIntegerInput(prompt2, EMPSTR, EMPSTR, DISABLED, DISABLED, SNUMSIZE, x+1);
    students[x] = stuID;
  }

  return size;/*return size of array*/
}/*end getStudentInfo function*/

/**********************************************
* Function Name: setCourseInfo
* PURPOSE: To populate course array and get info needed
* INPUT: none
* RETURN:  size of array
***********************************************/
int setCourseInfo(){
  int numCourses = 0; /*course Number Input*/
  int i; /*for loop counter*/
  char * prompt1 = "How many courses will be offered:";/*String for prompt*/
  char * prompt2 = "Please enter 7 digit course code for course";/*String for prompt*/
  char * small = "Invalid! input must be a positive integer.";/*String number too small*/
  char * large = "Invalid! input number too large (>100).";/*String for number too large*/
  char * crsItem; /*Temp course item pointer */
  /*prompt for number of course offerings*/
  numCourses = getIntegerInput(prompt1, small, large, MINITEMS, MAXITEMS, DISABLED, DISABLED);

  /*Allocate memory for courses array*/
  courses = malloc(  numCourses * sizeof(char *));

  /*Prompt for each course code item*/
  /*function already allocates memory for the string*/
  for (i = 0; i < numCourses; i++) {
    /*Allocate memory for item */
    courses[i] = malloc( (CCODESIZE + 1) * sizeof(char *));

    /*Get the course code*/
    crsItem = getStringInput(prompt2, CCODESIZE, i+1);

    /*copy into courses array*/
    strcpy(courses[i], crsItem);

    /*Need to free the course item, no longer used*/
    free(crsItem);
    crsItem = NULL;
  }
  /*Returns number of courses */
  return numCourses;
}

/**********************************************
* Function Name: validateStudentId
* PURPOSE: to prompt for and validate a student id
* INPUT: int * students: pointer to the students array
* int numStudents: size of students array
* RETURN:  index of student id
***********************************************/
int validateStudentId(int numStudents)
{
  char * prompt = "Enter a valid Student ID:";
  int stuID;/*Student id to search*/
  int i;/*for lopp counter*/
  int index; /*The index of match*/
  int flag = 0; /*flag for match found*/

  /*loop until valid student id entered*/
  while(1)
  {
    /*Promt for 5 digit student ID*/
    stuID = getIntegerInput(prompt, EMPSTR, EMPSTR, DISABLED, DISABLED, SNUMSIZE, DISABLED);

    /*Loop through student array*/
    for(i = 0; i< numStudents; i++)
    {
      /*check if student found*/
      if(students[i] == stuID){
        flag = 1;
        index = i;
        break;/*No need to go through array anymore*/
      }
    }

    if(flag == 1)
    {
      return index;
    }
    else
    {
      printf("Error: Student with ID: %d not found, try again\n", stuID );
    }
  }
}
/**********************************************
* Function Name: validateCourseCode
* PURPOSE: to prompt for and validate a course code
* INPUT: int numCourses, size of courses array
* RETURN:  index of course code
***********************************************/
int validateCourseCode( int numCourses)
{
  char * prompt = "Enter a valid Course Code:";
  char * crsCode;/*course code to search*/
  int i;/*for loop counter*/
  int index; /*The index of match*/
  int flag = 0; /*flag for match found*/

  /*loop until valid student id entered*/
  while(1)
  {
    /*Promt for 7 digit coursecode*/
    crsCode = getStringInput(prompt, CCODESIZE, DISABLED);

    /*Loop through student array*/
    for(i = 0; i< numCourses; i++)
    {
      /*check if student found*/
      if(strcmp(courses[i], crsCode) == 0){
        flag = 1;
        index = i;
        break;/*No need to go through array anymore*/
      }
    }

    if(flag == 1)
    {
      /*free course code item, no longer used*/
      free(crsCode);
      return index;
    }
    else
    {
      printf("Error: Course with CODE: %s not found, try again\n", crsCode );
      free(crsCode);/*Free the temp course code*/
      crsCode = NULL;/*set to empty string*/
    }

  }
}

/**********************************************
* Function Name: getIntegerInput
* PURPOSE: Helper function get integer from user input, has two modes
* min/max, or num digits
* INPUT: char * prompt : string for main prompt
* char * tooSmall : string for number too small
* char * tooLarge : string for number too large
* int min: the minimum number value
* int max: the upper number value
* int numDigits: the number of digits, pass 0 to disable
* int pCount: used to add count number to prompt
* RETURN:  integer input
***********************************************/
int getIntegerInput(char *prompt, char *tooSmall, char *tooLarge, int min, int max, int numDigits, int pCount){

  int temp;/*Temp value, will be the return number of function*/
  int tCopy;/*used as copy value to count the digits*/
  int count;/*store the count*/

  /*loop forever until integer passed*/
	while(1)
	{
    /*Print prompt, check if pcount provided*/
    (pCount > 0)? (  printf("%s %d:\n", prompt, pCount) ) : (  printf("%s\n", prompt) );

    /*get user input, check if integer */
    if(scanf("%d",&temp) != 1)
    {
      printf("Invalid! input must be an integer.\n");
      fflush(stdin); /*flush standard input*/
      while( getchar() != '\n' ); /*clear input buffer*/
    }
    else
    {
      /* min-max mode*/
      if(numDigits == 0){
        /*check if in min/max mode*/
        if(temp>= min && temp<=max)
        {
          return temp;
        }
        if(temp < min) /*check if number is too small*/
        {
          printf("%s\n",tooSmall);
        }
        if(temp > max) /*check if number is too large*/
        {
          printf("%s\n",tooLarge);
        }
      }
      else  /* numDigits mode*/
      {
        /*Copy temp for count*/
        tCopy = temp;
        count = 0;/*set count to 0*/
        /*Count the digits*/
        while(tCopy != 0){
          tCopy /= 10;
          ++count;
        }

        /*check count against numDigits*/
        if(count == numDigits)
        {
          return temp;
        }
        else
        {
          printf("Invalid number of digits!\n");
        }
      }
    }
	}/*end while*/
}/*end function*/

/**********************************************
* Function Name: getStringInput
* PURPOSE: Helper function to get string from user
* INPUT: char * prompt : string for main prompt
* int numDigits int for max size
* int pCount: used to add count into prompt
* RETURN:  integer input
***********************************************/
char * getStringInput(char * prompt, int numDigits, int pCount)
{
  char * strRet;/*pointer to return string*/
  char inputArr[MAXINPUT];/*Temp array for user input max size of 20*/
  int tSize = 0;/*used for size of string*/
  int flag;/*flag for validation*/
  int x; /*For loop counter*/

  /*loop forever until valid string*/
  while(1)
  {
    /*Print prompt, check if pcount provided*/
    (pCount > 0)? (  printf("%s %d:\n", prompt, pCount) ) : (  printf("%s\n", prompt) );

    /*Read number as string*/
    scanf("%s", inputArr);

    /*Get size of string*/
    tSize = strlen(inputArr);
    flag = 0;
    /*string is right size*/
    if(tSize == numDigits)
    {
      /*validate string contents (must be alphanumeric)*/
      for (x = 0; x < tSize; x++)
      {
        /*check if alphanumeric using isalnum() function from c standard library*/
        if(!isalnum(inputArr[x]))
        {
          flag = 1;/*set flag*/
          break;
        }
      }

      /*String is alphanumeric, allocate memory and return*/
      if(flag == 0)
      {
        /*allocate memory for user input and return*/
        strRet = malloc(sizeof(char) * numDigits + 1);

        /*copy input string into return string*/
        strcpy(strRet, inputArr);

        return strRet;/*Returns pointer to string*/
      }
      else
      {
        printf("Invalid! input must be alphanumeric\n");
      }
    }
    else
    {
      /*Print item is wrong size*/
      ( tSize > CCODESIZE)? (printf("Invalid! input too large\n")):( printf("Invalid! input too small\n") );
    }

  }/*end while*/
}

/**********************************************
* Function Name: destroyCourses
* PURPOSE: Function to free spaced used by courses
* INPUT: int items: number of courses in array
* RETURN:  n/a
***********************************************/
void destroyCourses(int items){
  int i;

  /*Free each item in courses array*/
  for (i = 0; i < items; i++) {
    free(courses[i]);
  }
  free(courses);
  courses = NULL;
  return;
}

/**********************************************
* Function Name: destroyRegtable
* PURPOSE: Function to free spaced used by regtable
* INPUT: int items: number of courses in array
* RETURN:  n/a
***********************************************/
void destroyRegtable( int items){
  int i;
  /*Free each item in courses array*/
  for (i = 0; i < items; i++) {
    free(regTable[i]);
  }
  free(regTable);
  regTable = NULL;
  return;
}
