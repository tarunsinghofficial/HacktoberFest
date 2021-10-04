#include <stdio.h>
int main()
{
    int n, i, j, temp,item,flag=0,low,high,mid;
    int arr[64];

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
            while ( j > 0 && arr[j-1] > arr[j])
            {
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
    }
    printf("Sorted list in ascending order:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("\n  Enter the number to be search: ");
    scanf("%d",&item);

    low=0,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(item==arr[mid])
        {
            flag=1;
            break;
        }
        else if(item<arr[mid])
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    if(flag==0)
    printf("\n  The number is not found");
    else
    printf("\n  The number is found and its position is: %d",mid+1);
    return 0;
}
