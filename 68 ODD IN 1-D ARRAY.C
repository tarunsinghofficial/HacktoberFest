// WAP TO PRINT THE ODD NUMBER IN 1-D ARRAY

#include<stdio.h>
int main()
{
    int i,n,a[10];
    printf("Enter Size Of Array");
    scanf("%d",&n);
    printf("Enter Elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Odd Elements are ");
    for(i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            printf("%d ",a[i]);
        }
    }
}