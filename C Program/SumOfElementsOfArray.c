//A c program that simply takes elements of the array from the user and finds the sum of these elements.

#include <stdio.h>

int main(void) {
    int n, i, sum = 0;
    int arr[20];

    printf("Enter the size of the array (max 20): ");
    scanf("%d", &n);

    // Ensure n does not exceed the array size
    if (n > 20) {
        printf("Size exceeds maximum limit of 20.\n");
        return 1; // Exit with error code
    }

    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Taking user input for the array
        sum += arr[i]; // Update sum
    }

    printf("Sum of all elements of the array is %d\n", sum);

    return 0; // Return success
}
