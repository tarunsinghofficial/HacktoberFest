import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Random;
import java.util.Scanner;

public class randomSort3524 {

    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter no of elements: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];
        arr = RandomArray(arr);

        int comparisonsInt = OrderNSort(arr.clone());
        char[] charArray = CharArray(arr);
        int comparisonsChar = OrderNSort(charArray.clone());

        System.out.println("Number of comparisons for integer array sorting: " + comparisonsInt);
        System.out.println("Number of comparisons for character array sorting: " + comparisonsChar);
    }

    public static int[] RandomArray(int[] arr) {
        Random random = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(26);
        }
        return arr;
    }

    public static char[] CharArray(int[] intArray) {
        char[] charArray = new char[intArray.length];
        for (int i = 0; i < intArray.length; i++) {
            charArray[i] = (char) (intArray[i] + 'a');
        }
        return charArray;
    }

    public static int OrderNSort(int[] arr) {
        int comparisons = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        System.out.println("Sorted array in ascending order(Selection Sort):");
        printArray(arr);
        return comparisons;
    }

    public static int OrderNSort(char[] arr) {
        int comparisons = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        System.out.println("\nSorted array in ascending order(Selection Sort):");
        printArray(arr);
        return comparisons;
    }

    public static void printArray(int[] arr) {
        System.out.print("|");
        for (int i = 0; i < arr.length; i++) {
            System.out.printf(" %d |", arr[i]);
        }
    }

    public static void printArray(char[] arr) {
        System.out.print("|");
        for (int i = 0; i < arr.length; i++) {
            System.out.printf(" %c |", arr[i]);
        }
        System.out.print("\n");
    }
}
