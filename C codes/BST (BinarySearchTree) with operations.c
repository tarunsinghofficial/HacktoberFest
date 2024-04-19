#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
}Node;

// Create a node
Node *createNode(int item)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert a node
Node *insert(Node *node, int key)
{
    //Create and return a new node if the tree is empty
    if (node == NULL)
    {
        return createNode(key);
    }

    // Traverse to left if item less than current node
    if(key < node->data)
    {
        node->left = insert(node->left, key);
    }

    //Traverse to the right if item greater than current
    else
    {
        node->right = insert(node->right, key);
    }

    return node;
}

// Inorder Traversal
void inorder(Node *root)
{
  if (root != NULL)
  {
    //Left child
    inorder(root->left);

    //Printing root
    printf("%d\t", root->data);

    //Right child
    inorder(root->right);
  }
}

//Preorder Traversal
void preorder(Node *root)
{
  if (root != NULL)
  {
    //Printing root
    printf("%d\t", root->data);

    //Left child
    preorder(root->left);

    //Right child
    preorder(root->right);
  }
}

//Preorder Traversal
void postorder(Node *root)
{
  if (root != NULL)
  {
    //Left child
    postorder(root->left);

    //Right child
    postorder(root->right);

    //Printing root
    printf("%d\t", root->data);
  }
}

//Searching and counting the number of comparisons
int search(Node *root, int item, int *count)
{
    //If the tree is empty or item not found
    if(root == NULL)
    {
        return 0;
    }

    else
    {
        //If item found
        if(item == root->data)
        {
            *count = *count + 1;
            return 1;
        }

        //If item less than current node
        else if(item < root->data)
        {
            *count = *count + 1;
            return search(root->left, item, count);
        }

        //If item greater than current node
        else
        {
            *count = *count + 1;
            return search(root->right, item, count);
        }
    }

    return 0;
}

// Find the inorder successor
Node *minValueNode(Node *root)
{
    Node *current = root;

    // Find the leftmost leaf
    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Deleting a node
Node *deleteNode(Node *root, int key)
{
    //Can't delete if tree is empty
    if (root == NULL)
    {
        printf("\nTree is empty or element not found");
        return root;
    }

    // Find the node to be deleted
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    //Deleteing
    else
    {
        // If the node is with only one child or no child
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

        //If the node has two children
        //We need to find the inorder successor
        Node *temp = minValueNode(root->right);

        //Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        //Deleting the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Driver code
int main()
{
    int flag = 0, count = 0, n, x;
    struct node *root = NULL;

    printf("\nStart\n");

    while(flag != 5)
    {
        printf("\n1. Insert an element");
        printf("\n2. Search for an element with number of comparison");
        printf("\n3. Delete an element");
        printf("\n4. Traversal");
        printf("\n5. Exit\n\n");

        scanf("%d", &flag);

        if(flag > 5 || flag < 1)
        {
            printf("\nWrong Input\n");
        }

        else
        {
            switch(flag)
            {
                case 1:

                printf("\nEnter the elements you want to insert: (-1 to exit)\n");
                while(n++)
                {
                    scanf("%d", &x);
                    if(x == -1){
                        break;
                    }
                    root = insert(root, x);
                }

                break;

                case 2:
                printf("\nEnter the element you want to search : ");
                scanf("%d", &x);

                count = 0;
                n = search(root, x, &count);

                if(n != 0)
                {
                    printf("\nElement %d found with %d comparisons\n", x, count);
                }

                else
                {
                    printf("\nElement not present in the list!!!!");
                }

                break;

                case 3:
                printf("\nEnter the element you want to delete : ");
                scanf("%d", &x);

                deleteNode(root, x);

                printf("\nTfter deleting inorder :\n");
                inorder(root);

                break;

                case 4:
                printf("\nInorder Traversal: \n");
                inorder(root);

                printf("\nPreorder Traversal:\n");
                preorder(root);

                printf("\nPostorder Traversal:\n");
                postorder(root);

                break;

                case 5:
                printf("\nTHANK YOU\n\n");
            }
        }
    }

    return 0;
}
