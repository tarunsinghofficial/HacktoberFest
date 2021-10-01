// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
 
#include <stdio.h>
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)     // Perfoming the if operation for n times. 
        if (arr[i] == x)        // Checking if element at ith index is equal to x.
            return i;           //  if arr[i]=x i.e Element found, then return the i value as well as return control of the program to the main function.
    return -1;                 // if x is not found in the array, return -1 value as well as return control of the program to the main function.
}
 
// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };       // Arrayand declaration and initialization 
    int x = 10;                            // x is the element to be found in the array
    int n = sizeof(arr) / sizeof(arr[0]);  // n is the size of array 'arr[]'
   
    
    int result = search(arr, n, x);        // Function call
    (result == -1) 
        ? printf("Not Present")           // if result = -1 i.e Element is not found, this printf function will get executed.
        : printf("Present at index %d", result); // Otherwise, this printf function will get executed.
    return 0;  // End of main function.
}

Time Complexity:
Worst Case - O(n).
Best Case - O(1). 
