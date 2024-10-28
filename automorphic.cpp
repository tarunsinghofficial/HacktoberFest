// C++ program to check if a number is Automorphic 
#include <iostream> 
using namespace std; 

// Function to check Automorphic number 
bool isAutomorphic(int N) 
{ 
	
	if(N < 0) N = -N; 
		
	
	// Store the square 
	int sq = N * N; 

	// Start Comparing digits 
	while (N > 0) { 
		// Return false, if any digit of N doesn't 
		// match with its square's digits from last 
		if (N % 10 != sq % 10) 
			return false; 

		// Reduce N and square 
		N /= 10; 
		sq /= 10; 
	} 

	return true; 
} 

// Driver code 
int main() 
{ 
	int N = 5; 

	isAutomorphic(N) ? cout << "Automorphic"
					: cout << "Not Automorphic"; 

	return 0; 
} 
