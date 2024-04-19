package arrays.OneDimension;

import java.util.Arrays;
import java.util.Scanner;

/*
You have been given an integer array of size N that contains only integers, 0 ans 1.
write a function to sort this array.
Think of a solution which scans the array only once and doesn't require use of an extra
array.

Example:
input -> 0,1,1,0,1,0,1
output -> 0,0,0,1,1,1,1

Example 2:
input -> 1,0,1,1,0,1,0,1.
output -> 0,0,0,1,1,1,1,1
 */
public class sortZeroesAndOnes {


//    Using the two pointer approach
    public static void sortZeroOne(int[] arr){
        int s = 0;
        int e = arr.length - 1;

        while(s < e){
            if(arr[s] == 1){
                if(arr[e] != 1){
                    int temp = arr[s];
                    arr[s] = arr[e];
                    arr[e] = temp;
                }
                e--;
            }else{
                s++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] arr = new int[size];

        for(int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }

        System.out.println("Entered Array :" + Arrays.toString(arr));
        sortZeroOne(arr);
        System.out.println("After Sorting :" + Arrays.toString(arr));
    }
}
