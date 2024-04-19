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

void RightView(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int temp;

    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            temp = node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            cout << temp << " ";
            q.push(NULL);
        }
    }
    cout << temp;
}

void rightview(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    // q.push(NULL);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            node *node = q.front();
            q.pop();
            if (i == (n - 1))
            {
                cout << node->data << " ";
            }

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
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

    RightView(root);
}