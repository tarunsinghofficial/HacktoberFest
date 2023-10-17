// WAP TO PRINT SUM OF DIGIT USING RECURSION

#include<stdio.h>
int sum(int n);
int main()
{
    int n,c;
    printf("Enter The Digit");
    scanf("%d",&n);
    c=sum(n);
    printf("Sum is %d",c);
}
int sum(int n)
{
    if(n!=0)
    return(n%10+sum(n/10));
    else
    return 0;
}