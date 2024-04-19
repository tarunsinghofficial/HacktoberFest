#include<iostream>
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
void display(node* head){
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
node* reverse(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int c=0;
    while(currptr!=NULL && c<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        c++;
    }
    if(nextptr!=NULL){
    head->next=reverse(nextptr,k);
    }
    return prevptr;
}
int main()
{
    node* head=NULL;
    insertattail(head,0);
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    display(head);
    node* newhead=reverse(head,4);
    display(newhead);
    return 0;
}
