#include<stdio.h>
#include<stdlib.h>
struct node{
int num;
struct node *nextptr;
} *stnode;
void create(int n);
void insertpos(int num, int pos);
void display();
int main()
{
    int n,num,pos;
    printf("Enter total data to be inserted:");
    scanf("%d",&n);
    create(n);
    printf("Display:\n");
    display();
    printf("Input data to be inserted at position:");
    scanf("%d",&num);
    printf("Position:");
    scanf("%d",&pos);
    insertpos(num,pos);
    printf("Insert completed.");
    printf("Data:\n");
    display();
    return 0;
}
void create(int n)
{
    int num, i;
    struct node *fnnode, *tmp;
    stnode=(struct node*)malloc(sizeof(struct node));
    if(stnode==NULL)
    {
        printf("Can't be inserted.");
    }
    else
    {
        printf("Data 1:");
        scanf("%d",&num);
        stnode->num=num;
        stnode->nextptr=NULL;
        tmp=stnode;
        for(i=2;i<=n;i++)
        {
            fnnode=(struct node*)malloc(sizeof(struct node));
            if(fnnode==NULL)
            {
                printf("Can't be inserted.");
            }
            else
            {
                printf("Data %d:",i);
                scanf("%d",&num);
                fnnode->num=num;
                fnnode->nextptr=NULL;
                tmp->nextptr=fnnode;
                tmp=tmp->nextptr;
            }
        }
    }
}
void insertpos(int num, int pos)
{
    int i;
    struct node *fnnode, *tmp;
    fnnode=(struct node*)malloc(sizeof(struct node));
    if(fnnode==NULL)
    {
        printf("Empty");
    }
    else
    {
        fnnode->num=num;
        fnnode->nextptr=NULL;
        tmp=stnode;
        for(i=2;i<=pos-1;i++)
        {
            tmp=tmp->nextptr;
            if(tmp==NULL)
                break;
        }
        if(tmp!=NULL)
        {
            fnnode->nextptr=tmp->nextptr;
            tmp->nextptr=fnnode;
        }
        else
        {
            printf("Not possible.");
        }
    }
}

void display()
{
    struct node *tmp;
    if(stnode==NULL)
    {
        printf("Empty");
    }
    else
    {
        tmp=stnode;
        while(tmp!=NULL)
        {
            printf("Data:%d\n",tmp->num);
            tmp=tmp->nextptr;
        }
    }
}
