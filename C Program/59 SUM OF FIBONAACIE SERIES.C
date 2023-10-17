// WAP TO PRINT THE SUM OF THE FIBONAACIE SERIES UPTO GIVEN TERM

#include<stdio.h>
int sum (int n);
int main()
{   int n;
    printf("Enter Number of Terms");
    scanf("%d",&n);
    sum(n);
}
int sum ( int n )
{
    int i,sum=0,a=0,b=1,c=(a+b);
    for(i=3;i<=n;i++)
    {
        sum=sum+c;
        a=b;
        b=c;
        c=(a+b);
    }
    printf("Sum is %d",sum);
}