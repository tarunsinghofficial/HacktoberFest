// find the position of any element...
#include <stdio.h>
int find_element(int a[], int n, int k)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (k == a[mid])
        {
            return mid;
        }
        if (a[mid] > a[low])
        {
            if (k < a[mid] && k >= a[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (k > a[mid] && k <= a[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(void)
{
    int i, n, k, idx;
    printf("Enter the no of elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d roated sorted elements:", n);
    // for input
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d", &a[i]);
    }
    printf("Enter the element you want to search:");
    scanf("%d", &k);
    idx = find_element(a, n, k);
    printf("index find at %d position", idx);
    return 0;
}
/*
Enter the no of elements:3
Enter 3 roated sorted elements:
Enter a[0]:1

Enter a[1]:2

Enter a[2]:3
Enter the element you want to search:2
index find at 1 position
*/
