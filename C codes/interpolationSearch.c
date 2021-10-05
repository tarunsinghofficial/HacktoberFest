#include <stdio.h>
int interpolationSearch(int arr[], int low, int high, int x)
{
    int pos;
    if (low <= high && x >= arr[low] && x <= arr[high]) {
        pos = low+ (((double)(high - low) / (arr[high] - arr[low]))* (x - arr[low]));
        if (arr[pos] == x)
             printf("Element found at index %d", pos);
        else if(low == high){
            printf("Element not found");
        }
        if (arr[pos] < x)
            interpolationSearch(arr, pos + 1, high, x);
        if (arr[pos] > x)
            interpolationSearch(arr, low, pos - 1, x);
    }
    return -1;
}
 