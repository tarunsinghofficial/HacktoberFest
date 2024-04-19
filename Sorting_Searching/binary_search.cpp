
#include <iostream>
using namespace std;

// Binary Search: Iterative
int binarySearch(int arr[], int N, int ele)
{
	int low = 0;
	int high = N - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == ele)
			return mid;
		if (arr[mid] > ele)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

/* Binary Search: Recursive
int binarySearch(int arr[], int N, int ele, int low, int high)
{
	if (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == ele)
			return mid;
		if (arr[mid] > ele)
			binarySearch(arr, N, ele, low, mid - 1);
		binarySearch(arr, N, ele, mid + 1, high);
	}
	return -1;
} */

// Main function
int main()
{
	int *array, N, ele;
	cout << "\nEnter the size of array: ";
	cin >> N;

	array = new int[N];
	cout << "Enter the elements of sorted array: ";
	for (int i = 0; i < N; i++)
		cin >> array[i];

	cout << "Enter an element to be searched: ";
	cin >> ele;

	int res = binarySearch(array, N, ele);
	(res == -1) ? cout << "\nResult: -1 i.e. Element not found!" : cout << "\nElement found at index " << res << "!";

	cout << endl;
	return 0;
}