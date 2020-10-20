// Java program to check if 
// a given number is lucky 

class GFG 
{ 
	// This function returns true if n is lucky 
	static boolean isLucky(int n) 
	{ 
		// Create an array of size 10 and initialize all 
		// elements as false. This array is used to check 
		// if a digit is already seen or not. 
		boolean arr[]=new boolean[10]; 
		for (int i = 0; i < 10; i++) 
			arr[i] = false; 
	
		// Traverse through all digits 
		// of given number 
		while (n > 0) 
		{ 
			// Find the last digit 
			int digit = n % 10; 
	
			// If digit is already seen, 
			// return false 
			if (arr[digit]) 
			return false; 
	
			// Mark this digit as seen 
			arr[digit] = true; 
	
			// Remove the last digit from number 
			n = n / 10; 
		} 
		return true; 
	} 
 
	public static void main (String[] args) 
	{ 
	int arr[] = {1291, 897, 4566, 1232, 80, 700}; 
		int n = arr.length; 
	
		for (int i = 0; i < n; i++) 
			if(isLucky(arr[i])) 
				System.out.print(arr[i] + " is Lucky \n"); 
			else
			System.out.print(arr[i] + " is not Lucky \n"); 
	} 
} 
