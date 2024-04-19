// C program to calculate stock span values
#include <stdio.h>

// Fills array S[] with span values
void calculateSpan(int price[], int n, int S[])
{
	// Span value of first day is always 1
	S[0] = 1;

	// Calculate span value of remaining days by linearly checking
	// previous days
	for (int i = 1; i < n; i++) {
		S[i] = 1; // Initialize span value

		// Traverse left while the next element on left is smaller
		// than price[i]
		for (int j = i - 1; (j >= 0) && (price[i] >= price[j]); j--)
			S[i]++;
	}
}

// A utility function to print elements of array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

// Driver program to test above function
int main()
{
	int price[] = { 10, 4, 5, 90, 120, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	int S[n];

	// Fill the span values in array S[]
	calculateSpan(price, n, S);

	// print the calculated span values
	printArray(S, n);

	return 0;
}
