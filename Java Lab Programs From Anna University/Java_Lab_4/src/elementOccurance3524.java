import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Random;
import java.util.Scanner;

public class elementOccurance3524 {
    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());

        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        // Generate a random value for n between 1 and 10
        int n = random.nextInt(10) + 1;

        int[] A = new int[n];
        int[] B = new int[n];

        System.out.println("Randomly generated value of n: " + n);

        System.out.println("Random integers for array A:");
        for (int i = 0; i < n; i++) {
            // Fill array A with random integers between 0 and 99
            A[i] = random.nextInt(100);
            System.out.print(A[i] + " ");
        }
        System.out.println();

        System.out.println("Random integers for array B:");
        for (int i = 0; i < n; i++) {
            // Fill array B with random integers between 0 and 99
            B[i] = random.nextInt(100);
            System.out.print(B[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < n; i++) {
            // Count the occurrences of each element of B in array A
            int count = countOccurrences(A, B[i]);
            System.out.println("Number of occurrences of " + B[i] + " in array A: " + count);
        }
    }

    // Count the occurrences of a target number in an array
    public static int countOccurrences(int[] arr, int target) {
        int count = 0;
        for (int num : arr) {
            if (num == target) {
                count++;
            }
        }
        return count;
    }
}
