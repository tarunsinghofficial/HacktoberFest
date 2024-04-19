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
node* todelete(node* head,int n){
    node* temp=head;
    if(head->data==n){
        temp=temp->next;
        return temp;
    }
    while (head!=NULL){
        if(head->next->data==n){
            head=head->next->next;
        }
        else{
            head=head->next;
        }
        cout<<"reached here\n";
    }
    return temp;
}
int main()
{   node* newhead;
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    display(head);
    newhead=todelete(head,3);
    display(newhead);
    return 0;
}
