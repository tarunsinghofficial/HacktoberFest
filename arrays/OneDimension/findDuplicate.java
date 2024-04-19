/*
you have given an integer array of size N which contains numbers from 0 to (N - 2). Each number
is present at least once. That is, if N = 5. the array constitutes values ranging from 0 to 3 and
among these, there is a single integer valuue that is present twice. You need to find and return
that dublicate number present in the array.

Example 1:
Input 0,2,1,3,1
OutPut : 1.

Example 2:
Input: 0,3,1,5,4,3,2
Output: 3.
 */

package arrays.OneDimension;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class findDuplicate {

    public static int duplicate(int[] nums){
        int i = 0;
        int j = 1;
        Arrays.sort(nums);
        while(j < nums.length - 1){
            if(nums[i] == nums[j]){
                return nums[i];
            }
            i++;
            j++;
        }
        return -1;
    }

//  Optimised Solution for the same problem:

    public static int duplicateOptimised(int[] nums){
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

//    Approach 3 if their eis duplicates more than 1
    public static List<Integer> approach3(int[] nums){
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < nums.length; i++){
            int index = Math.abs(nums[i]) - 1;
            if(nums[index] < 0) list.add(index + 1);
            nums[index] *= -1;
        }

        return list;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] nums = new int[size];

        for(int i =0; i < size; i++){
            nums[i] = sc.nextInt();
        }

        System.out.println("Given Array is : " + Arrays.toString(nums));
//        System.out.println("Ans is : " + duplicate(nums));
//        System.out.println(duplicateOptimised(nums));
        System.out.println(approach3(nums));
    }
}
