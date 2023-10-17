// WAP TO PRINT THE SMALLEST ELEMENT IN 1-D ARRAY

#include<stdio.h>
int main()
{
    int a[20],min,n,i;
    printf("Enter Size Of Array");
    scanf("%d",&n);
    printf("Enter Elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    min=a[0];
    for(i=0;i<n;i++)
    if(i>min)
    {
        min=a[i];
    }
    printf("Smallest Number Is %d",min);
}