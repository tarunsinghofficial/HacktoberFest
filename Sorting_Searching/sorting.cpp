#include <iostream>
using namespace std;

// Bubble Sort
template <typename T>
void bubbleSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
}

// Insertion Sort
template <typename T>
void insertionSort(T arr[], int size)
{
	T key;
	int i, j;
	for (i = 0; i < size; ++i)
	{
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

// Selection Sort
template <typename T>
void selectionSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < size; j++)
			if (arr[minIndex] > arr[j])
				minIndex = j;
		swap(arr[minIndex], arr[i]);
	}
}

// to print array
template <typename T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Main function
int main()
{
	int *array, N;
	cout << "\nEnter the size of array: ";
	cin >> N;
	array = new int[N];
	cout << "Enter the elements of array: ";
	for (int i = 0; i < N; i++)
		cin >> array[i];
	cout << "\nUnsorted Array: ";
	printArray(array, N);
	
	int choice;
	cout << "\nSelect a sorting algorithm\n";
	cout << "\n1. Bubble Sort";
	cout << "\n2. Insertion Sort";
	cout << "\n3. Selection Sort";
	cout << "\nYour choice: ";
	cin >> choice;
	
	switch (choice)
	{
		case 1:
			cout << "\nApplying bubble sort...";
			bubbleSort<int>(array, N);
			break;
		case 2:
			cout << "\nApplying insertion sort...";
			insertionSort<int>(array, N);
			break;
		case 3:
			cout << "\nApplying selection sort...";
			selectionSort<int>(array, N);
			break;
		default: 
			cout << "\nInvalid Choice!";
	}
	cout << "\nSorted Array: ";
	printArray(array, N);

	return 0;
}