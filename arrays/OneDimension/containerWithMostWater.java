/*
Given n non-negetive integers a[0], a[1],...,a[n - 1] where each represent a point at
coordinate (i, a[i]). These 'n' vertical lines are drawn such that the two endpoints of
line i is at (0, i) and (a[i], i).

Find two lines, which together with x-axis form a container, suxh that the container contains
the most water.

The program should return an integer which correspinds to the maximum are of water that
can be contained.

Note : You may not slant the container.
 */
package arrays.OneDimension;

import java.util.Arrays;
import java.util.Scanner;

public class containerWithMostWater {

    public static int maxWater(int[] nums){
        int i = 0;
         int j = nums.length;
         int area = 0;
         while(i < j){
             int w = j - i;
             int h = Math.min(nums[i], nums[j]);
             int calArea = w * h;
             if(area < calArea){
                 area = calArea;
             }

             if(nums[i] < nums[j]){
                 i++;
             }else{
                 j--;
             }
         }
         return area;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] nums = new int[size];

        for(int i = 0; i < nums.length; i++){
            nums[i] = sc.nextInt();
        }

        System.out.println("Given Array is : " + Arrays.toString(nums));
        System.out.println("Maximum Water is we can hold in given Data is : " + maxWater(nums));
    }
}
