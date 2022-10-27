#include<stdio.h>
#include<stdlib.h>

struct Node { 
    int data;
    struct Node *next;
    struct Node *prev;
};
void insertStart(struct Node** head, int data){
    
    // creating memory for newNode
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // assigning newNode's next as the current head 
    // Assign data & and make newNode's prev as NULL
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    
    // if list already had item(s)
    // We need to make current head previous node as this new node
    if(*head != NULL)
        (*head)->prev = newNode;
    
    // change head to this newNode
    *head = newNode;
    
}
void display(struct Node* node)
{
    struct Node* end;
    printf("\nIn Forward Direction\n");
    while (node != NULL) {
        printf(" %d ", node->data);
        end = node;
        node = node->next;
    }
 
    printf("\nIn Backward direction \n");
    while (end != NULL) {
        printf(" %d ", end->data);
        end = end->prev;
    }
}
int main()
{
    struct Node* head = NULL;
    
    // Need '&' i.e. address as we need to change head
    insertStart(&head,1);
    insertStart(&head,2);
    insertStart(&head,3);
    
    // no need for '&' as head need not be changed
    // only doing traversal
    display(head);
    
    return 0;
}