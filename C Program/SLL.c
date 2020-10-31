#include <stdio.h>
#include <stdlib.h>

// defining structure of a node
struct node{
    int data;
    struct node *next;
};



//function to print element of linked list
void display(struct node *head)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr = head;
    if(ptr == NULL)
        printf("\n SLL is empty!");

    else {
        while (ptr != NULL) {
            printf("  %d ", ptr->data);
            if (ptr->next != NULL) {
                printf("->");
            }
            ptr = ptr->next;
        }
    }

}



//function to insert element at the end of linked list
struct node *insert_End(struct node *head, int ele)
{
    struct node *new_node, *ptr;

    new_node=(struct node *)malloc(sizeof(struct node));

    new_node->data= ele;
    new_node->next= NULL;

    ptr=head;

    if(ptr == NULL) {
        ptr=new_node;
        head=ptr;
    }
    else {

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    return head;

}



// function to delete element from the end of SLL
struct node *delete_End(struct node *head) {
    struct node *ptr, *temp;
    ptr=head;
    temp=head;

    if(head == NULL){
        printf("SLL is empty!");
        return head;
    }
    else if(head->next == NULL) {
        head = NULL;
        return head;
    }
    else{
        while(ptr->next != NULL){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);

        return head;
    }

}



// main function
int main() {
    struct node *head;
    head = NULL;

    int choice, ele;
    do {
        printf("\n\n ****----- MENU -----****");
        printf("\n 1. INSERT (at End)");
        printf("\n 2. DELETE (from End)");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT\n");
        printf("\n\n Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n Enter the number to Insert at the end of SLL :");
                scanf("%d", &ele);
                head = insert_End(head, ele);
                printf("\n Insertion done !");
                break;

            case 2:
                head = delete_End(head);
                printf("\n Deletion done !");
                break;

            case 3:
                printf("\n Elements of SLL are : \n");
                display(head);
                break;

            case 4:
                exit(0);

        }

    } while( choice != 4);

    return 0;

}
