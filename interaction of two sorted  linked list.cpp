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

 	node* interactionoftwoarray(node* head1, node* head2)
 	{
 		node* temp1 =   head1;
 		node* temp2 =   head2;
 		node* newhead = NULL;
 		
 		while(temp1!=NULL&& temp2!=NULL)
 		{
 			if(temp1->data==temp2->data)
 			{
 				insertAttail( newhead,temp1->data);
 				temp1= temp1->next;
 				temp2= temp2->next;
			 }
 			
 			
 			else if(temp1->data>temp2->data)
 			{
 				temp2=temp2->next;
			 }
			 else  
 			{
 				temp1=temp1->next;
			 }
		 }
 		
 		return newhead;
 		
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

   node*  newhead =  interactionoftwoarray( head1, head2);
 display(newhead);
	return 0;
}
