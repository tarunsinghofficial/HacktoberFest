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
node* merge(node* &head,node* &nexthead){
    node* p1=head;
    node* p2=nexthead;
    node* dummynode=new node(-1);
    node* p3=dummynode;
    while (p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while (p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while (p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummynode->next;
}
node* mergerecursive(node* &head1,node* &head2){
    node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        result=head1;
        result->next=mergerecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergerecursive(head1,head2->next);
    }
    return result;
}
int main()
{
    node* head=NULL;
    node* nexthead=NULL;
    insertAttail(head,1);
    insertAttail(head,8);
    insertAttail(head,11);
    insertAttail(nexthead,5);
    insertAttail(nexthead,7);
    insertAttail(nexthead,9);
    insertAttail(nexthead,10);
    insertathead(head,0);
    node* heading=mergerecursive(head,nexthead);
    display(heading);
    return 0;
}
