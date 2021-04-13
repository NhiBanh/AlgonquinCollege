/*****************************************************************************
 FILE      :  Employee.h
 PROGRAM   :  Assignment 2, Employee database header file
 AUTHOR    :  Nhi Banh
 STUDENT_NUMBER: XXX XXX XXX
*****************************************************************************/
/***********************************************
* Declare constants
***********************************************/
#define MAX_NAME_LENGTH 100
#define MAX_JOB_LENGTH 100
#define MAX_EMPLOYEES 150

/***********************
Employee Linked list struct
************************/
struct Employee
{
    /*Employee details*/
    char name[MAX_NAME_LENGTH];
    char gender;
    int age;
    char job[MAX_JOB_LENGTH];

    /*pointers to next employee structures in the linked list */
    struct Employee *next;

}typedef Employee;

/***********************************************
* Function prototypes.
***********************************************/
void print_employees(Employee  * empll, int* size);
void employee_search_insert(Employee**head, char * srcname, int field);
void employee_add(Employee **head, int* size );
void employee_update(Employee **head, int * size);
void employee_remove(Employee **head, int* size);
void employee_destroy(Employee **head);
