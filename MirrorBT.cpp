#include<iostream>
using namespace std;

struct node
{	
	int data;
	node *prev,*next;
};

node *newnode(int k)
{
	node *temp=new node;
	temp->data=k;
	temp->prev=temp->next=NULL;
	return temp;
}
bool mirror(node* r,node* p)
{
	if(r==NULL && p==NULL)
	return true;
	if(r==NULL || p==NULL) 
	return false;
	if(r->data!=p->data)
	return false;
	return mirror(r->prev,p->next) && mirror(r->next,p->prev);
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
root1->next=newnode(32);
root1->next->next=newnode(1);
cout<<mirror(root,root1);
return 0;

}
