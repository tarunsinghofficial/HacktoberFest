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
    head->data=val;
    head->next=head;
    head=head;
}
void middle(node* &head){
    int l=length(head);
    l--;
    cout<<l<<endl;
    if(l%2==0){
        l=l/2;
        while (l>0){
            head=head->next;
            l--;
        }
    }
    else{
        l=ceil(l/2);
        while(l>0){
            head=head->next;
            l--;
        }
    }
}
int main(){
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    insertAttail(head,6);
    display(head);
    middle(head);
    display(head);
    return 0;
}
