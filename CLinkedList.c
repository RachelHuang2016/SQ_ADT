/*****************************************************************************************************
* File: CLinkedList.c
* Course: Data Structures and Algorithms for Engineers
* Project: A4
* Author: Xin Huang
* Versions:
*	1.0 November 2016
*
* Description: This program provides Linked List operations such as append, delete and destroy, which can be reused by
*              Stack and Queue operations.
*
* Parameters: N/A
*
* Internal Functions: struct LinkedList* createEmptyList();
                      void appendToEnd(struct Node *node, struct LinkedList *list);
                      void deleteAtPosition(int index, struct LinkedList *list);
                      void destroy(struct LinkedList *list).
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

/*********************************************************************
* Function Name:    createEmptyList
* Description:      This function creates an empty list.
* Input Parameters: None
* Output:           An empty list
***********************************************************************/

struct LinkedList* createEmptyList()
{
    struct LinkedList *list=(struct LinkedList*)malloc(sizeof(struct LinkedList)); //Allocate memory for the new linked list.
    list->numberOfElements=0;             //Re-set global variables to the initial state to make sure the list is set as empty.
    list->head=NULL;
    return list;
}

/*********************************************************************
* Function Name:   appendToEnd
* Description:     This function appends a new element to the exsiting list
*                  after the user enters the five properties of the element.
* Input Parameters:
*                  Node *node: a new node the user will append to the end.
*                  LinkedList *list: The specific list that the user wants
*                  to operate on.
* Postcondition:   The new node has been appended to the end of the list.
***********************************************************************/

void appendToEnd(struct Node *node, struct LinkedList *list)
{
    struct Node *temp;
    temp=list->head;
    if(list->head==NULL)          //When the list is empty, we set the passed node as the head and the only node in the list.
    {
        list->head=node;
        list->numberOfElements++; //In the meantime, the value of numberOfElements is increased by 1 to indicate a new
                                  //node is added into the list.
    }
    else
    {
        while(temp->next!=NULL)  //If the list is not empty, we append the new node into the end of the list.
        {
            temp=temp->next;
        }
        temp->next=node;
        temp=node;
        temp->next=NULL;
        list->numberOfElements++;
    }
    return;
}

/*********************************************************************
* Function Name:   deleteAtPosition
* Description:     This function deletes an existing node at a specific
*                  position of the list.
* Input Parameters:
*                 int index: the position of the target node in the list.
*                 LinkedList *list: The specific list that the user wants
*                 to operate on.
* Postcondition:  The node which at the specific position has been deleted.
***********************************************************************/

void deleteAtPosition(int index, struct LinkedList *list)
{
    struct Node *temp=list->head;

    if (list->head==NULL)                               //If the list is empty, we notify the user about the information.
    {
        printf("\n This is an empty list. you cannot delete any element.\n");
        return;
    }

    if (index > list->numberOfElements-1 || index < 0)  //If the index goes beyond the range of 0-numberOfElements-1,
    {                                                   //notify the user.
            printf("\n Invalid index.\n");
            return;
    }
    if(index==0)                                 //If the index is 0, then move head to the next node and free temp.
    {
        list->head=list->head->next;
        free(temp);
    }
    else
    {                                           //Otherwise, we simply create a node named prev stays at the previous
        struct Node *prev=NULL;                 //location of temp, and move both node at the same speed until the temp
        for(int i=0;i<index;i++)                //node reaches the position of index.
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp!=NULL)
            prev->next=temp->next;            //If temp node happens to reach the last node, then point prev node to NULL
        else                                  //to delete the temp node as it is the target node. Otherwise, set
            prev->next = NULL;                //prev->next=temp->next, to delete the temp node.
        free(temp);
    }
}

/*********************************************************************
* Function Name:   destroy
* Description:     This function destroies a linked list to make it empty.
* Input Parameters:
*                 LinkedList *list: The specific list that the user wants
*                 to operate on.
* Postcondition:  The specific list became empty.
***********************************************************************/

void destroy(struct LinkedList *list)
{
    while(list->head!=NULL)               //Iterate the list to free each node if the list is not empty.
    {
        struct Node *temp=list->head;
        list->head=list->head->next;//in the list.
        if (temp) {
            free(temp);
            temp = NULL;
        }

    }
    list->numberOfElements=0;             //Re-set global variables to the initial state to make sure the list is set as empty.
    list->head=NULL;

    //free(list);
    printf("\n All elements are destroyed.\n\n");
}










