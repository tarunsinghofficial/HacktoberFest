// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
 
#include <stdio.h>

int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Element found
        }
    }
    return -1; // Element not found
}

// Driver code
int main(void) {
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int result = search(arr, n, x);
    if (result == -1) {
        printf("Not Present\n");
    } else {
        printf("Present at index %d\n", result);
    }

    return 0; // Return success
}
