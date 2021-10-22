// 1. pick element from preorder & create a node ;
// 2. increment preoder idx ; 
// 3. serach for picked element's pos in inorder ;
// 4. call to build left subtree from 0 to pos-1 in inorder ;
// 5. call to build right subtree from pos+1 to end(n) in inorder ;
// 6. return the node ;  

#include<iostream>
using namespace std;


struct node{
	int data;
	node* left;
	node* right;
	node(int val){
		data =val;
		left=NULL;
		right= NULL;
	}
};

int search(int inorder[],int st,int en ,int curr){
	for (int i = st; i <=en; ++i)
	{
		if(inorder[i]==curr)return i;
	}
	return -1;
}
struct node* buildTree(int preorder[], int inorder[],int st,int en){
	static int idx=0;
	if(st>en)return NULL;
	int curr = preorder[idx];
	idx++;
	struct node* root=new node(curr);
	if(st==en)return root;
	int pos =search(inorder,st,en,curr);
	root->left = buildTree(preorder,inorder,st,pos-1);
	root->right = buildTree(preorder,inorder,pos+1,en);
	return root;
}

void inorder(struct node * root){
	if(root==NULL)return ;
	inorder(root->left);
	cout<<root->data<<"  ";
	inorder(root->right);

}

int main(){
	int preorder1[] = {1,2,4,5,3,6,7};
	int inorder1[] = {4,2,5,1,6,3,7};
	struct node* head = buildTree(preorder1,inorder1,0,6);
	inorder(head);


	return 0;
}
