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
 
 
 
 int  add_2_no(node* head1,node* head2)
{
	node * temp1 = head1;
      node * temp2 = head2;
	int n =0,p=0;
	
	while(temp1 !=NULL)
	{ 
	  
	     int d = temp1->data;
 	    n = n*10+ d;
		temp1=temp1->next;

	}
	 
	 	while(temp2 !=NULL)
	{ 
	
	  int d = temp2->data;
	    p = p*10+ d;
		temp2=temp2->next;
	}
	
 
	n = n+p;
	return n;
	
	 } 	
 	
 	
 	
 
int main()
{
	
 node* head1 = NULL;
 
  node* head2 = NULL;
  
 int n1;
 cin>>n1;
 
 while(n1--)
 {
 	int temp;
 	cin>>temp; 
 	insertAttail(head1,temp);
 }
 int n2;
 cin>>n2;
 
 while(n2--)
 {
 	int temp;
 	cin>>temp; 
 	insertAttail(head2,temp);
 }
 
  display(head1);
 display(head2);
 
 int n = add_2_no(head1,head2) ;
     node* head3 = NULL;
	 while(n)
 {
 	int temp;
 	temp =  n%10; 
 	insertAthead (head3,temp);
 	n=n/10;
 }
 display(head3);
	return 0;
}
