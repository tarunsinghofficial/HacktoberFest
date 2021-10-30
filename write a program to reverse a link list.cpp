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


node* reverserecursion(node* & head)
{
	if(head==NULL|| head->next==NULL)
	{
		return head;
	}
	 node* newhead = reverserecursion(head->next);

head->next->next = head;
head->next = NULL;
return newhead;


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


node* reversehill(node* head)
{
	
	
	
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
	display(head);
	node* newhead = reversehill(head);
	
	display(newhead);
	return 0;
}
