/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


Follow up: Could you come up with a one-pass algorithm using only constant extra space?
 */
package arrays.OneDimension;

import java.util.Arrays;
import java.util.Scanner;

public class sort0_1_And_2 {

    public static void sort012(int[] arr){
        int s = 0, e = arr.length - 1;
        int current = 0;
        while(current <= e){
            if(arr[current] == 0){

                int temp = arr[s];
                arr[s] = arr[current];
                arr[current] = temp;
                current++;
                s++;
            } else if (arr[current] == 2) {
                int temp = arr[e];
                arr[e] = arr[current];
                arr[current] = temp;
                e--;
            }else{
                current++;
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

        System.out.println("Before Sorting : ");
        System.out.println(Arrays.toString(arr));
        sort012(arr);
        System.out.println("After Sorting : ");
        System.out.println(Arrays.toString(arr));
    }
}
