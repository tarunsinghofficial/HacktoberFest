#include<stdio.h>

// Function to calculate the maximum sum of a sub-array of a given array using Kadane's Algorithm.
int findMaxSubArraySum(int arr[], int size) {
    int i;
    int maxSumSoFar = 0;       // Variable to store the maximum sum encountered so far
    int currentSubArraySum = 0; // Variable to store the current sub-array sum

    // Iterate through the array to calculate maximum sub-array sum
    for(i = 0; i < size; i++) {
        currentSubArraySum += arr[i]; // Add the current element to the sub-array sum

        // If the current sub-array sum is negative, reset it to zero (i.e., ignore the sub-array)
        if(currentSubArraySum < 0) {
            currentSubArraySum = 0;
        }

        // Update maxSumSoFar if the current sub-array sum is larger
        if(maxSumSoFar < currentSubArraySum) {
            maxSumSoFar = currentSubArraySum;
        }
    }

    return maxSumSoFar;
}

int main() {
    int i, arraySize;

    // Input: Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int arr[arraySize];

    // Input: Get the elements of the array from the user
    printf("\nEnter the elements of the array:\n");
    for(i = 0; i < arraySize; i++) {
        scanf("%d", &arr[i]);
    }

    // Function call to find the maximum sum of a sub-array
    int maxSum = findMaxSubArraySum(arr, arraySize);

    // Output the result
    printf("\nThe Maximum Sum of the Sub-Array is: %d\n", maxSum);

    return 0;
}
