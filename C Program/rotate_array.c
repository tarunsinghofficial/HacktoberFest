#include <stdio.h>

void rotateLeft(int arr[], int n, int k) {
    k = k % n;
    int temp[k];
    for(int i = 0; i < k; i++)
        temp[i] = arr[i];
    for(int i = k; i < n; i++)
        arr[i - k] = arr[i];
    for(int i = 0; i < k; i++)
        arr[n - k + i] = temp[i];
}

void rotateRight(int arr[], int n, int k) {
    rotateLeft(arr, n, n - k);  // Right rotation = Left rotation by n-k
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, k;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter positions to rotate: ");
    scanf("%d", &k);

    rotateLeft(arr, n, k);
    printf("Array after left rotation: ");
    printArray(arr, n);

    rotateRight(arr, n, k);
    printf("Array after right rotation: ");
    printArray(arr, n);

    return 0;
}
