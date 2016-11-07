//
// Created by Rachel on 11/2/16.
//

#ifndef SQ_ADT_CQUEUE_H
#define SQ_ADT_CQUEUE_H
#include "CLinkedList.h"
struct Queue {

    struct LinkedList *list;
};
struct Queue *createEmptyQ();
void enqueue(struct Node *node, struct Queue *queue);
void dequeue(struct Queue *queue);
struct Node* firstElementInQueue(struct Queue *queue);
int lengthOfQueue(struct Queue *queue);
void destroyQ(struct Queue *queue);
void printQueue(struct Queue *queue);
void printElementInQueue(struct Node* pr);
void printNumberOfElementsInQueue(struct Queue *queue);
#endif //SQ_ADT_CQUEUE_H
