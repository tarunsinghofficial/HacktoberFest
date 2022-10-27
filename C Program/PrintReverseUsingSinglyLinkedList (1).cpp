#include<iostream>
using namespace std;

struct stu{
	
	int id;
	stu *next = NULL;
	
};

stu *first = NULL;
stu *last = NULL;

int opt;
int key;

void insert_end();
void insert_start();
void display();
void first_last_even();
void first_last_odd();
void palindrome();
void reverse();

int main(){
	
	do{
		
		cout<<"\n0.Exit";
		cout<<"\n1.Insert at end";
		cout<<"\n2.Insert at start";
		cout<<"\n3.Display";
		cout<<"\n4.First & Last for Even nodes";
		cout<<"\n5.First & Last for Odd nodes";
		cout<<"\n6.Palindrome";		
		cout<<"\n7.Reverse";	
		
		cout<<"\n\n\nEnter your choice: ";
		cin>> opt;
		
		switch(opt){
			
			case 1:{
				insert_end();
				break;
			}
			
			case 2:{
				insert_start();
				break;
			}
			
			case 3:{
				display();
				break;
			}
			
			case 4:{
				first_last_even();
				break;
			}
			
			case 5:{
				first_last_odd();
				break;
			}
			
			case 6:{
				palindrome();
				break;
			}
			case 7:{
				reverse();
				break;
			}
		}
	}
	while(opt != 0);
	
return 0;

}


void insert_end(){
	
	stu *current  = new stu;
	
	cout<<"\n\nEnter the id: ";
	cin>>current->id;
	
	if(first == NULL){
		cout<<"\n\nEmpty";
		first = last = current; 
	}
	else{
		last->next = current;
		last = current;
	}
	
}

void insert_start(){
	
	stu *current  = new stu;
	
	cout<<"\n\nEnter the id: ";
	cin>>current->id;
	
	if(first == NULL){
		cout<<"\nEmpty";
		first = last = current; 
	}
	else{
		current->next = first;
		first = current;
	}
	
}

void display(){
	
	cout<<"\n";
	
	stu *current  = new stu;
	stu *p = first;
	
	if(first == NULL){
		cout<<"\n\nEmpty";
		first = last = current; 
	}
	else{
		while(p != NULL){
			cout<< p->id<<" ";
			p = p->next;
		}
	}
	
	cout<<"\n";
	
}

void first_last_even(){
	
	// for even number of nodes
	
	stu *temp = first;
	stu *p = first;
	stu *p1 = NULL;

	stu *k = last;
	
	int count = 0;
	
	while(temp != k){
		while(p != k){
			count++;
			p1 = p;
			p = p->next;
		}
		
	cout<<temp->id<<" ";	//1
	cout<<k->id<<" ";		//5
		
	temp = temp->next;		//2
	k = p1;					//4
		
	p = temp;
		
	}
	
	cout<<"\n\nThe no. of nodes are: "<<count;
	
}

void first_last_odd(){
	
	// for odd number of nodes
	
	stu *temp = first;
	stu *p = first;
	stu *p1 = NULL;

	stu *k = last;
	
	int count = 0;
	
	while(temp != k){
		while(p != k){
			count++;
			p1 = p;
			p = p->next;
		}
		
	cout<<temp->id<<" ";	//1
	cout<<k->id<<" ";		//5
		
	temp = temp->next;		//2
	k = p1;					//4
		
	p = temp;
		
	}
	cout<<temp->id;
	
	cout<<"\n\nThe no. of nodes are: "<<count;
	
}

void palindrome(){
	
	// for even number of nodes
	
	stu *temp = first;
	stu *p = first;
	stu *p1 = NULL;
	stu *k = last;
	
	while(temp != k){
		while(p != k){
			p1 = p;
			p = p->next;
				
	}
		if(temp->id == k->id){
		temp = temp->next;	
		k = p1;					
		p = temp;
		cout<<"\n\ntrue";
	}
	else{
		cout<<"\n\nfalse";
		break;
	}		
}

cout<<"\n\n";
	
}

void reverse(){
	
	stu *p = first;
	stu *p1 = NULL;
	stu *p2 = first;
	
	//1 2 3 4 5
	while(p != p2){
		while(p != NULL){
		p1 = p;
		p = p->next;
		
	}
	cout<<p->id<<" ";
	p = p1;		
	}
	
	cout<<" ";
}