#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAttail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int length(node* head){
    int c=1;
    while (head!=NULL)
    {
        head=head->next;
        c++;
    }
    return c;
}
void insertathead(node* &head,int val){
    node* temp;
    temp->data=val;
    temp->next=head;
    head=temp;
}
void change(node* &head){
    node* odd=head;
    node* even=head->next;
    node* dummy=head->next;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=dummy;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}
int main(){   
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    display(head);
    change(head);
    display(head);
    return 0;
}
