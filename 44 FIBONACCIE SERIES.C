// WAP TO PRINT FIBONACCIE SERIES

#include<stdio.h>
int main()
{
    int i,n,a=0,b=1;
    int nxt=(a+b);
    printf("Enter Number Of Terms");
    scanf("%d",&n);
    printf("Fibonaccie series is %d%d",a,b);
    for(i=3;i<n;i++)
    {
        printf("%d",nxt);
        a=b;
        b=nxt;
        nxt=(a+b);
    }
}