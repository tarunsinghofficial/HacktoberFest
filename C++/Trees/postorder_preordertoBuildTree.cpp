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

int search(int postOrder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (postOrder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node *buildTree(int inOrder[], int postOrder[], int start, int end)
{
    static int idx = end;

    if (start > end)
    {
        return NULL;
    }

    int curr = inOrder[idx];
    node *setnode = new node(curr);
    int pos = search(postOrder, start, end, curr);
    idx--;

    if (start == end)
    {
        return setnode;
    }

    setnode->right = buildTree(inOrder, postOrder, pos + 1, end);
    setnode->left = buildTree(inOrder, postOrder, start, pos - 1);

    return setnode;
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

main()
{
    int inOrder[] = {4,2,1,5,3};
    int postOrder[] = {4, 2, 1, 5, 3};

    node *newnode = buildTree(inOrder, postOrder, 0, 4);

    preOrder(newnode);
}