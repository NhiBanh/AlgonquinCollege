/*****************************************************************************
 FILE      :  linked_list.c
 PROGRAM   :  Single Linked List
 AUTHOR    :  Nhi Banh
 STUDENT_NUMBER: 040 932 192
*****************************************************************************/
/***********************************************
* Include C library headers.
***********************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************
* Declare constants
***********************************************/

/***********************
Linked list node struct
************************/
typedef struct node {
  int data;
  struct node *next;
}node_t;

/***********************************************
* Function prototypes.
***********************************************/
int llist_push(node_t **head, int element);
int llist_pop(node_t **head);
int llist_size(node_t *head);
void printList(node_t * node);
int llist_contains(node_t *head, int element);
int llist_count(node_t *head, int element);
void llist_addlast(node_t *head, int element);
int llist_insert(node_t **head, int index, int element);
int llist_remove(node_t **head, int element);
void llist_free(node_t **head);
/**********************************************
* Function Name: Main
* PURPOSE: Test linked list functions
* INPUT: none
* RETURN:  0
***********************************************/
int main(){
  int i = 0;
  int flag = 0;
  int assert = 0;
  int size1 = 0;
  int size2 = 0;

  /*Create node head pointer(to linked list)*/
  node_t * head = NULL;

  /*****************************
  * Test 1 : Easy Function
  * llist_contains()
  *****************************/
  /*Populate the list for test 1*/
  for(i= 0; i< 5; i++){
    llist_push(&head, i+1);
  }

  /*Test for an element in the list*/
  assert = llist_contains(head, 3);

  /*Check if return value is invalid*/
  if(assert == 0 ){
    flag = 1;
  }

  /* Test for element not in list*/
  assert = llist_contains(head, 11);

  /*Check if return value is invalid*/
  if(assert == 1){
    flag = 1;
  }

  /*Print Test Results*/
  if(flag == 1){
    printf("Testing list_contains().....Failed\n");
  }else{
    printf("Testing list_contains().....Passed\n");
  }

  /*Free the List*/
  llist_free(&head);

  flag = 0;  /*Reset flag for next test*/
  assert = 0; /*Reset assert for next Test*/
  /*****************************
  * End Test 1
  *****************************/
  /*****************************
  * Test 2 : Easy Function
  * llist_count()
  *****************************/
  /*Populate the list for test 2*/
  for(i= 0; i< 5; i++){
    /*Push all same values into list*/
    llist_push(&head, 3);
  }

  /*Test for an element in the list*/
  assert = llist_count(head, 3);

  /*Check if return value is invalid*/
  if(assert == 0 ){
    flag = 1;
  }

  /* Test for element not in list*/
  assert = llist_count(head, 11);

  /*Check if return value is invalid*/
  if(assert > 0){
    flag = 1;
  }

  /*Print Test Results*/
  if(flag == 1){
    printf("Testing llist_count().....Failed\n");
  }else{
    printf("Testing llist_count().....Passed\n");
  }

  /*Free the List*/
  llist_free(&head);

  flag = 0;  /*Reset flag for next test*/
  assert = 0; /*Reset assert for next Test*/
  /*****************************
  * End Test 2
  *****************************/
  /*****************************
  * Test 3 : Medium Function
  * llist_addlast()
  *****************************/
  /*Populate the list for test 3*/
  for(i= 0; i< 3; i++){
    llist_push(&head, i+1);
  }

  /*Get size of list before adding new tail element*/
  size1 = llist_size(head);

  /*Add element (with value not in list) to end of list*/
  llist_addlast(head, 4);

  /*Getr size after adding to tail*/
  size2 = llist_size(head);

  /*Check if list is larger than before*/
  if(size2 > size1){
    /*Check if item was added to tail, can infer as list before
    * did not contain 4 as value. Should use llist_find(),
    * but did not implement that function. using llist_contains() instead
    */
    assert = llist_contains(head, 4);
    if( assert == 0 ) /*Check if item not found*/
    {
      flag = 1;
    }

  }else{
    /*Failed, item not added*/
    flag = 1;
  }

  /*Print Test Results*/
  if(flag == 1){
    printf("Testing llist_addlast().....Failed\n");
  }else{
    printf("Testing llist_addlast().....Passed\n");
  }

  /*Free the List*/
  llist_free(&head);

  flag = 0;  /*Reset flag for next test*/
  assert = 0; /*Reset assert for next Test*/
  /*****************************
  * End Test 3
  *****************************/
  /*****************************
  * Test 4 : Medium Function
  * llist_insert()
  *****************************/
  /*Populate the list for test 4*/
  for(i= 0; i< 5; i++){
    llist_push(&head, i+1);
  }

  /*Try to add to negative index*/
  assert = llist_insert(&head, -1, 6);

  /*Expected 0 return as index is not valid*/
  if(assert == 1 ){
    flag = 1;
  }

  /*Try to add to index that is too large*/
  assert = llist_insert(&head, 5, 6);

  /*Expected 0 return as index is not valid*/
  if(assert == 1 ){
    flag = 1;
  }

  /*Try to add valid index*/
  assert = llist_insert(&head, 2, 6);

  /*Expected 1 return as index valid*/
  if(assert == 0 ){
    flag = 1;
  }

  /*Print Test Results*/
  if(flag == 1){
    printf("Testing llist_insert().....Failed\n");
  }else{
    printf("Testing llist_insert().....Passed\n");
  }

  /*Free the List*/
  llist_free(&head);

  flag = 0;  /*Reset flag for next test*/
  assert = 0; /*Reset assert for next Test*/
  /*****************************
  * End Test 4
  *****************************/
  /*****************************
  * Test 5 : Medium Function
  * llist_remove()
  *****************************/
  /*Populate the list for test 5*/
  for(i= 0; i< 5; i++){
    llist_push(&head, i+1);
  }

  /*Try to remove element not in list*/
  assert = llist_remove(&head, 6);

  /*Expected 0 return as value not in list*/
  if(assert == 1)
  {
    flag = 1;
  }

  /*Delete the head node*/
  assert = llist_remove(&head, 5);

  /*Expected 1 as element is in list*/
  if(assert == 0)
  {
    flag = 1;
  }

  /*get number of element with value of 5*/
  size1 = llist_count(head, 5);

  /*check that count is not 0*/
  if(size1 != 0)
  {
    flag = 1;
  }

  /*Remove from middle of list*/
  assert = llist_remove(&head, 3);

  if(assert == 0)
  {
    flag = 1;
  }

  /*get number of element with value of 3*/
  size1 = llist_count(head, 3);

  /*check that count is not 0*/
  if(size1 != 0)
  {
    flag = 1;
  }

  /*Delete the head node*/
  assert = llist_remove(&head, 1);

  /*Expected 1 as element is in list*/
  if(assert == 0)
  {
    flag = 1;
  }

  /*get number of element with value of 1*/
  size1 = llist_count(head, 1);

  /*check that count is not 0*/
  if(size1 != 0)
  {
    flag = 1;
  }

  /*Print Test Results*/
  if(flag == 1){
    printf("Testing llist_remove().....Failed\n");
  }else{
    printf("Testing llist_remove().....Passed\n");
  }

  /*Free the List*/
  llist_free(&head);
  /*****************************
  * End Test 6
  *****************************/

  /*Set head to NULL*/
  head = NULL;

  return EXIT_SUCCESS;
}

/**********************************************
* Function Name: llist_push
* PURPOSE: Add an element to the head of the
* linked list
* INPUT: pointer to head of linked list
* RETURN:  0
***********************************************/
int llist_push(node_t  **head, int element)
{
  /*Allocate memory for new node*/
  node_t * newNode = malloc(sizeof(node_t));

  /*Point the head of the new node to the old head*/
	newNode->next = *head;

  /*Set the value of data*/
  newNode->data = element;

  /*Point the head to the new node*/
	*head = newNode;
  
  return 0;
}

/**********************************************
* Function Name:llist_pop
* PURPOSE: Removes an element from the head
* of the linked list
* INPUT: pointer to head of linked list
* RETURN:  0
***********************************************/
int llist_pop(node_t  **head)
{
  /*Store current head in temp var*/
  struct node *temp = *head;

  if(temp != NULL){
    /*point head to next item*/
    *head = temp->next; /* Changed head*/
    free(temp); /* free old head*/
  }

  return 0;
}

void printList(node_t  * node)
{
  if(node == NULL){
    printf("Empty List\n");
  }
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
  printf("\n");
}
/**********************************************
* Function Name:llist_size
* PURPOSE: Returns the number of elements in the list
* INPUT: pointer to head of linked list
* RETURN:  0
***********************************************/
int llist_size(node_t *head)
{
  int count = 0;
  /*Set current to point to head*/
  node_t * current = head;

  /*Iterate current until tail*/
  while (current != NULL) {
    ++count;/*Iterate count*/
    current = current->next;
  }

  return count;
}

/**********************************************
* Function Name:llist_contains
* PURPOSE: Checks if an element is contained in the list
* INPUT: pointer to head of linked list, int to search for
* RETURN:  1 of element exists, 0 otherwise
***********************************************/
int llist_contains(node_t *head, int element)
{
  int found = 0;
  /*Set current to point to head*/
  node_t * current = head;

  /*Iterate current until tail*/
  while (current != NULL) {

    /*Check if element matches current node data*/
    if(element == current->data){
      found = 1;/*Element exists*/
      break;/*Break loop, no need to continue*/
    }

    current = current->next;
  }

  return found;
}

/**********************************************
* Function Name:llist_count
* PURPOSE: Counts how many time an element is in the list
* INPUT: pointer to head of linked list, element data
* RETURN:  0 if no matches found, count otherwise
***********************************************/
int llist_count(node_t *head, int element)
{
  int count = 0;

  /*Set current to point to head*/
  node_t * current = head;

  /*Iterate current until tail*/
  while (current != NULL) {
    /*Check if element matches current node data*/
    if(element == current->data){
      count+=1;/*Increase count*/
    }

    current = current->next;
  }

  return count;
}

/**********************************************
* Function Name:llist_addlast
* PURPOSE: Adds an element to the tail of the list
* INPUT: pointer to head of linked list, element data
* RETURN:  nothing
***********************************************/
void llist_addlast(node_t *head, int element)
{
  /*Allocate memory for a new node*/
  node_t * newNode = malloc(sizeof(node_t));

  /*Set current to point to head*/
  node_t * current = head;

  /*Iterate current until tail*/
  while(current->next != NULL)
  {
    current = current->next;
  }

  /*Set data to element*/
  newNode->data = element;

  /*Set next to point to NULL (end of list)*/
  newNode->next= NULL;

  /*Point current tail node to newNode*/
  current->next= newNode;
}

/**********************************************
* Function Name:llist_insert
* PURPOSE: Adds an element at specified index
* INPUT: pointer to head of linked list
* RETURN:  0 if error, 1 otherwise
***********************************************/
int llist_insert(node_t **head, int index, int element)
{
  int i;/*Counter*/

  node_t * newNode;/*The newNode to add*/
  node_t * current = *head;  /*Set current to point to head*/
  int size = llist_size(*head);/*get size of linked list*/

  /*Validate index is within bounds*/
  if( (index < 0) || ( index > ( size - 1 ) ) )
  {
    return 0;/*Index out of bounds*/
  }

  /*Check if inserting head*/
  if(index == 0)
  {
    /*Add element to head*/
    llist_push(head, element);
  }
  else if( index == (size - 1) )/*Inserting at tail*/
  {
    /*Add element to tail*/
    llist_addlast(*head, element);
  }
  else /*In middle of linked list*/
  {
    /*Iterate until insertion point*/
    for(i = 0; i< index-1; ++i)
    {
      current = current->next;
    }
    /*
    [A]->[B]->[C]->[D]
     0    1    2    3
               |
              [E]
    [A]->[B]->[C]->[D]
         [E]->[C]
         [B]->[E]->[C]->[D]
    [A]->[B]->[E]->[C]->[D]
    */
    /*Create space for newNode*/
    newNode = malloc(sizeof(node_t));
    newNode->data = element;/*Set element value*/
    newNode->next = current->next; /*point newNode to next index*/
    current->next = newNode;/*point current next to newNode*/
  }
  /*
    Think of the flow, how to make it work,
    and how will it break,
    and how to mitigate (prevent) that

    Step by step, in one small section at a time.
    Rome was not built in a day. Neither is software.

    get the size ()

    validate the provided index, is within bounds of ll

    if not return 0,

    Head->[0]->[1]->[T]->Null

    check if inserting head,

    check if inserting tail

    all other cases
  */
  return 1;
}

/**********************************************
* Function Name:llist_remove
* PURPOSE: Removes first instance of value
* INPUT: pointer to head of linked list, element to remove
* RETURN:  0 for element not found, 1 otherwise
***********************************************/
int llist_remove(node_t **head, int element){
  int found = 0;/*Found element*/
  node_t * current = *head;/*Pointer to current head node*/
  node_t * prev = NULL; /*Pointer to previous node*/

  /*Check if head contains key*/
  if(current->data == element){
    llist_pop(head);/*Pop element from head of list*/
    return 1;
  }

  /*Iterate until end of linked list*/
  while (current != NULL)
  {
    if(element == current->data){
      found = 1;/*Element exists*/
      break;/*Break loop, no need to continue*/
    }

    prev = current;/*Point to current node*/
    current = current->next;/*Set current to point to next node*/
  }

  /*Element found*/
  if(found == 1){
    /*Set previous node to point to next node*/
    prev->next = current->next;
    free(current); /*Free current node*/
  }

  return found;
}

/**********************************************
* Function Name:llist_free
* PURPOSE: Delete (free) all nodes in linked list
* INPUT: pointer to head of linked list
* RETURN:  nothing
***********************************************/
void llist_free(node_t **head)
{
  node_t * current = *head; /*Pointer to current head node*/
  node_t * next; /*Pointer to the next node*/

  /*Iterate until end of linked list*/
  while (current != NULL)
  {
    next = current->next;/*Set next to point to the next node*/
    free(current);/*Free memory located at current node*/
    current = next;/*Set current to point to the next node*/
  }

  *head = NULL;  /*dereference the head, and set to NULL*/
}