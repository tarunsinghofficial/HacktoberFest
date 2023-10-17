// WAP TO PRINT THE SUM OF ARRAY ELEMENT

#include<stdio.h>
int main()
{
    int i,n,a[10],sum=0;
    printf("Enter Size Of Array");
    scanf("%d",&n);
    printf("Enter Array Elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Sum Of Elements is ");
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    {
        printf("%d",sum);
    }
}