#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binary_search(int arr[], int target, int left, int right);
void sort_list(int arr[], int arr_size);
void swap(int *a, int *b);

int main(void) 
{
    int target;
    int arr[] = {3, 9, 16, 7, 8, 12, 6, 4, 2, 15};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("THIS IS FOR HACKTOBERFEST!!!\n");
    printf("Enter the target element: ");
    scanf("%d", &target);

    sort_list(arr, arr_size);

    int result = binary_search(arr, target, 0, arr_size - 1);
    (result == -1) ? printf("Target element not found.\n") : printf("Target found at position %d.\n", result);

    return 0;
}

int binary_search(int arr[], int target, int left, int right)
{
    if (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (target == arr[middle])
            return middle;

        if (target > arr[middle])
            return binary_search(arr, target, middle + 1, right);

        if (target < arr[middle])
            return binary_search(arr, target, left, middle - 1);
    }

    return -1; // Target element not found in the array
}

void sort_list(int arr[], int arr_size)
{
    int i, j;
    for (i = 0; i < arr_size - 1; i++)
    {
        for (j = 0; j < arr_size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
