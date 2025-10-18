import java.util.*;
/*
 *The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most
 *significant digit. Radix sort uses counting sort as a subroutine to sort.
*/ 
class RadixSort {
 
    static int getMax(int arr[], int n)
    {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }
 
    static void countSort(int arr[], int n, int exp)
    {
        int output[] = new int[n]; // output array
        int i;
        int count[] = new int[10];
        Arrays.fill(count, 0);
 
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
 
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
 
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
 
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
 
    static void radixsort(int arr[], int n)
    {
        int m = getMax(arr, n);
 
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(arr, n, exp);
    }
 
    static void print(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }
// Driver Function 
    public static void main(String[] args)
    {
        int arr[] = { 1, 100, 25, 0, 588, 62, 54, 5006};
        int n = arr.length;
           
          // Function Call
        radixsort(arr, n);
        print(arr, n);
    }
}