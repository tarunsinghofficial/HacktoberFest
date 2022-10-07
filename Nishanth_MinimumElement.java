import java.util.Arrays;
import java.util.Scanner;

public class MinimumElement {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter count: ");
        int count = scanner.nextInt();
        scanner.nextLine();

        int[] returnedArray = readIntegers(count);
        int returnedMin = findMin(returnedArray);

        System.out.println("min = " + returnedMin);
    }


    public static int[] readIntegers(int count) {
        int[] array = new int[count];
        for (int i = 0; i < array.length; i++) {
            System.out.println("Enter a number: ");
            array[i] = scanner.nextInt();
            scanner.nextLine();
        }
        return array;
    }


    public static int findMin(int[] array) {
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < array.length; i++) {
            int value = array[i];
            if (value < min) {
                min = value;
            }
        }
        return min;

    }
}