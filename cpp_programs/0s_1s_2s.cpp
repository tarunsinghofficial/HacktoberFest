// C++ program to sort an array
// with 0, 1 and 2 in a single pass
#include <bits/stdc++.h>
using namespace std;

 
 
void sort012(int a[], int arr_size)
{
    int low = 0;
    int high = arr_size - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= high) {
        switch (a[mid]) {

        // If the element is 0
        case 0:
            swap(a[low++], a[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(a[mid], a[high--]);
            break;
        }
    }
}

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
  
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);

    printArray(arr, n);

    return 0;
}

