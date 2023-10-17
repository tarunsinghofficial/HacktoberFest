// WAP TO PRINT REVERSE OF INPUT DIGIT

#include<stdio.h>
int main()
{
    int rev=0,r,n;
    printf("Enter Any Number");
    scanf("%d",&n);
    while(n>0)
    {
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    printf("The Reverse Is %d",rev);
}