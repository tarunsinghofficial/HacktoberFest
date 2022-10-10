#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trees.h"

int main()
{
    int oper;
    Node *root = NULL;
    int insertVal;
    int delVal;
    int searchVal;
    int ilevel;
    char name[500];
    printf("\n0:For quitting\n1.Initializing BST\n2.Inserting in a BST\n3.Removing a node from BST\n4.Searching a Node\n5.Post-Order Traversal\n6.Displaying Node at ith level\n7.Destroy BST\n");
    printf("Enter the operation you want to perform\n");
    scanf("%d", &oper);
    while (oper)
    {
        switch (oper)
        {
        case 1:
            init(&root);
            break;
        case 2:
        {
            printf("Enter the mis you want to insert in BST: ");
            scanf("%d", &insertVal);
            printf("\n");
            printf("Enter Name: ");
            scanf("%s", name);
            insert(&root, insertVal, name);
            break;
        }
        case 3:
        {
            printf("Enter mis of the node you want to delete\n");
            scanf("%d", &delVal);
            deleteNode(root, delVal);
            break;
        }
        case 4:
        {
            printf("Enter mis of the node you want to search\n");
            scanf("%d", &searchVal);
            if (search(root, searchVal))
            {
                printf("Found!\n");
            }
            else
            {
                printf("Not Found!\n");
            }
            break;
        }
        case 5:
            printf("Post-Order Traversal\n");
            printf("[ \n");
            postorder(root);
            printf("]");
            printf("\n");
            break;
        case 6:
            printf("Enter the level of nodes\n");
            scanf("%d", &ilevel);
            level(root, ilevel);
            break;
        case 7:
            printf("Destroying BST\n");
            destroyTree(&root);
            break;
        default:
            printf("Invalid Operation Entered\n");
            break;
        }
        printf("Enter the operation you want to perform\n");
        scanf("%d", &oper);
    }
    //[5,3,6,2,4,7]
    // init(&root);
    // printf("Inserting...\n");
    // insert(&root, 5, "Justin");
    // insert(&root, 3, "Minouli");
    // insert(&root, 6, "Jess");
    // insert(&root, 2, "Mel");
    // insert(&root, 4, "Jock");
    // insert(&root, 7, "Andy");
    // printf("Inorder Traversal...\n");
    // inorder(root);
    // Node *res = search(root, 10);
    // if (res)
    // {
    //     printf("Found\n");
    // }
    // else
    // {
    //     printf("Not Found\n");
    // }
    // Node *res2 = deleteNode(root, 100);
    // printf("Inorder Traversal...\n");
    // inorder(root);
    // printf("Postorder Traversal...\n");
    // postorder(root);
    // printf("Level Order Traversal...\n");
    // level(root, 2);
    // destroyTree(&root);
    // insert(&root, 5, "Justin");
    // insert(&root, 3, "Minouli");
    // printf("Inorder Traversal...\n");
    // inorder(root);
    return 0;
}
