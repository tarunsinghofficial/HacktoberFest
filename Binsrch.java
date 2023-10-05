import java.util.*;
import java.io.*;
public class Binsrch
{
    public static void main(String args[]) 
    {
        int[] arr = { 2, 5, 7, 9, 12, 15, 18 };
        Scanner obj = new Scanner(System.in);
        System.out.print("Enter a number to search: ");
        int num = obj.nextInt();
        int result = binarySearch(arr, num);
        if (result == -1) 
            System.out.println("Element not found");
        else 
                    System.out.println("Element found at index " + result);
    }
    public static int binarySearch(int[] arr, int num) {
        int left = 0, right = arr.length - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == num) 
                return mid;
            else if (arr[mid] < num) 
                left = mid + 1;
                 else 
                right = mid - 1;
        }
        return -1;
    }
}
