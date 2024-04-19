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
void display(node* head){
    while (head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void insertattail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
node* reverse(node* &head){
    node* preptr=NULL;
    node* currptr=head;
    node* nextptr;
    while (currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=preptr;
        preptr=currptr;
        currptr=nextptr;
    }
    return preptr;
}
node* reverserec(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main()
{
    node* head=NULL;
    insertattail(head,0);
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    display(head);
  //  node* tail=reverse(head);
   // display(tail);
    node* recteil=reverserec(head);
    display(recteil);
    return 0;
}
