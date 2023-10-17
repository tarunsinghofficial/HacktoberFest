//WAP TO CHEK THE NUMBER IS PRIME OR NOT

#include<stdio.h>
int main()
{
    int n,i,c=0;
    printf("Enter Any Number");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    if(n%i==0)
    c=c+1;
    if(c==2)
    {
        printf("Prime Number");
    }
    else
    {
        printf("Not a Prime number");       
    }
}
