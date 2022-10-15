// A program for tree preorder traversals
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
void showPreorder(struct node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	showPreorder(node->left);
	showPreorder(node->right);
}
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printf("\n The Preorder traversal of binary tree \n");
	showPreorder(root);
	getchar();
	return 0;
}
