//arrange in ascending order of data
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
void insertathead(node* &head,int val){
    node* temp;
    temp->data=val;
    temp->next=head;
    head=temp;
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
void ascend(node* &head){
    int l=length(head);
    node* ii=head;
    for (int i = 0; i < l-2; i++)
    {   node* jj=ii->next;
        for (int j = i+1; j < l; j++)
        {   if(ii->data>jj->data){
                int temp=ii->data;
                ii->data=jj->data;
                jj->data=temp;
            }
            jj=jj->next;
        }
        ii=ii->next;
    }
}
int main()
{
    node* head=NULL;
    insertAttail(head,8);
    insertAttail(head,13);
    insertAttail(head,12);
    insertAttail(head,4);
    insertAttail(head,5);
    display(head);
    insertathead(head,0);
    ascend(head);
    display(head);
    return 0;
}
