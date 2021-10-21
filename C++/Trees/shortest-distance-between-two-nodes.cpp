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

node* LCA(node* root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==n1 || root->data==n2)
    {
        return root;
    }

    node* left=LCA(root->left,n1,n2);
    node* right=LCA(root->right,n1,n2);

    if(left!=NULL && right!=NULL)
    {
        return root;
    }

    if(left==NULL && right==NULL)
    {
        return NULL;
    }

    if(left!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

int dis(node* root,int k,int dist)
{
    if(root==NULL)
    {
        return -1;
    }

    if(root->data==k)
    {
        return dist;
    }

    int left=dis(root->left,k,dist+1);
    if(left!=-1)
    {
        return left;
    }

    int right=dis(root->left,k,dist+1);
    if(right!=-1)
    {
        return right;
    }
}

int mindis(node* root,int n1,int n2)
{
    node* lca=LCA(root,n1,n2);

    int d1=dis(lca,n1,0);
    int d2=dis(lca,n2,0);

    return d1+d2+1;
}

main()
{
    node *newnode = new node(1);
    newnode->left = new node(2);
    newnode->right = new node(3);
    newnode->left->left = new node(4);
    newnode->left->right = new node(5);
    newnode->right->left = new node(6);
    newnode->right->right = new node(77);
    newnode->left->right->right = new node(50);

    cout << mindis(newnode, 77, 5);

}