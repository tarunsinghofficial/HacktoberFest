#include<conio.h>
#include<stdio.h>
void main()
{ 
    int a,b,sum,sub,div,prod;
    printf("enter the value of a \n");
    scanf("%d",&a);
    printf("enter the value of b\n");
    scanf("%d",&b);
    sum=a+b;
    sub=a-b;
    div=a/b;
    prod=a*b;
    printf("sum=%d\n",sum);
    printf("sub=%d\n",sub);
    printf("div=%d\n",div);
    printf("prod=%d\n",prod);
    getch();
    
}