#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CStack.h"
#include "CQueue.h"

struct Stack *stack=NULL;
struct Queue *queue=NULL;

struct Stack *createEmptyStack(struct Stack *stack)
{
    if(stack!=NULL)
    {
        if(stack->list->head!=NULL)
        {
            printf("\n The stack is not empty. Now destroying the stack...\n");
            destroyS(stack);
        }
    }
    else
    {
        stack = createEmptyS();

    }
    return stack;
}
struct Queue *createEmptyQueue(struct Queue *queue)
{
    if(queue!=NULL)
    {
        if(queue->list->head!=NULL)
        {
            printf("\n The queue is not empty. Now destroying the queue...\n");
            destroyQ(queue);
        }
    }
    else
    {
        queue = createEmptyQ();
    }
    return queue;
}
void createStackOrQueueFromFile(int input)
{
    int maxSize=1024;
    if(input==2)
    {
        stack=createEmptyStack(stack);
        /*if(stack!=NULL)
        {
            if(stack->list->head!=NULL)
            {
                printf("\n The stack is not empty. Now destroying the stack...\n");
                destroyS(stack);

            }
        }
        else
        {
            stack = createEmptyS();


        }*/

    }
    if(input==8)
    {
        queue=createEmptyQueue(queue);
        /*if(queue!=NULL)
        {
            if(queue->list->head!=NULL)
            {
                printf("\n The queue is not empty. Now destroying the queue...\n");
                destroyQ(queue);
            }
        }
        else
        {
            queue = createEmptyQ();
        }*/

    }
    FILE *fp;
    char fileName[maxSize];
    char readLine[maxSize];
    int counter=0;                     //A counter determines where the read data should be stored.
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));  //Allocate memory to create a new Node to store an element.

    printf("Please input the file name with complete path and file extension you would like to open to create the stack "
                   "or queue:\n");
    printf("For example: /Users/ClionProjects/test.txt\n");
    scanf("%s", fileName);         //The program reads the user input.
    fp = fopen (fileName, "r");        //Before reading the file, the file needs to be opened.
    if(fp==NULL)                       //It is possible that the file cannot be opened or does not exist, thus we need to
        // handle the exception by simply reporting the error details.
        perror("Error opening file");
    else {

        while (EOF != fscanf(fp,"%[^\n]\n",readLine)) {
            if (readLine[strlen(readLine) - 1] == '\n')    //If the program encounters the newline symbol "\n" while
                readLine[strlen(readLine) - 1] = 0;        //going through each line, it shouldn't be kept to store
            // into the node thus we delete it.
            if (counter % 5 == 0)                          //This indicates the program is reading the first name of the element.
                strcpy(node->firstName, readLine);
            if (counter % 5 == 1)                          //This indicates the program is reading the last name of the element.
                strcpy(node->lastName, readLine);
            if (counter % 5 == 2)                          //This indicates the program is reading the birth day of the element.
                node->birthDay = atoi(readLine);
            if (counter % 5 == 3)                          //This indicates the program is reading the birth month of the element.
                node->birthMonth = atoi(readLine);
            if (counter % 5 == 4) {                        //This indicates the program is reading the birth year of the element.
                node->birthYear = atoi(readLine);

                if(input==2)
                    push(node,stack);
                if(input==8)
                    enqueue(node,queue);//Whenever the five properties are read and stored, we simply add
                node = (struct Node *) malloc(sizeof(struct Node)); //this node to the linked list and create a new node to continue.
            }
            counter++;
        }
        fclose(fp);                                        //File needs to be closed after finishing above operations..
    }

}



void pushElement(struct Stack *stack)
{

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));  //Allocate memory for a node to store five properties.
    printf("Please input the first name: \n");
    scanf("%s",node->firstName);
    printf("Please input the last name: \n");
    scanf("%s",node->lastName);
    printf("Please input the birth day: \n");
    scanf("%d",&node->birthDay);
    printf("Please input the birth month: \n");
    scanf("%d",&node->birthMonth);
    printf("Please input the birth year: \n");
    scanf("%d",&node->birthYear);
    push(node,stack);
    printNumberOfElementsInStack(stack);

}

void popElement(struct Stack *stack)
{

    pop(stack);
    //printf("After pop... ");
    //printNumberOfElementsInStack(stack);
}


void peekStack(struct Stack *stack)
{
    struct Node* peekNode=topElementInStack(stack);
    if(peekNode!=NULL)
    {
        printf("The peek element is: \n\n");
        printElementInStack(peekNode);
        printNumberOfElementsInStack(stack);
    }
    //return;
}

void destroyStack(struct Stack *stack)
{
    destroyS(stack);
}

void enqueueElement(struct Queue *queue)
{

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));  //Allocate memory for a node to store five properties.
    printf("Please input the first name: \n");
    scanf("%s",node->firstName);
    printf("Please input the last name: \n");
    scanf("%s",node->lastName);
    printf("Please input the birth day: \n");
    scanf("%d",&node->birthDay);
    printf("Please input the birth month: \n");
    scanf("%d",&node->birthMonth);
    printf("Please input the birth year: \n");
    scanf("%d",&node->birthYear);
    enqueue(node,queue);
    printNumberOfElementsInQueue(queue);

}

void dequeueElement(struct Queue *queue)
{
    dequeue(queue);
    //printNumberOfElementsInQueue(queue);
}


void peekQueue(struct Queue *queue)
{
    struct Node* peekNode=firstElementInQueue(queue);
    if(peekNode!=NULL)
    {
        printf("The peek element is: \n\n");
        printElementInQueue(peekNode);
        printNumberOfElementsInQueue(queue);
    }
    return;

}

void destroyQueue(struct Queue *queue)
{
    destroyQ(queue);
    //printNumberOfElementsInQueue();

}

void testHarness()
{
    char input[4];
    while (1)      //The user can select any of below 9 options to append, delete and print element in the list. The user
        //can always continue until he/she input 'X' or 'x' to exit the program.
    {
        printf("Test Harness Operations: \n");
        printf("Stack: \n");
        printf("1. Create an empty stack\n");
        printf("2. Create a stack from a file\n");
        printf("3. Push an element on the stack\n");
        printf("4. Pop an element from the stack \n");
        printf("5. Peek the stack \n");
        printf("6. Destroy stack \n\n");
        printf("Queue: \n");
        printf("7. Create an empty queue \n");
        printf("8. Create a queue from a file\n");
        printf("9. Enqueue an element\n");
        printf("10. Dequeue an element from the queue\n");
        printf("11. Peek the queue\n");
        printf("12. Destroy queue\n");
        printf("X. Exit \n");
        scanf("%s",input);
        if(strcmp(input,"X")==0 || strcmp(input,"x")==0 )   //The function exit.
            break;

        else if(strcmp(input,"1")==0)         //When the user enters 1, the program calls createEmptyList() function to create
        {                                //an empty list.
            stack=createEmptyStack(stack);
            //stack=createEmptyS();
        }
        else if(strcmp(input,"2")==0)         //When the user enters 2, the program calls createListFromFile() function to read
        {                                //the file line by line and create a linked list for the file.
            createStackOrQueueFromFile(2);
        }

        else if(strcmp(input,"3")==0)         //When the use enters 3, the program calls appendElementToList() function to append
        {
            if(stack==NULL)
                printf("\n You haven't created a stack yet, please create a stack first.\n\n");
            else//a new element to the existing linked list. The new element information needs to be
            pushElement(stack);       //provided by the user input.
        }
        else if(strcmp(input,"4")==0)        //When the user enters 4, the program calls printContentsOfList() function to print
        {
            if(stack==NULL)
                printf("\n You haven't created a stack yet, please create a stack first.\n\n");
            else//each element of the list.
            popElement(stack);
        }
        else if(strcmp(input,"5")==0)        //When the user enters 5, the program calls deleteElementByIndex() function to delete
        {
            if(stack==NULL)
                printf("\n You haven't created a stack yet, please create a stack first.\n\n");
            else//an element with a index provided by the user input.
            peekStack(stack);
        }
        else if(strcmp(input,"6")==0)        //When the user enters 6, the program calls deleteElementByLastName() function to
        {
            if(stack==NULL)
                printf("\n You haven't created a stack yet, please create a stack first.\n\n");
            else//delete the first element with a last name provided by the user input.
            destroyStack(stack);
        }
        else if(strcmp(input,"7")==0)        //When the user enters 7, the program calls deleteAllElementsByLastName() function
        {                               //to delete all found elements with a last name provided by the user input.
            queue=createEmptyQueue(queue);
            //queue=createEmptyQ();
        }
        else if(strcmp(input,"8")==0)        //When the user enters 8, the program calls printNumberOfElements() function to
        {                               //print the total number of all elements in the list.
            createStackOrQueueFromFile(8);
        }
        else if(strcmp(input,"9")==0)        //When the user enters 8, the program calls printNumberOfElements() function to
        {
            if(queue==NULL)
                printf("\n You haven't created a queue yet, please create a queue first.\n\n");
            else
            //print the total number of all elements in the list.
            enqueueElement(queue);
        }
        else if(strcmp(input,"10")==0)        //When the user enters 8, the program calls printNumberOfElements() function to
        {
            if(queue==NULL)
                printf("\n You haven't created a queue yet, please create a queue first.\n\n");
            else
                //print the total number of all elements in the list.
            dequeueElement(queue);
        }
        else if(strcmp(input,"11")==0)        //When the user enters 8, the program calls printNumberOfElements() function to
        {
            if(queue==NULL)
                printf("\n You haven't created a queue yet, please create a queue first.\n\n");
            else
                //print the total number of all elements in the list.
            peekQueue(queue);
        }
        else if(strcmp(input,"12")==0)        //When the user enters 8, the program calls printNumberOfElements() function to
        {
            if(queue==NULL)
                printf("\n You haven't created a queue yet, please create a queue first.\n\n");
            else
                //print the total number of all elements in the list.
            destroyQueue(queue);
        }
        else
        {
            printf("\n Invalid input. Please try it again.\n\n");
        }
    }

}
int main()
{
    testHarness();
}