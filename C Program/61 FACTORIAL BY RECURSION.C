// WAP TO FIND THE FACTORIAL OF NUMBER USING RECURSION

#include<stdio.h>
int facto(int n);
int main()
{
    int n,f;
    printf("Enter The Number");
    scanf("%d",&n);
    f=facto(n);
    printf("Factorial is %d",f);
    return 0;
}
int facto(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    else
    {
        return(n*facto(n-1));
    }
}
