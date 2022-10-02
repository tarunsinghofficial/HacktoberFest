package arrays.OneDimension;
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 */

import java.util.Scanner;

public class twoSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] nums = new int[size];

        for(int i = 0; i < size; i++){
            nums[i] = sc.nextInt();
        }

        System.out.println("Given Array : \n");
        for(int i : nums){
            System.out.print(i + " ");
        }

        System.out.println("Enter target ");
        int target = sc.nextInt();

        //Main Logic

        int[] a = new int[2];

        for(int i = 0; i < nums.length; i++){
            for(int j = i + 1; j < nums.length ; j++){
                if(target == nums[i] + nums[j]){
                    a[0] = i;
                    a[1] = j;
                }
            }
        }

        for (int i : a){
            System.out.print(i + " ");
        }
    }
}
