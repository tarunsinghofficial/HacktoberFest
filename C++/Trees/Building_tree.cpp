#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int data;
    struct node* left;
    struct node* right;

    public:
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int inorder[],int start , int end,int curr)
{
    for (int i = start; i <= end; i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node* BuildTree(int preorder[],int inOrder[],int start ,int end)
{

    static int idx=0;

    if(start>end)
    {
        return NULL;
    }

    int curr=preorder[idx];
    idx++;
    node* setnode= new node(curr);

    if(start==end)
    {
        return setnode;
    }

    int pos=search(inOrder,start,end,curr);

    setnode->left = BuildTree(preorder,inOrder,start,pos-1);
    setnode->right = BuildTree(preorder,inOrder,pos+1,end);

    return setnode;
}

void preorderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<< root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

main()
{
   int preorder[] = {1,2,4,3,5};
   int inOrder[] = {4,2,1,5,3};

   //Build tree
   node* treenew = BuildTree(preorder,inOrder,0,4);

    // called to check
   preorderPrint(treenew);
}