#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CQueue.h"


struct Queue *createEmptyQ()
{
    struct Queue *queue=(struct Queue*)malloc(sizeof(struct Queue));
    printf("\n Now creating an empty queue...\n\n");
    queue->list=createEmptyList();
    printf("\n Empty queue is created.\n\n");
    return queue;

}

void enqueue(struct Node *node, struct Queue *queue)
{
        appendToEnd(node,queue->list);
    //printNumberOfElementsInQueue(queue);
}

void dequeue(struct Queue *queue)
{
    struct Node* temp=queue->list->head;
    if(queue->list->head==NULL)
    {
        printf("\n Warning : Trying to dequeue from an empty queue\n\n");

    }
    else
    {
        /*temp = temp->next;

        printf("\n Dequeued element is: \n\n");
        printElementInQueue(queue->list->head);
        free(queue->list->head);
        queue->list->head = temp;
        queue->list->numberOfElements--;
        printNumberOfElementsInQueue(queue);*/
        printf("\n Dequeued element is: \n\n");
        printElementInQueue(queue->list->head);
        deleteAtPosition(0,queue->list);
        queue->list->numberOfElements--;
        printNumberOfElementsInQueue(queue);


    }
    return;

}

struct Node* firstElementInQueue(struct Queue *queue)
{

    if(queue->list->head==NULL)
    {
        printf("\n Warning : This is an empty queue.\n\n");
        return NULL;
    }

    return queue->list->head;
}

int lengthOfQueue(struct Queue *queue)
{
    return queue->list->numberOfElements;
}

void destroyQ(struct Queue *queue)
{
    if(queue->list->head==NULL)
    {
        printf("\n Warning : This is already an empty queue, you cannot destroy it.\n\n");
        return;
    }
    destroy(queue->list);
}

void printQueue(struct Queue *queue)
{
    struct Node *pr=queue->list->head;
    int counter=0;
    if(pr==NULL)
        printf("\n This is an empty queue.\n\n");
    while(pr!=NULL)
    {
        printf("********************\n");
        printf("Index: %d\n", counter);
        printf("First name: %s\n", pr->firstName);
        printf("Last name: %s\n", pr->lastName);
        printf("BirthDay: %d\n", pr->birthDay);
        printf("BirthMonth: %d\n", pr->birthMonth);
        printf("BirthYear: %d\n", pr->birthYear);
        printf("********************\n\n");

        pr=pr->next;
        counter++;

    }
}

void printElementInQueue(struct Node* pr)
{
    int counter=0;
    if(pr==NULL)
        printf("\n This is an empty stack.\n\n");

    printf("********************\n");
    printf("Index: %d\n", counter);
    printf("First name: %s\n", pr->firstName);
    printf("Last name: %s\n", pr->lastName);
    printf("BirthDay: %d\n", pr->birthDay);
    printf("BirthMonth: %d\n", pr->birthMonth);
    printf("BirthYear: %d\n", pr->birthYear);
    printf("********************\n\n");

}
void printNumberOfElementsInQueue(struct Queue *queue)
{
    printf("The number of total elements in the queue is: %d\n\n", queue->list->numberOfElements);

}






