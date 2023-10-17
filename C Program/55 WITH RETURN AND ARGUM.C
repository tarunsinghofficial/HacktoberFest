// WITH RETURN AND ARGUMENT

#include<stdio.h>
int sum(int c);
int main()
{
    int a,b,c;
    printf("Enter 2 NO.");
    scanf("%d%d",&a,&b);
    c=sum(a);
    printf("Sum is %d",c);
}
int sum(int a)
{
    c=a+b;
}