/*****************************************************************************************************
* File: CStack.c
* Course: Data Structures and Algorithms for Engineers
* Project: A4
* Author: Xin Huang
* Versions:
*	1.0 November 2016
*
* Description: This program provides Stack operations such as create empty stack, push, pop, etc.
*
* Parameters: N/A
*
* Internal Functions: struct Stack* createEmptyS();
                      void push(struct Node *node, struct Stack *stack);
                      void pop(struct Stack *stack);
                      struct Node* topElementInStack(struct Stack *stack);
                      int lengthOfStack(struct Stack *stack);
                      void destroyS(struct Stack *stack);
                      void printElementInStack(struct Node *node);
                      void printNumberOfElementsInStack(struct Stack *stack);
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "CStack.h"

/*********************************************************************
* Function Name:    createEmptyS
* Description:      This function creates an empty stack.
* Input Parameters: None
* Output:           An empty stack.
***********************************************************************/

struct Stack *createEmptyS() {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));  //Allocate memory for a stack to be created.
    printf("\n Now creating an empty stack...\n\n");
    stack->list = createEmptyList();                                    //Call an API of LinkedList.c to create empty list.
    printf("\n Empty stack is created.\n\n");

    return stack;
}

void push(struct Node *node, struct Stack *stack) {
    if (stack->list->head == NULL) {
        stack->list->head = node;
        stack->list->numberOfElements++;
        return;
    }
    node->next = stack->list->head;
    stack->list->head = node;
    stack->list->numberOfElements++;
}

void pop(struct Stack *stack) {
    struct Node *temp = stack->list->head;
    if (stack->list->head == NULL) {
        printf("\n Warning : Trying to pop from an empty stack\n\n");

    } else {
        printf("\n Popped element is: \n\n");
        printElementInStack(stack->list->head);
        deleteAtPosition(0, stack->list);
        stack->list->numberOfElements--;
        printNumberOfElementsInStack(stack);
    }
    return;

}

struct Node *topElementInStack(struct Stack *stack) {
    if (stack->list->head == NULL) {
        printf("\n Warning : This is an empty stack.\n\n");
        return NULL;
    }
    return stack->list->head;
}

int lengthOfStack(struct Stack *stack) {
    return stack->list->numberOfElements;
}

void destroyS(struct Stack *stack) {
    if (stack->list->head == NULL) {
        printf("\n Warning : This is already an empty stack, you cannot destroy it.\n\n");
        return;
    }

    destroy(stack->list);
    if (stack->list) {
        free(stack->list);
        stack->list = NULL;
    }
    //free(stack);
}

void printElementInStack(struct Node *node) {
    int counter = 0;
    struct Node *pr = node;
    if (node == NULL)
        printf("\n Warning : This is an empty stack.\n\n");

    printf("********************\n");
    printf("Index: %d\n", counter);
    printf("First name: %s\n", pr->firstName);
    printf("Last name: %s\n", pr->lastName);
    printf("BirthDay: %d\n", pr->birthDay);
    printf("BirthMonth: %d\n", pr->birthMonth);
    printf("BirthYear: %d\n", pr->birthYear);
    printf("********************\n\n");

}

void printNumberOfElementsInStack(struct Stack *stack) {
    printf("\n The number of total elements in the stack is: %d\n\n", lengthOfStack(stack));
}




