//WAP TO READ AND WRITE 1-D ARRAY

#include<stdio.h>
int main()
{
    int i,n,a[10];
    printf("Enter Size Of Araay");
    scanf("%d",&n);
    printf("Enter Elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Elements are %d",a[i]);
        printf("\n");
    }
}