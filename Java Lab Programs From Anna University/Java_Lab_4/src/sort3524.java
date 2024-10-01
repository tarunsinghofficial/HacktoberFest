import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Scanner;

public class sort3524 {

    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter no of elements: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter the array elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int comparisonsBubbleSort = bubbleSort(arr.clone());
        int comparisonsSelectionSort = selectionSort(arr.clone());


        System.out.println("\nNumber of comparisons for Bubble Sort: " + comparisonsBubbleSort);
        System.out.println("Number of comparisons for Selection Sort: " + comparisonsSelectionSort);
    }

    public static int bubbleSort(int[] arr) {
        int n = arr.length;
        int comparisons = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        System.out.println("Sorted array in ascending order(Bubble Sort):");

        printArray(arr);
        return comparisons;
    }

    public static int selectionSort(int[] arr) {
        int n = arr.length;
        int comparisons = 0;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
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
        System.out.printf("\n");
    }
}
