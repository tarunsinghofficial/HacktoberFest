/*
Implementing The Quick Sort Algorithm to Sort the given array.
Time Complexity -> theta(n log(n))
Space Complexity -> O(log(n));
One of the most efficient and fast sorting algo.
 */
package arrays.Sorting;

import java.util.Arrays;
import java.util.Scanner;

public class QuickSort {
    Scanner sc = new Scanner(System.in);

    private int[] readArray(){
        int size = sc.nextInt();
        int[] array = new int[size];
        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }
        return array;
    }
    private void quickSort(int[] array, int start, int end) {
        if(start < end){
            int p = Partition(array, start,end);
            quickSort(array, start, (p - 1));
            quickSort(array, (p + 1), end);
        }
    }

    private int Partition(int[] array, int start, int end) {
        int pivot = array[end];
        int pIndex = start;
        for(int i = start; i < end - 1; i++){
            if(array[i] <= pivot){
                int temp = array[i];
                array[i] = array[pIndex];
                array[pIndex] = temp;
                pIndex++;
            }
        }
        int temp = array[end];
        array[end] = array[pIndex];
        array[pIndex] = temp;
        return pIndex;
    }

    public static void main(String[] args) {
        QuickSort sort = new QuickSort();

        int[] array = sort.readArray();

        System.out.println("Array Before Sorting ");
        System.out.println(Arrays.toString(array));
        System.out.println("Array After Sorting ");
        sort.quickSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
    }


}
