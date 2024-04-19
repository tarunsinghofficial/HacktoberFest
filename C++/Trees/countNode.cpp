#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void countNumberOfNode(node* root)
{
    if(root==NULL)
    {
        return;
    }

    int c=0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* node = q.front();
        q.pop();

        if(node!=NULL)
        {
            c++;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
    cout<<c;
}

int countNumberOfNodeRecursive(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return countNumberOfNodeRecursive(root->left)+countNumberOfNodeRecursive(root->right)+1;
}

int countNumberOfNodeSum(node* root)
{
    
    if(root==NULL)
    {
        return 0;
    }
    return countNumberOfNodeSum(root->left)+countNumberOfNodeSum(root->right)+root->data;
}

main()
{
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->right=new node(7);

    // countNumberOfNodeRecursive(root);
    cout<<countNumberOfNodeSum(root)<<" = Sum\n";
}