// menu driven program for single linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head, *new_node, *ptr, *temp;
int count = 0;
void create(int n)
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->next = NULL;
}

void display()
{

    if (head == NULL)
    {
        printf("The list is empty\n");
    }

    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("->%d", temp->data);
            temp = temp->next;
        }
    }
}

int length()
{

    count=0;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void empty()
{
    if (head == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else

    {
        printf("\nDisplaying list......\n");
        display();
    }
}

void insert_at_beg()
{
    if (head == NULL)
    {
        head = new_node;
        temp = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insert_at_end()
{
    if (head == NULL)
    {
        head = new_node;
        temp = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
}

void insert_at_pos(int pos)
{
    if (head == NULL)
    {
        head = new_node;
        temp = new_node;
    }
    else
    {
        int i = 0;
        temp = head;
        while (i < pos - 2)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_beg()
{
    temp = head;
    if (head == NULL)
        printf("The list is empty");
    else
    {
        head = head->next;
        free(temp);
    }
}

void delete_end()
{
    temp = head;
    ptr = head;
    if (head == NULL)
        printf("The list is empty");
    else
    {
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            ptr->next = NULL;
            free(temp);
        }
    }
}

void delete_pos(int pos)
{
    int i = 0;
    temp = head;
    while (i < pos - 1)
    {
        ptr = temp;
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    free(temp);
}
int search(int n)
{
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        if (n == temp->data)
        {
            return i;
        }
        temp = temp->next;
    }
    return 0;
}

void delete_key(int n)
{
    int no = length();
    struct node *temp1 = temp;
    int pos = search(n);
    int i = 0;
    temp = head;
    if (pos == 1)
    {
        head = head->next;
        free(temp);
    }
    else if (pos == no)
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
    }
    else
    {
        while (i < pos - 2)
        {
            temp = temp->next;
            i++;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
    }
}

int main()
{
    head = NULL;
    int choice;
    system("cls");

    do
    {
        printf("\n\tLINKED LIST\n");
        printf("1.Traversal of the list\n");
        printf("2.Check if the list is empty\n");
        printf("3.Insert a node at a certain position(beg/end/any pos)\n");
        printf("4.Delete node at a certain position(beg/end/any pos)\n");
        printf("5.Delete a node for a given key\n");
        printf("6.Count the total no of nodes\n");
        printf("7.Search for an element in the linked list\n");
        printf("8.Exit\n");
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nDisplaying list.....\n");
            display();
            break;
        case 2:
            empty();
            break;
        case 3:
            printf("\n1.Insert node at beg");
            printf("\n2.Insert node at the end");
            printf("\n3.Insert node at any position");
            printf("\n4.Exit");
            int ch, n, pos;

            do
            {
                printf("\nEnter choice:");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    printf("\nEnter data to be inserted at the beginning of the node:");
                    scanf("%d", &n);
                    create(n);
                    insert_at_beg();
                    break;
                case 2:
                    printf("\nEnter data to be inserted at the end of the node:");
                    scanf("%d", &n);
                    create(n);
                    insert_at_end();
                    break;
                case 3:
                    printf("\nEnter data to be inserted at any position of the node:");
                    scanf("%d", &n);
                    create(n);
                    printf("\nEnter the position:");
                    scanf("%d", &pos);
                    insert_at_pos(pos);
                    break;
                // default:
                //     printf("Wrong choice!!TRY AGAIN!!");
                //     break;
                }
            } while (ch != 4);
            break;

        case 4:
            printf("\n1.Delete node from beg");
            printf("\n2.Delete node from end");
            printf("\n3.delete node from any position");
            printf("\n4.Exit");
            int ch1, pos1;

            do
            {
                printf("\nEnter choice:");
                scanf("%d", &ch1);
                switch (ch1)
                {
                case 1:
                    printf("\nDeleting node from the beginning.....");
                    delete_beg();
                    break;
                case 2:
                    printf("\nDeleting node from the end.....");
                    delete_end();
                    break;
                case 3:
                    printf("\nEnter the position at which the node is to be deleted");
                    scanf("%d", &pos1);
                    delete_pos(pos1);
                    break;
                // default:
                    // printf("Wrong choice!!TRY AGAIN!!");
                    // break;
                }
            } while (ch1 != 4);
            break;
        case 5:
            printf("Enter key for which the node is to be deleted:");
            int key;
            scanf("%d", &key);
            delete_key(key);
            break;
        case 6:
            printf("No of nodes=");
            int no = length();
            printf("%d", no);
            break;
        case 7:
            printf("Enter the element to be searched for:");
            int ele;
            scanf("%d", &ele);
            int loc = search(ele);
            if (loc == 0)
            {
                printf("node not found");
            }
            else
            {
                printf("node found at position %d", loc);
            }
            break;
        case 8: exit(1);
                break;
        default:
            printf("Wrong choice....please try again!");
        }
    } while (choice != 8);

    return 0;
}