#include<stdio.h>
int main()
{
    int arr[100],n,temp,i,j;
    printf("enter total number of element ");
    scanf("%d",&n);
    printf("enter the array element ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<=n;i++)
    {
        for(j=i;j>0 && arr[j-1]>arr[j];j--)
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
    printf("Insertion Sort ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}