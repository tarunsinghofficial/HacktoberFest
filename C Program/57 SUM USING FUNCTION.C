// WAP TO PRINT SUM OF DIGITS USING FUNCTION

#include<stdio.h>
int sum(int n);
int main()
{
    int n;
    printf("Enter The Digits");
    scanf("%d",n);
    printf("The Sum Of digits is %d",sum(n));
}
int sum(int n)
{
    int r,sum=0;
    while(n>0)
    {
        r=n%10;
        sum=sum+r;
        n=n/10;
    }
    return sum;
}