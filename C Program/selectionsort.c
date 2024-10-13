#include <stdio.h>

void initialize(int arr[], int n) {
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display(int arr[], int n) {
    printf("Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]); 
    printf("\n"); 
}

void sort(int arr[], int n) {
    int i, j, temp, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i; 
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        if (minIndex != i) { 
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    initialize(arr, n);
    display(arr, n);

    sort(arr, n);
    printf("After Sorting ");
    display(arr, n); 
    return 0;
}
