#include <stdio.h>

// Function to calculate the maximum sum of a sub-array of a given array
int maxSumArray(int a[], int size) {
    int i;
    int max_sum_so_far = 0;     // To store the maximum sum of sub-array found so far
    int max_ending_here = 0;    // To store the sum of the current sub-array

    for (i = 0; i < size; i++) {
        max_ending_here += a[i];

        // If the sum of the current sub-array becomes negative, reset it to 0
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }

        // Update the maximum sum found so far
        if (max_sum_so_far < max_ending_here) {
            max_sum_so_far = max_ending_here;
        }
    }

    return max_sum_so_far;
}

int main() {
    int i, size;

    // Input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare an array of the given size
    int a[size];

    // Input for the elements of the array
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    // Call the function to find the maximum sum of the sub-array
    int max_sum = maxSumArray(a, size);

    // Display the result
    printf("\n\nThe Maximum Sum of the Sub Array is: %d\n", max_sum);

    return 0;
}

