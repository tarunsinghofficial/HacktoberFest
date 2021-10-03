import java.util.Arrays;
import java.util.*;
import java.lang.*;

public class SortExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();//inputting the array size
        int arr[] = new int[n];
        for (int j = 0; j < n; ++j) {
            arr[j] = sc.nextInt();
        }
        Arrays.sort(arr); // Sorts arr[] in ascending order
        System.out.println("The Sorted Array Is:");
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
    }
}
