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
 
 
 
 int  add_1_no(node* head)
{
	node * temp = head;

	int n =0;
	while(temp !=NULL)
	{ 
	  int d = temp->data;
	n = n*10+ d;
		temp=temp->next;
	}
	n = n+1;
	
 
	
	return n;
	
	 } 	
 	
 	
 	
 
int main()
{
	
 node* head1 = NULL;
 
 
 int n1;
 cin>>n1;
 
 while(n1--)
 {
 	int temp;
 	cin>>temp; 
 	insertAttail(head1,temp);
 }

 
  display(head1);
 
cout<<add_1_no(  head1)<<"\n";
    
	return 0;
}
