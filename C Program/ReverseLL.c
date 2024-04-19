#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node *reverse (struct Node *head, int k)
{
    if (!head)
      return NULL;

    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;


    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next !=  NULL)
       head->next = reverse(next, k);

    return prev;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

int main(void)
{
    struct Node* head = NULL;

    int n;
    printf("Enter the no. of elements you want to enter\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
      int a;
      printf("\nEnter the data\n");
      scanf("%d", &a);
      push(&head, a);
    }

    int amt;
    printf("\nEnter the amount by which you want to reverse the list\n");
    scanf("%d", &amt);


    printf("\nGiven linked list \n");
    printList(head);
    head = reverse(head, amt);

    printf("\nReversed Linked list \n");
    printList(head);

    return(0);
}
