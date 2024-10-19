class FibonacciExample {
    public static void main(String[] args) {
        int n1 = 0, n2 = 1, n3, count = 10;

        System.out.print(n1 + " " + n2); // Printing 0 and 1

        for (int i = 2; i < count; ++i) { // Loop starts from 2
            n3 = n1 + n2; // Next Fibonacci number
            System.out.print(" " + n3); // Print the next number
            n1 = n2; // Update n1
            n2 = n3; // Update n2
        }

        System.out.println(); // Add a new line at the end
    }
}

