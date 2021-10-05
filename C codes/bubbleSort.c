#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("%d  ", arr[i]);
    }

}

void bubbleSort(int arr[], int n){
        int i,j,temp;
        int count=0;
        for( i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(arr[j+1]<arr[j])
                {
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                }
                count++;
            }
            
        }
        printf("Array sorted after %d comparisons.", count);
        printf("Sorted Array: ");
        display(arr, n);
}

