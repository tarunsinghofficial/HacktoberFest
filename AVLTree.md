# include<stdio.h>

# include<stdlib.h>

struct Node { int key; struct Node *left; struct Node *right; int height; }; int max(int a, int b); int height(struct
Node *N)
{ if (N == NULL)
return 0; return N->height; } int max(int a, int b)
{ return (a > b)? a : b; } struct Node* createNode(int value)
{ struct Node* node = malloc(sizeof(struct Node)); node->key = value; node->left = NULL; node->right = NULL; return
node; }

struct Node* newNode(int key)
{ struct Node* node = (struct Node*) malloc(sizeof(struct Node)); node->key = key; node->left = NULL; node->right =
NULL; node->height = 1; return(node); } struct Node *rightRotate(struct Node *y)
{ struct Node *x = y->left; struct Node *T2 = x->right; x->right = y; y->left = T2; y->height = max(height(y->left),
height(y->right))+1; x->height = max(height(x->left), height(x->right))+1; return x; } struct Node *leftRotate(struct
Node *x)
{ struct Node *y = x->right; struct Node *T2 = y->left; y->left = x; x->right = T2; x->height = max(height(x->left),
height(x->right))+1; y->height = max(height(y->left), height(y->right))+1; return y; } int getBalanceFactor(struct
Node *N)
{ if (N == NULL)

return 0; return height(N->left) - height(N->right); } struct Node* insertNode(struct Node* node, int key)
{ if (node == NULL)
return(newNode(key)); if (key < node->key)
node->left = insertNode(node->left, key); else if (key > node->key)
node->right = insertNode(node->right, key); else return node; node->height = 1 + max(height(node->left), height(node->
right)); int balanceFactor = getBalanceFactor(node); if (balanceFactor > 1)
{ if (key < node->left->key)
{ return rightRotate(node); } else if (key > node->left->key)
{ node->left = leftRotate(node->left); return rightRotate(node); } } if (balanceFactor < -1)
{ if (key > node->right->key)
{ return leftRotate(node); }

else if (key < node->right->key)
{ node->right = rightRotate(node->right); return leftRotate(node); } } return node; } struct Node * minValueNode(struct
Node* node)
{ struct Node* current = node; while (current->left != NULL)
current = current->left; return current; } struct Node* deleteNode(struct Node* root, int key)
{ if (root == NULL)
return root; if ( key < root->key )
root->left = deleteNode(root->left, key); else if( key > root->key )
root->right = deleteNode(root->right, key); else { if( (root->left == NULL) || (root->right == NULL) )
{ struct Node *temp = root->left ? root->left :
root->right; if (temp == NULL)
{ temp = root;

root = NULL; } else
*root = *temp; free(temp); } else { struct Node* temp = minValueNode(root->right); root->key = temp->key; root->right =
deleteNode(root->right, temp->key); } } if (root == NULL)
return root; root->height = 1 + max(height(root->left), height(root->right)); int balanceFactor = getBalanceFactor(root)
; if (balanceFactor > 1)
{ if (getBalanceFactor(root->left) >= 0)
{ return rightRotate(root); } else { root->left = leftRotate(root->left); return rightRotate(root); } } if (
balanceFactor < -1)
{ if (getBalanceFactor(root->right) <= 0)

{ return leftRotate(root); } else { root->right = rightRotate(root->right); return leftRotate(root); } } return root; }
void Preorder(struct Node *root)
{ if(root != NULL)
{ printf("%d ", root->key); Preorder(root->left); Preorder(root->right); } } int main()
{ struct Node *root = NULL; int option,val; while (1)
{ printf("\n***********MAIN MENU************\n"); printf("1. create \t 2. insert \n3. delete \t 4.Display preorder\n5.
exit \n"); printf("option : "); scanf("%d",&option); switch(option)
{ case 1:printf("enter the value : "); scanf("%d",&val); root = createNode(val); break;

case 2:printf("\nenter the value of new node:"); scanf("%d",&val); root = insertNode(root,val); break; case 3:printf("\n
enter data to delete : "); scanf("%d",&val); root = deleteNode(root,val); break; case 4:Preorder(root); break; case 5:
exit(0); break; } } return 0; }
