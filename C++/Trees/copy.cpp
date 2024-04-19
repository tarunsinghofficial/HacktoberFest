#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void traverse(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
}

node* copy(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }

    struct node* temp;
    temp->left=copy(root->left);
    temp->right=copy(root->right);
    temp->data=root->data;

    return temp;
}

main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->right = new node(4);
    struct node* newroot=copy(root);

    traverse(root);
    cout <<endl;
    traverse(newroot);
}