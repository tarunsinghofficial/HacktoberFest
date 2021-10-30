#include<bits/stdc++.h>
using namespace std;
 
 class node{
 	public :
 		
 			int  data;
 			node* next;
 			
          node(int val)
          {
          	data = val;
          	next = NULL;
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
 
	 

 }
 int linkedlist_length(node* head)
 {
 	node*temp=  head;
 	int count=1;
 	while(temp!=NULL)
 	{
 		temp = temp->next;
	 count++;
	 }
 	
 	return count;
 	
 }
 int  findinteraction(node* head1,node* head2)
 {
 	int l1 =  linkedlist_length(head1);
    int l2 =  linkedlist_length(head2);
    
    
	 int d=0;  
    node*p1;
    node*p2;
    
	if(l1>l2)
    {
    	p1= head1;
    	p2 = head2;
    	d = l1-l2;
    	
	}
    
    else
    {
    	p1 = head2;
    	p2 = head1;
    	d = l1-l2;	
	}
	
		int count =0;
    	
	while(count<d)
    	{  
		  if(p1==NULL)
		  {
		  	  return -1;
		  }
    	
    		p1=p1->next;
    		
    		count++;
		}
    count =0;
    while(p1!=NULL &&p2!=NULL)
    {
    		if(p1==p2)
    	 {
    	 	return p1->data;
		 }
    	p1=p1->next;
    	p2=p2->next;
    
	 count++;
	
	}
    
     
 }
 
  void insertAthead(node* &head, int val)
  {
  	node *n = new node(val);
  	n->next = head;
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
void insertattaill(node* &head1,node* &head2,int pos)
{
	
	node* temp1 = head1;
	node* temp2 = head2;
	while(pos--)
	{
		temp1=temp1->next;
	}
	
	while(temp2!=NULL)
{
	
	temp2=temp2->next;
	
}
temp2->next = temp1;
}
 	
 
int main()
{
	
 node* head1 = NULL;
 node* head2 = NULL;
insertAttail(head1, 1);
insertAttail(head1, 2);
insertAttail(head1, 3);
insertAttail(head1, 4);
insertAttail(head1, 5);
display(head1);
insertAttail(head2, 9);
insertAttail(head2, 10);
 insertattaill(head1,head2,3);
 display(head2);
	return 0;
}
