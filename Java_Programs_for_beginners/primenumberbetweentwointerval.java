import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the starting number:");
        int s = sc.nextInt();
        System.out.println("Enter the ending number:");
        int e = sc.nextInt();

        System.out.println("Prime numbers between " + s + " and " + e + ":");
        
        for (int i = s; i <= e; i++) {
            int flag = 1; // Assume the number is prime
            if (i <= 1) {
                continue; // Skip 0 and 1 as they are not prime numbers
            }
            for (int j = 2; j <= Math.sqrt(i); j++) { // Check divisibility up to the square root of i
                if (i % j == 0) {
                    flag = 0; // Not a prime number
                    break; // No need to check further
                }
            }
            if (flag == 1) {
                System.out.println(i); // Print the prime number
            }
        }
        sc.close(); // Close the scanner to prevent resource leaks
    }
}
