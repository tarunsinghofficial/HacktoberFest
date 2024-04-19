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

// sum of a paticular level
int printLevelKSum(node* root,int k)
{
    if(root==NULL)
    {
        return -1;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty())
    {
        node* node=q.front();
        q.pop();

        if(node!=NULL)
        {
            if(level==k)
            {
                sum+=node->data;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())
        {
            level++;
            q.push(NULL);
        }
    }
    return sum;
}

/*
        1
      /   \
     2     3
    / \   / \
   4   5 6   77
        \
         50
*/

main()
{
    node *newnode = new node(1);
    newnode->left = new node(2);
    newnode->right = new node(3);
    newnode->left->left = new node(4);
    newnode->left->right = new node(5);
    newnode->right->left = new node(6);
    newnode->right->right = new node(77);
    newnode->left->right->right=new node(50);

    cout << printLevelKSum(newnode, 2);
}