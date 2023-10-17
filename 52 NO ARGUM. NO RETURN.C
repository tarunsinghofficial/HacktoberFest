// WAP TO PRINT SUM OF TWO NUMBER (NO ARGUMENTS NO RETURN VALUE)

#include<stdio.h>
int sum();
int main()
{
    sum();
}
int sum()
{
    int a,b,c;
    printf("Enter Two Number");
    scanf("%d %d",&a,&b);
    c=a+b;
    printf("Sum is %d",c);
}