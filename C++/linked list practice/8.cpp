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
void display(node* head){
    while (head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void insertattail(node* &head,int val){
    node* n=new node(val);
    if (head==NULL){
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
int length(node* head){
    int c=1;
    while(head!=NULL){
        head=head->next;
        c++;
    }
    return c;
}
int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    node* ptr1;
    node* ptr2;
    int d;
    if (l1>l2)
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while (d)
    {   d--;
        ptr1=ptr1->next;
        if(ptr1->next==NULL){
            return -1;
        }
    }
    while (ptr1->next!=NULL && ptr2->next!=NULL)
    {   
        if(ptr1==ptr2){
            return (ptr1->data);
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
}
void intersect(node* head1,node* head2,int pos){
    int l1=length(head1);
    int l2=length(head2);
    if (l1>l2){
        pos--;
        node* temp1=head1;
        node* temp2=head2;
        while (pos--)
        {
            temp1=temp1->next;
        }
        while (temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp1;
    }
    else{
        node* temp1=head2;
        node* temp2=head1;
        pos--;
        while (pos--)
        {
            temp1=temp1->next;
        }
        while (temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp1;
    }
}
int main(){
    node* head=NULL;
    node* newhead=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    insertattail(head,7);
    insertattail(newhead,11);
    insertattail(newhead,12);
    insertattail(newhead,13);
    intersect(head,newhead,3);
    display(head);
    display(newhead);
    cout<<intersection(head,newhead)<<"\n";
    return 0;
}
