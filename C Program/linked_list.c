#include <stdio.h>
#include <conio.h>

#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
} *start = NULL;

void append()
{
    int x;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n\tnode you want to enter \n");
    scanf("%d", &x);
    temp->info = x;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *ptr;
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    printf("\n node is added\n");
}
void display()
{
    struct node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("empty!!!!!!!!!!!!!\n");
        append();
        return;
    }
    else
        printf("linked list is :\n");
    while (ptr->next != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
    printf("%d\t", ptr->info);
}
void insert_beg()
{
    struct node *ptr;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (start == NULL)
    {
        printf("\nplease create a node\n");
    }
    else
    {
        printf("Enter value\n");
        scanf("%d", &val);
        ptr->info = val;
        ptr->next = start;
        start = ptr;
        printf("Node inserted\n");
    }
}

void insert_after()
{
    int num, value;
    struct node *temp;
    printf("Enter the vlue you want to add in list\n");
    scanf("%d", &num);
    printf("Enter the element in list  after which you want to add number\n");
    scanf("%d", &value);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = num;
    if (start == NULL)
    {
        printf("Empty list !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n ");
    }
    else
    {
        struct node *ptr;
        ptr = start;
        while (ptr->info != value)
        {
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        ptr->next = temp;
    }
    printf("Node inserted\n");
}

void insert_before()
{
    int num, val;
    struct node *ptr, *temp, *prev;
    printf("\nEnter the value you want to add in list\n");
    scanf("%d", &num);
    printf("\nEnter the element in the list before which you want to add number\n");
    scanf("%d", &val);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = num;
    temp->next = NULL;
    ptr = start;
    if (ptr->next == NULL || ptr->info == val)
    {
        temp->next = start;
        start = temp;
    }
    else

        while (ptr->info != val)
        {
            prev = ptr;
            ptr = ptr->next;
        }
    prev->next = temp;
    temp->next = ptr;
}

void deletion_value()
{
    int val;
    struct node *ptr, *prev;
    ptr = start;
    printf("Enter the value you want to delete in list which must be present in list\n");
    scanf("%d", &val);
    while (ptr->info != val)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    printf("given Value %d has been deleted from the list\n", val);
    free(ptr);
}

int main()
{

    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ");
    printf("\t  \n");
    printf("\t 1. for append\n");
    printf("\t 2. for insert beg\n");
    printf("\t 3. for insert after\n");
    printf("\t 4. for insert before\n");
    printf("\t 5. for display\n");
    printf("\t 6. for deletion a given element\n");
    printf("\t 8. for exit the program\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ");

    while (1)
    {
        printf("\n\t      Choose one option\n");
        int choice, data;

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            append();
            printf("\n appended\n");
            break;
        case 2:

            insert_beg();
            printf("inserted in begning\n");
            break;
        case 3:
            insert_after();
            printf("inserted after the value\n");

            break;
        case 4:
            insert_before();
            printf("inserted before the value\n");
            break;
        case 5:
            printf("element are :\n");
            display();
            break;
        case 6:
            void deletion_value();
            printf("deleted\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Enter invalid choice\n");
        }
    }
    return 0;
}