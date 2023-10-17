// NO ARGUMENT RETURN

#include<stdio.h>
int sum();
int main()
{
    int c;
    c=sum();
    printf("%d",c);
}
int sum()
{
    int a,b,c;
    printf("Enter 2 No.");
    scanf("%d%d",&a,&b);
    c=a+b;
}