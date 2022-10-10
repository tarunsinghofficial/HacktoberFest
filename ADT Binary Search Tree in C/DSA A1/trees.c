#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suppl.h"

void init(Node **root)
{
    root = NULL;
    return;
}

void insert(Node **tree, int val, char s[])
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->mis = val;
        int i = 0;
        // while (s[i] != '\0')
        // {
        //     temp->name[i] = s[i];
        //     i++;
        // }
        strcpy(temp->name, s);
        *tree = temp;
        return;
    }
    if ((*tree)->mis == val)
    {
        return;
    }
    else if (val < (*tree)->mis)
    {
        insert(&(*tree)->left, val, s);
    }
    else if (val > (*tree)->mis)
    {
        insert(&(*tree)->right, val, s);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d\t", root->mis);
        printf("%s\n", root->name);
        inorder(root->right);
    }
}
Node *search(Node *root, int val)
{
    if (root == NULL || root->mis == val)
    {
        return root;
    }
    if (val > root->mis)
    {
        search(root->right, val);
    }
    else if (val < root->mis)
    {
        search(root->left, val);
    }
}
Node *minValue(Node *root)
{
    Node *ptr = root;
    while (ptr && ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

Node *deleteNode(Node *root, int d)
{
    Node *res = search(root, d);
    if (res)
    {
        // Case 1: Empty tree
        if (root == NULL)
        {
            return root;
        }
        if (root->mis > d)
        {
            root->left = deleteNode(root->left, d);
        }
        else if (root->mis < d)
        {
            root->right = deleteNode(root->right, d);
        }
        else
        {
            // Node has only 1 or 0 children
            if (root->left == NULL)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                Node *temp = minValue(root->right);
                root->mis = temp->mis;
                root->right = deleteNode(root->right, temp->mis);
            }
        }
        return root;
    }
    else
    {
        printf("Not Found\n");
    }
}
void _deleteTree(Node *Node)
{
    if (Node == NULL)
        return;
    _deleteTree(Node->left);
    _deleteTree(Node->right);
    printf("Deleting Node: %d\n", Node->mis);
    free(Node);
}
void destroyTree(Node **Node_ref)
{
    _deleteTree(*Node_ref);
    *Node_ref = NULL;
}

// postorder
void postorder(struct Node *root)
{
    Node *curr = root;
    Node *prev = NULL;
    while (curr != NULL || !isStackEmpty())
    {
        if (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        else
        {
            curr = peek();
            if (curr->right == NULL || curr->right == prev)
            {
                printf("%d\t%s\n", curr->mis, curr->name);
                pop();
                prev = curr;
                curr = NULL;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
}

void level(Node *root, int lev)
{
    if (root == NULL)
    {
        return;
    }
    if (lev == 0)
    {
        enQueue(root);
        printf("%d\t%s\n", root->mis, root->name);
        return;
    }
    else if (lev > 0)
    {
        level(root->left, lev - 1);
        level(root->right, lev - 1);
    }
}
