//WAP TO CHECK THE NUMBER IS ARMSTRONG OR NOT

#include<stdio.h>
int main()
{
    int a,n,r,sum=0;
    printf("Enter Any Number");
    scanf("%d",&n);
    a=n;
    while(n>0)
    {
        r=n%10;
        sum=sum+(r*r*r);
        n=n/10;
    }
    if(a==sum)
    printf("Armstrong");
    else
    printf("Not Armstrong");
}