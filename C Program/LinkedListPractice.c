// #include <stdio.h>
// #include <stdlib.h>

// struct node 
// {
//     int num;                        //Data of the node
//     struct node *nextptr;           //Address of the next node
// }*stnode;

// void createNodeList(int n); // function to create the list
// void displayList();         // function to display the list

// int main()
// {
//     int n;
// 		printf("\n\n Linked List : To create and display Singly Linked List :\n");
// 		printf("-------------------------------------------------------------\n");
		
//     printf(" Input the number of nodes : ");
//     scanf("%d", &n);
//     createNodeList(n);
//     printf("\n Data entered in the list : \n");
//     displayList();
//     return 0;
// }
// void createNodeList(int n)
// {
//     struct node *fnNode, *tmp;
//     int num, i;
//     stnode = (struct node *)malloc(sizeof(struct node));

//     if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
//     {
//         printf(" Memory can not be allocated.");
//     }
//     else
//     {
// // reads data for the node through keyboard

//         printf(" Input data for node 1 : ");
//         scanf("%d", &num);
//         stnode->num = num;      
//         stnode->nextptr = NULL; // links the address field to NULL
//         tmp = stnode;
// // Creating n nodes and adding to linked list
//         for(i=2; i<=n; i++)
//         {
//             fnNode = (struct node *)malloc(sizeof(struct node));
//             if(fnNode == NULL)
//             {
//                 printf(" Memory can not be allocated.");
//                 break;
//             }
//             else
//             {
//                 printf(" Input data for node %d : ", i);
//                 scanf(" %d", &num);
 
//                 fnNode->num = num;      // links the num field of fnNode with num
//                 fnNode->nextptr = NULL; // links the address field of fnNode with NULL
 
//                 tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
//                 tmp = tmp->nextptr; 
//             }
//         }
//     }
// }
// void displayList()
// {
//     struct node *tmp;
//     if(stnode == NULL)
//     {
//         printf(" List is empty.");
//     }
//     else
//     {
//         tmp = stnode;
//         while(tmp != NULL)
//         {
//             printf(" Data = %d\n", tmp->num);       // prints the data of current node
//             tmp = tmp->nextptr;                     // advances the position of current node
//         }
//     }
// } 



// 1st


// #include <stdio.h>
// #include <stdlib.h>

// struct node 
// {
//     int num;
//     struct node *nextptr;
// }*stnode;

// void createNodeList(int n); 
// void displayList();

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     createNodeList(n);
//     displayList();
//     return 0;
// }
// void createNodeList(int n)
// {
//     struct node *fnNode, *tmp;
//     int num, i;
//     stnode = (struct node *)malloc(sizeof(struct node));

//     if(stnode == NULL)
//     {
//         printf(" Memory can not be allocated.");
//     }
//     else
//     {
//         scanf("%d", &num);
//         stnode->num = num;      
//         stnode->nextptr = NULL;
//         tmp = stnode;
//         for(i=2; i<=n; i++)
//         {
//             fnNode = (struct node *)malloc(sizeof(struct node));
//             if(fnNode == NULL)
//             {
//                 printf(" Memory can not be allocated.");
//                 break;
//             }
//             else
//             {
//                 scanf(" %d", &num);
 
//                 fnNode->num = num;      
//                 fnNode->nextptr = NULL; 
 
//                 tmp->nextptr = fnNode;
//                 tmp = tmp->nextptr; 
//             }
//         }
//     }
// }
// void displayList()
// {

//     struct node *tmp;
//     if(stnode == NULL)
//     {
//         printf(" List is empty.");
//     }
//     else
//     {
//         tmp = stnode;
//         while(tmp != NULL)
//         {
//             printf("%d\n", tmp->num);
//             tmp = tmp->nextptr;
//         }
//     }
// } 


// 2nd REVERSED LINKED LIST


// #include <stdio.h>
// #include <stdlib.h>

// struct node 
// {
//     int num;
//     struct node *nextptr;
// }*stnode;

// void createNodeList(int n); 
// void displayList();
// void reverseDispList();

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     createNodeList(n);
//     reverseDispList();
//     printf("\n");
//     displayList();
//     printf("\n");
//     return 0;
// }
// void createNodeList(int n)
// {
//     struct node *fnNode, *tmp;
//     int num, i;
//     stnode = (struct node *)malloc(sizeof(struct node));

//     if(stnode == NULL)
//     {
//         printf(" Memory can not be allocated.");
//     }
//     else
//     {
//         scanf("%d", &num);
//         stnode->num = num;      
//         stnode->nextptr = NULL;
//         tmp = stnode;
//         for(i=2; i<=n; i++)
//         {
//             fnNode = (struct node *)malloc(sizeof(struct node));
//             if(fnNode == NULL)
//             {
//                 printf(" Memory can not be allocated.");
//                 break;
//             }
//             else
//             {
//                 scanf("%d", &num);
 
//                 fnNode->num = num;      
//                 fnNode->nextptr = NULL; 
 
//                 tmp->nextptr = fnNode;
//                 tmp = tmp->nextptr; 
//             }
//         }
//     }
// }


// void reverseDispList()
// {
//     struct node *prevNode, *curNode;
 
//     if(stnode != NULL)
//     {
//         prevNode = stnode;
//         curNode = stnode->nextptr;
//         stnode = stnode->nextptr;
 
//         prevNode->nextptr = NULL; //convert the first node as last
 
//         while(stnode != NULL)
//         {
//             stnode = stnode->nextptr;
//             curNode->nextptr = prevNode;
 
//             prevNode = curNode;
//             curNode = stnode;
//         }
//         stnode = prevNode; //convert the last node as head
//     }
// }

// void displayList()
// {

//     struct node *tmp;
//     if(stnode == NULL)
//     {
//         printf(" List is empty.");
//     }
//     else
//     {
//         tmp = stnode;
//         while(tmp != NULL)
//         {
//             printf("%d----->", tmp->num);
//             tmp = tmp->nextptr;
//         }
//     }
// } 



// 3rd PRINTING AND COUNTING THE NUMBER OF NODES


// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//     int data;
//     struct Node*next;
// }*s;

// void CreateLinkedList(int n)
// {
//     struct Node *fnNode,*tmp;
//     int num,i;

//     s = (struct Node*)malloc(sizeof(struct Node));

//     if(s == NULL)
//     {
//         printf(" Memory can not be allocated.");
//     }
//     else
//     {
//         printf("Enter the data for 1 node : ");
//         scanf("%d",&num);
//         s->data=num;
//         s->next=NULL;
//         tmp=s;

//         for ( i = 2; i <=n; i++)
//         {
//             fnNode=(struct Node*)malloc(sizeof(struct Node));
//             if (fnNode==NULL)
//             {
//                 break;
//             }
//             else
//             {
//                 printf("Enter the data for %d node : ",i);
//                 scanf("%d",&num);

//                 fnNode->data=num;
//                 fnNode->next=NULL;

//                 tmp->next=fnNode;
//                 tmp=tmp->next;
//             }
            
//         }
        
//     }
    
// }

// void display()
// {
//     struct Node*tmp;
//     if (s==NULL)
//     {
//         printf("List is empty");
//     }
//     else
//     {
//         int count=0;
//         tmp=s;
//         while (tmp!=NULL)
//         {
//             printf("%d---->",tmp->data);
//             tmp=tmp->next;
//         }
        
//     }
      
// }

// int NodeCount()
// {
//     int count=0;
//     struct Node*ptr;
//     ptr=s;
//     while (ptr!=NULL)
//     {
//         count++;
//         ptr=ptr->next;
//     }
//     return count;
// }
 
// int main()
// {
//     int n;
//     int count=0;
//     CreateLinkedList(5);
//     printf("The linked list is\n");
//     display();
//     n=NodeCount();
//     printf("\nThe number of nodes are %d",n);
 
// return 0;
// }



// 4th INSERTING ELEMENT AT FIRST



#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*sn;

void CreateList(int n)
{
    struct Node*fnNode,*ptr;
    int num,i;
    sn=(struct Node*)malloc(sizeof(struct Node));

    if (sn==NULL)
    {
        printf("Memory cannot be allocated\n");
    }
    else
    {
        printf("Enter the data for 1 node : ");
        scanf("%d",&num);

        for ( i = 2; i <=n; i++)
        {

            if (fnNode==NULL)
            {
                break;
            }
            else
            {
            
            printf("Enter the data for %d node : ",i);
            scanf("%d",&num);

            fnNode->data=num;
            fnNode->next=NULL;

            ptr->next=fnNode;
            ptr=ptr->next;

            }

        }
        
    }
    
}

void displayList()
{
    struct Node*ptr;

    if (sn==NULL)
    {
        printf("List not found");
    }
    else
    {
        ptr=sn;
        while (sn!=NULL)
        {
            printf("%d----->",ptr->data);
            ptr=ptr->next;
        }

    }
    
}
 
int main()
{
    int n;
    // printf("Enter the number of elements of the linked list\n");
    // scanf("%d",&n);
    // printf("\n");
    CreateList(5);
    printf("The linked list is\n");
    displayList();
 
return 0;
}