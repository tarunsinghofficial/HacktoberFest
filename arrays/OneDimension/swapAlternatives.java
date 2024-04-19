/*
you have been given an array ARR[] of size N. you need to swap every pair of alternative
elements of the array/list.
you don't need to print or return anything, just change in the input array itself.

Test Case 1:
Input: 9,3,6,12,4,32
Output: 3,9,12,6,32,4

Test Case 2:
Input : 8,3,4,9,2,5,6,7,9
Output: 3,8,9,4,5,2,7,6,9
 */

package arrays.OneDimension;

import java.util.Scanner;

public class swapAlternatives {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] arr = new int[size];

        for(int i = 0 ; i < size; i++){
            arr[i] = sc.nextInt();
        }

        for(int a : arr){
            System.out.print(a + " ");
        }

        //Logic Start Here
        int j = 0;
        int k = 1;

        while( k < size){
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
            k += 2;
            j += 2;
        }

        System.out.println();
        for(int i : arr){
            System.out.print(i + " ");
        }

    }
}
