#include<stdio.h>
#include<stdlib.h>


int s[5],top=0;
void push()
{
  if(top==4)
  {
    printf("Stack overflow");
  }
  else
  {
    printf("Enter element :");
    scanf(" %d ",&s[++top]);
  }
}

void pop()
{
  if(top==-1)
  {
    printf("Stack underflow ");
  }
  else{
    printf("element deleted : %d",s[top--]);
  }
}

void disp()
{
  int t=top;
  while(t>0)
    {
      printf("%d\t",s[t--]);
    }
}