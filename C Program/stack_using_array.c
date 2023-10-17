#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX (sizeof(int)*100)
//This is the implementation of stack in C language and same could be run in C++ as well

void peek(int *lumb,int seze4)
{
    if(seze4==-1)
    {
        printf("\nThe Stack is Empty already.\n");
    }
    else
    {
        printf("\nThe Top/Latest Element of Stack is:%d\n",lumb[seze4]);
    }
}

void found_Del(int *lumb1,int *seze5,int value1)
{
    if((*seze5)==-1)
    {
        printf("\nThe Stack is Empty already.\n");
    }
    for(int k=0;k<=((*seze5));k++)
    {
        if(lumb1[k]==value1)
        {
            printf("\nThe element Deleted is :%d\n",value1);
            for(int m=k;m<(*seze5);m++)
            {
                lumb1[m] = lumb1[m+1];
            }
            *seze5 = *seze5-1;
            break;
        }
    }
}

void push(int *lumber,int *seze)
{
    int item;
    printf("Enter any data you want to insert:");
    scanf("%d",&item);
    *seze = *seze+1;
    lumber[*seze] = item;
    printf("\nItem has been inserted\n");
}

void pop(int *lumber1,int *seze1)
{
    if((*seze1)==-1)
    {
        printf("\nThe Stack is Empty already.\n");
    }
    else
    {
        printf("\nThe Deleted Top Element is: %d\n",lumber1[(*seze1)]);
        *seze1 = *seze1-1;
    }
}

void Found_ele(int *lumber2,int seze2,int value)
{
    int i;
    if(seze2==-1)
    {
        printf("\nThe Stack is Empty already.\n");
    }
    else
    {
        for(i=0;i<=seze2;i++)
        {
            if(lumber2[i]==value)
            {
                printf("\nFound the Element : %d\n",lumber2[i]);
                break;
            }
        }
        if(i==seze2+1)
        {
            printf("\nElement Not Found\n");
        }
    }
}

void Printing(int *lumber3,int *seze3)
{
    if((*seze3)==-1)
    {
        printf("\nThe Stack is Empty already.\n");
    }
    else
    {
        for(int j=0;j<=((*seze3));j++)
        {
            printf("%d\t",lumber3[j]);
        }
        printf("\n");
    }
}

int main()
{
    int top = -1;
    int stack_arr[MAX];
    int element,option,delele;
    printf("1.   Push an element in a Stack\n");
    printf("2.   Pop an element in a Stack\n");
    printf("3.   Find an Element\n");
    printf("4.   Print the Stack\n");
    printf("5.   Top Element of the Stack\n");
    printf("6.   Delete Particular Element from the Stack\n");
    printf("7.   Exit from Process\n");
    printf("Choose one option:");
    scanf("%d",&option);
    while(option!=7)
    {
        if(option==1)
        {
            push(stack_arr,&top);
        }
        else if(option==2)
        {
            pop(stack_arr,&top);
        }
        else if(option==3)
        {
            printf("Enter the item to be searched of:");
            scanf("%d",&element);
            Found_ele(stack_arr,top,element);
        }
        else if(option==4)
        {
            Printing(stack_arr,&top);
        }
        else if(option==5)
        {
            peek(stack_arr,top);
        }
        else if(option==6)
        {
            printf("Enter the item to be deleted:");
            scanf("%d",&delele);
            found_Del(stack_arr,&top,delele);
        }
        else
        {
            printf("Invalid user input");
            break;
        }
        printf("1.   Push an element in a Stack\n");
        printf("2.   Pop an element in a Stack\n");
        printf("3.   Find an Element\n");
        printf("4.   Print the Stack\n");
        printf("5.   Top Element of the Stack\n");
        printf("6.   Delete Particular Element from the Stack\n");
        printf("7.   Exit from Process\n");
        printf("Choose one option:");
        scanf("%d",&option);
    }
    return 0;
}

