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
void merge(node* head)
 	{
 		
	 }
 void merge_sort(node* &head)
 {
 	
 }
int main()
{
	int n;
	cin>>n;
	
 node* head1 = NULL;

 for(i=0;i<n;i++)
 {
 	int temp;
 	cin>>temp;
 	insertAttail(head,temp);
 }

 
display(head);

 display(head);
	return 0;
}
