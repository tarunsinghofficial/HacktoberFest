#include<stdio.h>
#include<stdlib.h>
#include "trees.h"

typedef struct stack
{
    Node *data;
    struct stack *next;
} stack;

void push(Node *d);
int isStackEmpty();
void *pop();
Node *peek();

typedef struct Queue
{
    Node *data;
    struct Queue *next;
} Queue;

void enQueue(Node *d);