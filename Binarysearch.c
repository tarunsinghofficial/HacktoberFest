#include <stdio.h>
int binsearch(int array[], int key, int low, int high)
{
    int mid = (low + high) / 2;
    if (key == array[mid])
    {
        return mid;
    }
    else if (key > array[mid])
    {
        low = mid + 1;
        return binsearch(array, key, low, high);
    }
    else
    {
        high = mid - 1;
        return binsearch(array, key, low, high);
    }
}
int main(int argc, char const *argv[])
{
    int array[] = {1, 3, 4, 5, 6, 7, 8};
    int low = array[0];
    int high = array[6];

    int key;
    scanf("%d", &key);
    int result = binsearch(array, key, low, high);

    /* code */
    if (result)
    {
        printf("found at index %d", result);
    }
    else
    {
        printf("not ");
    }

    return 0;
}
