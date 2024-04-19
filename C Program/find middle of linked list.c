## C program to find middle of linked list
-------------------------------------------
#include<stdio.h>
#include<stdlib.h>
 
// Link list node
struct Node
{
    int data;
    struct Node* next;
};
 
// Function to get the middle of
// the linked list
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL &&
               fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]",
                slow_ptr->data);
    }
}
 
void push(struct Node** head_ref,
          int new_data)
{
    // Allocate node
    struct Node* new_node =
           (struct Node*) malloc(sizeof(struct Node));
 
    // Put in the data
    new_node->data = new_data;
 
    // Link the old list off the new node
    new_node->next = (*head_ref);
 
    // Move the head to point to the new node
    (*head_ref) = new_node;
}
 
// A utility function to print a given
//  linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
 
// Driver code
int main()
{
    // Start with the empty list
    struct Node* head = NULL;
    int i;
 
    for (i = 5; i > 0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }
    return 0;
}
Output:

5->NULL
The middle element is [5]
