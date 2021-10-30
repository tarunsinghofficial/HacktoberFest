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
 
 
 void insertAttail(node* &head, int val)
 {
 	node* n = new node(val);
 	if(head == NULL)
 	{
 		head = n;
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
 
  void insertAthead(node* &head, int val)
  {
  	node *n = new node(val);
  	n->next = head;
  	head->prev = n;
  	head = n;
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
 void lasttofirst(node* &head,int k)
 {
 	node*temp = head;
 	if(head==NULL)
 	  return;
 	int l =0;
	 while(temp->next!=NULL)
 	{
 		temp = temp->next;
 		l++;
	 }
 	node*p = head;
  
  while((l-k)>0)
  {
  	p= p->next;
  	l--;
  	
  }
  p->next->prev = NULL;
 	p->next = NULL;
 	temp->next = head;
 	
 	 
 	
 	
 }
 
int main()
{
	
 node* head = NULL;
insertAttail(head, 1);
insertAttail(head, 2);
insertAttail(head, 3);
insertAttail(head, 4);
insertAttail(head, 5);
display(head);
int k;
cin>>k;
 lasttofirst( head,k);
 
 display(head);
	return 0;
}
