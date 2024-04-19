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
void insert(node* &head,int val){
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
bool cycle(node* head){
    node* hare=head;
    node* tortoise=head;
    do
    {   tortoise=tortoise->next;
        hare=hare->next->next;
        if(hare==tortoise){
            return true;
        }
    }while(hare!=NULL && hare->next!=NULL);
    return false;
}
void makecycle(node* &head,int val){
    node* temp=head;
    node* startcycle;
    int c=1;
    while (temp->next!=NULL)
    {
        if(c==val){
            startcycle=temp;
        }
        temp=temp->next;
        c++;
    }     
    temp->next=startcycle;
}
void removecycle(node* &head){
    node* fast=head;
    node* slow=head;
    while (fast->next!=NULL && slow->next!=NULL)
    {   fast=fast->next->next;
        slow=slow->next;
        if(fast->next==slow->next){
            fast=head;
            break;
        }
    }
    while (fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}
int main()
{
    node* head=NULL;
    insert(head,0);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    display(head);
    makecycle(head,3);
    cout<<cycle(head)<<endl;
    removecycle(head);
    cout<<cycle(head)<<endl;
    display(head);
    return 0;
}
