//A c program that simply takes elements of the array from the user and finds the sum of these elements.

#include<stdio.h>
void main(void)
{
    int n,i,sum=0,arr[20];

    printf("Enter the size of array: ");
    scanf("%d",&n);

    printf("\nEnter %d elements in the array: ",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]); //taking user input in the array.
        sum=sum+arr[i];
    }

    printf("Sum of all elements of the array is %d",sum);

}
