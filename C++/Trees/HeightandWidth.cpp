#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
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

int calculateHeight(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left=calculateHeight(root->left);
    int right=calculateHeight(root->right);
    return max(left,right)+1;
}

int calcDiameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lHeight=calculateHeight(root->left);
    int rHeight=calculateHeight(root->right);
    int currHeight=lHeight+rHeight+1;

    int ldia=calcDiameter(root->left);
    int rdia=calcDiameter(root->right);

    return max(currHeight,max(ldia,rdia));
}

/**
 *      1
 *     / \
 *    2   3
 *   / \ 
 * 
 * 
 * 
*/

main()
{
   node* nodE =new node(1);
   nodE->left=new node(2);
   nodE->right=new node(3);
   nodE->left->left=new node(4);
   nodE->left->right=new node(5);
   nodE->right->left=new node(6);
   nodE->right->right=new node(7);

   cout<<calculateHeight(nodE);
}