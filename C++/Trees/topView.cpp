#include<bits/stdc++.h>
using namespace std;
#define ll long long
class node
{
    int data;
    int hd;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void topView(node* root)
{
    if(root==NULL)
    {
        return;
    }

    
}

main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->right->left = new node(6);
    root->right = new node(5);

    topView(root);
}