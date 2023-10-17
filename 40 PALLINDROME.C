// WAP TO CHECK THE NUMBER IS PALLINDROME OR NOT

#include<stdio.h>
int main()
{
    int rev=0,n,r,a;
    printf("Enter The Number");
    scanf("%d",&n);
    a=n;
    while(n>0)
    {
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    if(a==rev)
    {
        printf("The Number Is Pallindrome");
    }
    else
    {
        printf("The Number is Not a Pallindrome");
    }
}