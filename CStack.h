//
// Created by Rachel on 11/2/16.
//

#ifndef SQ_ADT_CSTACKQUEUE_H
#define SQ_ADT_CSTACKQUEUE_H
#include "CLinkedList.h"
struct Stack {
    struct LinkedList *list;
};
struct Stack* createEmptyS();
void push(struct Node *node, struct Stack *stack);
void pop(struct Stack *stack);
int lengthOfStack(struct Stack *stack);
void destroyS(struct Stack *stack);
void printStack(struct Stack *stack);
void printElementInStack(struct Node *node);
void printNumberOfElementsInStack(struct Stack *stack);
struct Node* topElementInStack(struct Stack *stack);
#endif //SQ_ADT_CSTACKQUEUE_H
