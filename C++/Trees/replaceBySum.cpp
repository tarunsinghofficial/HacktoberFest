#include <bits/stdc++.h>
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

int replace(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    root->data = (root->data + replace(root->left) + replace(root->right));
    return root->data;
}

void traverse(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

main()
{
    node *nodes = new node(1);
    nodes->left = new node(2);
    nodes->right = new node(3);
    nodes->left->left = new node(4);
    nodes->left->right = new node(5);
    nodes->right->left = new node(6);
    nodes->right->right = new node(7);

    replace(nodes);

    traverse(nodes);
    cout<<endl;
    preorder(nodes);
}