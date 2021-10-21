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

bool getpath(node* root,int n,vector<int> &v)
{
    if(root==NULL)
    {
        return false;
    }

    v.push_back(root->data);
    if(root->data==n)
    {
        return true;
    }

    if(getpath(root->left,n,v) || getpath(root->right,n,v))
    {
        return true;
    }

    v.pop_back();
    return false;
}

int LCA(node* root,int n1,int n2)
{
    vector<int> path1,path2;

    if(!getpath(root,n1,path1) || !getpath(root,n2,path2))
    {
        return -1;
    }

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
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

    cout << LCA(newnode, 4, 5);
}