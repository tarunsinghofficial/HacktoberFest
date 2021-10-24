
#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int N, int ele)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == ele)
			return i;
	}
	return -1;
}

// Main function
int main()
{
	int *array, N, ele;
	cout << "\nEnter the size of array: ";
	cin >> N;
	
	array = new int[N];
	cout << "Enter the elements of array: ";
	for (int i = 0; i < N; i++)
		cin >> array[i];
		
	cout << "Enter an element to search in the array: ";
	cin >> ele;
		
	int res = linearSearch(array, N, ele);
	(res == -1) ? cout << "\nResult: -1 i.e. Element not found!" : cout << "\nElement found at index " << res << "!";
	
	cout << endl;
	return 0;
}