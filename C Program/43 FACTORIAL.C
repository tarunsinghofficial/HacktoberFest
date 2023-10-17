// WAP TO PRINT FACTORIAL OF GIVEN NUMBER
// ERROR

#include<stdio.h>
int main()
{
    int i=1,f=1,n;
    printf("Enter The Number");
    scanf("%d",&n);
    if(n<0)
    printf("Enter Positive Number");
    else
    while(i<=n)
    {
        f=f*i;
        i=i+1;
    }
    printf("Factorial Is %d",f);
}