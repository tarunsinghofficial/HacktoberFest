// WAP TO PRINT FIBONACCIE SERIES USING RECURSION

#include<stdio.h>
int fib(int i);
int  main()
{
    int n,i;
    printf("Enter Number Of Terms");
    scanf("%d",&n);
    printf("Fibonaccie series is");
    for(i=0;i<n;i++)
    {
        printf("%d",fib(i));
    }
}
int fib(int i)
{
    if(i==0)
    return 0;
    else if(i==1)
    return 1;
    else
    return (fib(i-1)+fib(i-2));
}