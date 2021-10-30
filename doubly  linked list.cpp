#include<bits/stdc++.h>
using namespace std;
 
 class node{
 	public :
 		
 			int  data;
 			node* next;
 			node* prev;
          node(int val)
          {
          	data = val;
          	next = NULL;
          	prev = NULL;
		  }
 	
 	
 };
  
 void deletion(node* &head,int val)
{

if(head==NULL)
   return;

node* temp = head;

while(temp->data!=val)
{
	temp = temp->next;
}
node *p = temp->next;
temp->next = temp->next->next;
temp->next->prev = temp;
delete(p);
}
 void insertAthead(node* &head, int val)
  {
  	node *n = new node(val);
  	n->next = head;
    if(head!=NULL)
  	head->prev = n;
  	head = n;
  }
  
 void insertAttail(node* &head, int val)
 {
 	node* n = new node(val);
 	if(head == NULL)
 	{
 		
 		insertAthead(head,val);
 		return;
	 }
	  node* temp = head;
	 while(temp->next!=NULL)
	 {
	 	temp = temp->next;
	 }
	  temp->next = n;
 
	 n->prev = temp;

 }
 
 
 void display(node* head)
 {
 	node* temp= head;
 	while(temp!=NULL)
 	{
 		cout<<temp->data<<" ";
 		temp = temp->next;
 		
	 }
 	cout<<"\n";
 	return;
 	
 }
int main()
{
	
 node* head = NULL;
insertAttail(head, 1);
insertAttail(head, 2);
insertAttail(head, 3);
display(head);
 deletion(head,2);
 display(head);
	return 0;
}
