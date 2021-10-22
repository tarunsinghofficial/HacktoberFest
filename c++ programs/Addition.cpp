// C++ program to add two number
// using addition operator
#include <iostream>
using namespace std;
// Function to return sum
// of two number
int addTwoNumber(int A, int B)
{
	// Return sum of A and B
	return A + B;
}

// Driver Code
int main()
{
	// Given two number
	int A = 4, B = 11;

	// Function call
	cout << "sum = " << addTwoNumber(A, B);
	return 0;
}
