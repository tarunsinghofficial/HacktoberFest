//A c program that simply takes elements of the array from the user and finds the sum of these elements.

#include<stdio.h>
void main()
{
    int n,sum=0,arr[n];
    
    printf("Enter the size of array: ");
    scanf("%d",&n);
    
    printf("\nEnter %d elements in the array: ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]); //taking user input in the array.
        sum+= arr[i];
    }

    printf("Sum of all elements of the array is %d",sum);
    return 0;
}
