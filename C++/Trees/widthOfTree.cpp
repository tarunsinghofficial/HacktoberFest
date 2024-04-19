#include<bits/stdc++.h>
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

int Width(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int width=1;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int c=0;

    while (!q.empty())
    {  
        struct node* node=q.front();
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
            if(c>width)
            {
                width=c;
            }
            c=0;
            q.push(NULL);
        }
    }
    
    return width;
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
    newnode->left->right->right=new node(50);

    cout<<"The maximum width is : "<<Width(newnode);
}