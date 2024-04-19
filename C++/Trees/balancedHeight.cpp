#include <bits/stdc++.h>
#include<conio.h>
using namespace std;
#define ll long long
struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

bool balancing(node *root)
{
    if(root==NULL)
    {
        return true;
    }
    if(balancing(root->left)==false)
    {
        return false;
    }
    if(balancing(root->right)==false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    int diff = lh - rh;
    abs(diff);

    if (diff <= 1)
    {
        return true;
    }
    return false;
}

main()
{
    node *root = new node(1);
    root->left=new node(1);
    root->left->left=new node(1);
    root->left->left->right=new node(1);

    cout << balancing(root);
    getch();
}