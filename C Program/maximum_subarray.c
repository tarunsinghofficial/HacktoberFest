/*Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.
A subarray is a contiguous part of an array.*/
#include <stdio.h>
int main(void)
{
    int i, n, current_sum = 0, maxsum = 0;
    printf("Enter the no of elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:", n);
    // for input
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d", &a[i]);
    }
    // for finding maximum subarray
    for (i = 0; i < n; i++)
    {
        current_sum = current_sum + a[i];
        if (current_sum > maxsum)
        {
            maxsum = current_sum;
        }
        else
        {
            current_sum = 0;
        }
    }
    printf("maximum sum is %d", maxsum);
    return 0;
}
/*
Enter the no of elements:5
Enter 5 elements:
Enter a[0]:-2

Enter a[1]:2

Enter a[2]:3

Enter a[3]:-1

Enter a[4]:3
maximum sum is 5
*/
