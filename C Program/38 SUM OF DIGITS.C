// WAP TO PRINT SUM OF DIGITS OF INPUT NUMBER

#include<stdio.h>
int main()
{
    int r,n,sum=0;
    printf("Enter A Number");
    scanf("%d",&n);
    while(n>0)
    {
        r=n%10;
        sum=sum+r;
        n=n/10;
    }
    printf("The Sum Is %d",sum);
}