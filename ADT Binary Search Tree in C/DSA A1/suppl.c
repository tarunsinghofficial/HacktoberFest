#include <stdio.h>
#include <stdlib.h>
#include "suppl.h"

stack *top = NULL;
// stack operations

void push(Node *d)
{
    stack *temp;
    temp = malloc(sizeof(stack));
    temp->data = d;
    temp->next = top;
    top = temp;
    return;
}
int isStackEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void *pop()
{
    stack *temp;
    Node *val;
    if (isStackEmpty())
    {
        printf("Stack Underflow");
        return 0;
    }
    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);
    temp = NULL;
    // return val;
}

Node *peek()
{
    return top->data;
}


Queue *front = NULL;
Queue *rear = NULL;

// Queue operations
void enQueue(Node *d)
{
    Queue *temp;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->data = d;
    temp->next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = temp;
        return;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        return;
    }
}