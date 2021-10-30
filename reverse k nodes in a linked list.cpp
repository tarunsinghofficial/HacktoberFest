#include<bits/stdc++.h>
using namespace std;

class node
{
	public :
		int data;
		node* next;
		node(int val)
		{
			data = val;
			next = NULL;
		}
	

};

void insertATtail(node* &head, int val)
{
	node *n = new node(val);
	if(head==NULL)
	{
		head = n;
		return;
	}
	node* temp = head;
	while(temp->next!=NULL)
	{
		temp= temp->next;	
	}
	temp->next = n;
}


display(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
		
	}
	cout<<"\n";

}


node* reversell(node* &head,int k)
{
	node* temp = head;
	node* current = head;
	node* prev = NULL;
	node* nexptr ;
	while(temp!=NULL)
	{
	
for(int i=0;i<k;i++)	
{
 temp= temp->next;
 nexptr = current->next;
 current->next = prev;
 prev = current;
 current = nexptr;

	
	
}
	
}

node* newnode  = prev;
return newnode;
}



node* reverse(node* &head)
 {
    node* prev = NULL;
    node* current = head;
    node* nextptr ; 

   while(current!=NULL)
 {
	nextptr = current->next;
	current->next = prev;
	prev = current;
	current = nextptr;
 }

node* newhead = prev;
return newhead;

}


int main()
{
	node* head = NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insertATtail(head,val);
	}
	int k;
	cin>>k;
	display(head);
	node* newhead = reversell(head,k);
	
	display(newhead);




	return 0;
}
