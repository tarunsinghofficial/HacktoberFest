#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int data;
    struct node *right;
    struct node *left;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void preorder(struct node *s)
{
    if (s == NULL)
    {
        return;
    }
    cout << s->data << " ";
    preorder(s->left);
    preorder(s->right);
}

void inorder(struct node *s)
{
    if (s == NULL)
    {
        return;
    }

    inorder(s->left);
    cout << s->data << " ";
    inorder(s->right);
}

void postorder(struct node *s)
{
    if (s == NULL)
    {
        return;
    }

    postorder(s->right);
    cout << s->data << " ";
    postorder(s->left);
}

main()
{
    struct node *s = new node(1);
    s->left = new node(2);
    s->right = new node(3);
    s->left->left = new node(4);
    s->left->right = new node(5);
    s->right->left = new node(6);
    s->right->right = new node(7);
    preorder(s);
    cout << endl;
    inorder(s);
    cout << endl;
    postorder(s);
}