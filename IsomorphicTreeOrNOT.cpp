#include<iostream>
using namespace std;

struct node
{	
	int data;
	node *prev,*next;
};

bool ismorphic(node *root,node* root2)
{
	if(root==NULL && root2==NULL)
	return true;
	if(root==NULL || root2==NULL)
	return false;
	if(root->data!=root2->data)
	return false;
	return( (ismorphic(root->prev,root2->next) && ismorphic(root->next,root2->prev)) ||
	(ismorphic(root->prev,root2->prev) && ismorphic(root->next,root2->next)));
	
	
}
node *newnode(int k)
{
	node *temp=new node;
	temp->data=k;
	temp->prev=temp->next=NULL;
	return temp;
}

int main()
{
node *root=NULL,*root1=NULL;
root = newnode(4);
root->prev=newnode(3);
root->prev->prev=newnode(1);
root->next=newnode(7);
root->next->prev=newnode(6);
root->next->next=newnode(9);

root1 = newnode(4);
root1->prev=newnode(7);
root1->prev->prev=newnode(9);

root1->prev->next=newnode(6);
root1->next=newnode(3);
root1->next->next=newnode(1);
cout<<ismorphic(root,root1);
return 0;

}
