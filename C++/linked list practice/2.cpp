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
void insertattail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void deleteathead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deleteing(node* &head,int key){
    if(head==NULL){
        return;
    }
    if(head->data==key){
        deleteathead(head);
        return;
    }
    node* temp=head;
    while (temp->next->data!=key){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
int main()
{   node* head=NULL;
    insertattail(head,0);
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    display(head);
    deleteing(head,0);
    display(head);
    return 0;
}
