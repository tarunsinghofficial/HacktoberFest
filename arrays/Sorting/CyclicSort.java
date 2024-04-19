/*
Implementing Cyclic sort.
Note: Cyclic sort is implemented only when the given elements are in range of
1 to N.

Time Complexity -> O(n)
 */

package arrays.Sorting;

import java.util.Arrays;
import java.util.Scanner;

public class CyclicSort {


    static int[] readArray(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        return arr;
    }

    //Method for Cyclic Sort
    static void cyclicSort(int[] arr){
        int i = 0;
        while(i < arr.length){
            int correctIndex = arr[i] - 1;
            if(arr[i] != arr[correctIndex]){
                swap(arr, i, correctIndex);
            }else{
                i++;
            }
        }
    }

    //Method to Perform Swapping
    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

    public static void main(String[] args) {
        int[] arr = readArray();
        System.out.println("Array Before Sorting :" + Arrays.toString(arr));
        cyclicSort(arr);
        System.out.println("Array Afer Sorting : " + Arrays.toString(arr));

    }
}
