#include <stdio.h>
void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
 void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min = j;
        swap(arr[min], arr[i]);
    }
    printArray(arr,n);
}
