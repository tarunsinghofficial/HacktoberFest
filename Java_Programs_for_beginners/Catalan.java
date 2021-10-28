import java.util.Scanner;

class Catalan {

	// find nth Catalan number
    public static int catalanDP(int n)
	{
		
		int cat[] = new int[n + 2];

		// Initialize first two values in table
		cat[0] = 1;
		cat[1] = 1;

		for (int i = 2; i <= n; i++) {
			cat[i] = 0;
			for (int j = 0; j < i; j++) {
				cat[i] += cat[j] * cat[i - j - 1];
			}
		}

		// Return last entry
		return cat[n];
	}

	// Driver code
	public static void main(String[] args)
	{

        // Catalan numbers are a sequence of positive integers, where the nth term in the sequence, denoted Cn, 
        // is found in the following formula: (2n)! / ((n + 1)!n!)

        Scanner in = new Scanner(System.in);
        System.out.println("Enter n (upto 20th catalan numbers will be printed): ");
        int n = in.nextInt();
        while(n>=20 || n<=0){
            System.out.print("Enter n < 20: ");
            n = in.nextInt();
        }
        in.close();
		for (int i = 0; i < n; i++) {
			System.out.print(catalanDP(i) + " ");
		}
	}
}
