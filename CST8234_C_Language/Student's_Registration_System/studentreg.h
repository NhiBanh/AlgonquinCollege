/*****************************************************************************
 FILE      :  studentreg.h
 PROGRAM   :  Student Registration System
 AUTHOR    :  Nhi Banh
 STUDENT_NUMBER: XXX XXX XXX
*****************************************************************************/
/***********************************************
* Declare constants
***********************************************/
#define MAXINPUT 20
#define MINITEMS 1
#define MAXITEMS 20
#define SNUMSIZE 5
#define CCODESIZE 7
#define DISABLED 0
#define EMPSTR ""
#define REGISTER 1
#define DROP 0
/***********************************************
* Global Variables
***********************************************/
int * students;/*Pointer to students*/
char ** courses;/*Pointer to course strings*/
int ** regTable;/*Pointer to registration table */
/***********************************************
* Function prototypes.
***********************************************/
void printMenu();
void printRegTable(int numStudents, int numCourses);
void updateRegTable(int numStudents, int numCourses, int mode);
int setStudentInfo();
int setCourseInfo();
int validateStudentId(int numStudents);
int validateCourseCode(int numCourses);
int getIntegerInput(char *prompt, char *tooSmall, char*tooLarge,int min, int max, int numdigits, int pCount);
char * getStringInput(char *prompt, int size, int pCount);
void destroyCourses( int items);
void destroyRegtable( int items);
