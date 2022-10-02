/*
Implementing the count sort algo.

Time Complexity = O(n + k)
Space Complexity = O(n + k)
 */

package arrays.Sorting;

import java.util.Arrays;
import java.util.Scanner;


public class CountingSort {
    Scanner sc = new Scanner(System.in);
    private int[] readArray(){
        int size = sc.nextInt();
        int[] array = new int[size];

        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }
        return array;
    }


    private int[] countingSort(int[] array, int range) {
        int[] count_array = new int[range];
        int[] output_array = new int[array.length];
        Arrays.fill(count_array, 0);

        for (int j : array) {
            ++count_array[j];
        }

        for(int i = 1; i < range; i++){
            count_array[i] += count_array[i - 1];

        }

        for (int j : array) {
            output_array[--count_array[j]] = j;
        }

        return output_array;
    }

    public static void main(String[] args) {
        CountingSort sort = new CountingSort();
        int[] input_array = sort.readArray();
        System.out.println("Enter the Range ");
        int range = sort.sc.nextInt();

        System.out.println("Give Array is : " + Arrays.toString(input_array));
        if(range <= input_array.length){
            System.out.println("Range is equal or too low for Sorting the array. \n" +
                    "Array can't be Sorted.");
        }else{
            input_array = sort.countingSort(input_array, range);
            System.out.println(Arrays.toString(input_array));
        }



    }

}
