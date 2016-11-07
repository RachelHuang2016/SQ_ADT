//
// Created by Rachel on 10/18/16.
//

#ifndef P2_CLINKEDLIST_H
#define P2_CLINKEDLIST_H

struct LinkedList {

    struct Node *head;
    int numberOfElements;
};

struct Node {

    char firstName[128];
    char lastName[128];
    int birthDay;
    int birthMonth;
    int birthYear;
    struct Node *next;
};

/*********************************************************************
* Function Name:  createEmptyList
* Description: This function creates an empty list.
* Input parameters: N/A
* Output: N/A
***********************************************************************/

struct LinkedList* createEmptyList();

/*********************************************************************
* Function Name:  printList
* Description: This function prints each element of the list one by one.
* Input parameters: N/A
* Output: N/A
***********************************************************************/

void printList();

/*********************************************************************
* Function Name:  appendToEnd
* Description: This function appends a new element to the exsiting list
*              after the user enters the five properties of the element.
* Input parameters: N/A
* Output: N/A
***********************************************************************/

void appendToEnd(struct Node *node, struct LinkedList *list);

/*********************************************************************
* Function Name:  lengthOfList
* Description: This function returns the number of elements in the list.
* Input parameters: N/A
* Output: Integer
***********************************************************************/

int  lengthOfList();

/*********************************************************************
* Function Name:  insertNode
* Description: This function inserts a new node into a specific postion
*              of the list. There are 4 conditions needed to consider for
*              different behaviors: when the position is the head of the
*              list, when the position equals to the length of the list,
*              when the position is neither the head nor the end of the
*              list but valid, when the index goes beyond the valid range.
* Input parameters: N/A
* Output: N/A
***********************************************************************/

void insertNode(struct Node *node, int index);

/*********************************************************************
* Function Name:  deleteAtPosition
* Description: This function deletes an existing node at a specific postion
*              of the list.
* Input parameters: N/A
* Output: N/A
***********************************************************************/

void deleteAtPosition(int index, struct LinkedList *list);

/*********************************************************************
* Function Name:  deleteAnyWithLastName
* Description: This function deletes all elements which have the specified
*              last name.
* Input parameters: N/A
* Output: N/A
***********************************************************************/

void destroy(struct LinkedList *list);


#endif //P2_CLINKEDLIST_H