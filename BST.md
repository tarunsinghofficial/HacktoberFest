# include<stdio.h>

# include<stdlib.h>

# include<conio.h>

struct node { int data; struct node *left; struct node * right; }; int n=1; struct node* createNode(int value)
{ struct node* newNode = malloc(sizeof(struct node)); newNode->data = value; newNode->left = NULL; newNode->right =
NULL; return newNode; } struct node* insert(struct node* root, int data)
{ if (root == NULL) return createNode(data); if (data < root->data)
root->left = insert(root->left, data); else if (data > root->data)
root->right = insert(root->right, data); return root;

} struct node * minValueNode(struct node* node)
{ struct node* current = node; while (current && current->left != NULL)
current = current->left; return current; } struct node* deleteNode(struct node* root, int data)
{ if (root == NULL) return root; if (data < root->data)
root->left = deleteNode(root->left, data); else if (data > root->data)
root->right = deleteNode(root->right, data); else { if (root->left == NULL)
{ struct node *temp = root->right; free(root); return temp; } else if (root->right == NULL)
{ struct node *temp = root->left; free(root); return temp; } struct node* temp = minValueNode(root->right); root->data =
temp->data; root->right = deleteNode(root->right, temp->data); }

return root; } int Height(struct node* node)
{ if (node==NULL)
return 0; else { int leftheight = Height(node->left); int rightheight = Height(node->right); if (leftheight >
rightheight)
return(leftheight+1); else return(rightheight+1); } } int totalnodes(struct node*root)
{ if(root==NULL)
return 0; if(root->left!=NULL)
{ n=n+1; n=totalnodes(root->left); } if(root->right!=NULL)
{ n=n+1; n=totalnodes(root->right); } return n; } void Preorder(struct node *root)
{ if(root!=NULL)
{

printf("%d\t",root->data); Preorder(root->left); Preorder(root->right); } } void inorder(struct node* root)
{ struct node *current, *pre; if (root == NULL)
return; current = root; while (current != NULL) { if (current->left == NULL) { printf("%d ", current->data); current =
current->right; } else { pre = current->left; while (pre->right != NULL && pre->right != current)
pre = pre->right; if (pre->right == NULL) { pre->right = current; current = current->left; } else { pre->right = NULL;
printf("%d ", current->data); current = current->right; }

} } } int totalinternalnodes(struct node *root)
{ if((root==NULL) || ((root->left==NULL) && (root->right==NULL)))
return 0; else return(totalinternalnodes(root->left) + totalinternalnodes(root->right) + 1); } int totalexternalnodes(
struct node *root)
{ if(root==NULL)
return 0; else { if((root->left==NULL) && (root->right==NULL))
return 1; else return (totalexternalnodes(root->left) + totalexternalnodes(root->right)); } } int main()
{ int option ,val; struct node *root=NULL; do { printf("\n***********MAIN MENU************"); printf("\n 1.create Tree")
; printf("\n 2.Insert Elements"); printf("\n 3.Delete an Elemet"); printf("\n 4.Height of a tree"); printf("\n 5.Total
nodes"); printf("\n 6.Total number of internal nodes");

printf("\n 7.Total number of external nodes"); printf("\n 8.Preorder Traversal"); printf("\n 9.Inorder Traversal");
printf("\n 10.Exit"); printf("\n Enter option : "); scanf("%d",&option); switch(option)
{ case 1:printf("enter the value : "); scanf("%d",&val); root = createNode(val); break; case 2:printf("\nenter the value
of new node:"); scanf("%d",&val); insert(root,val); break; case 3:printf("\n enter data to delete : "); scanf("%d",&val)
; deleteNode(root,val); break; case 4:printf("height of tree is %d",Height(root)); break; case 5:printf("total no. of
nodes is %d ",totalnodes(root)); break; case 6:
printf("total no. of internal nodes is %d ",totalinternalnodes(root)); break; case 7:
printf("total no. of external nodes is %d ",totalexternalnodes(root)); break; case 8:Preorder(root); break; case 9:
inorder(root); break;

case 10:exit(0); break; } } while(option!=11); getch(); return 0; }
