import java.util.Scanner;

public class RecursiveBubbleSort {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array: ");
        int length = sc.nextInt();
        System.out.print("Enter the array elements: ");
        int[] intArray = new int[length];
        for (int i = 0; i < length; i++) {
            intArray[i] = sc.nextInt();
        }

        //input example
        //int arr[] = {50, 20, 10, 60, 70, 40, 30};
        
        bubbleSort(intArray, intArray.length);
        
        System.out.print("Sorted array: ");

        for (int i = 0; i < length; i++) {
            System.out.print(intArray[i] + " ");
        }
        //output example
        //Sorted array: 10 20 30 40 50 60 70
        
    }

    private static void bubbleSort(int intArray[], int n)
    {
        if (n == 1) 
            return;
        for (int i = 0; i < n-1; i++)
            if (intArray[i] > intArray[i+1]) {
                int temp = intArray[i]; 
                intArray[i] = intArray[i+1];
                intArray[i+1] = temp;
            }
        bubbleSort(intArray, n-1);
    }
} 