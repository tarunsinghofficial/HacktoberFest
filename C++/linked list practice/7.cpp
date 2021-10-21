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
    int c=0;
    while (head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}
node* change(node* head,int k){
    node* newhead;
    node* newtail;
    node* tail=head;
    int l=length(head);
    k=k%l;
    int c=1;
    while (tail->next!=NULL)
    {
        if (c==l-k)
        {
            newtail=tail;
        }
        if (c==l-k+1)
        {
            newhead=tail;
        }
        c++;
        tail=tail->next;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
}
int main(){
    int k,n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int a[n];
    node* head=NULL;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        insert(head,a[i]);
    }
    display(head);
    cout<<"Enter the value of 'k' in here\n";
    cin>>k;
    node* newhead=change(head,k);
    display(newhead);
    return 0;
}
