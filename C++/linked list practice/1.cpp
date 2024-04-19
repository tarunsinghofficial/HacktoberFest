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
bool serach(node* head,int key){
    do
    {
        if(head->data==key)
        {
            return true;
        }
        head=head->next;
    }while (head!=NULL);    
    return false;
}
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
int main()
{
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    display(head);
    insertathead(head,0);
    display(head);
    cout<<serach(head,4);
    return 0;
}
