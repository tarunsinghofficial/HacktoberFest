package arrays.OneDimension;

import java.util.Arrays;
import java.util.Scanner;

public class findDuplicates2 {


//    This will only work only if the given array contains integers from 1 to N -1.
    public static void findDuplicates(int[] nums){
        for(int i = 0; i < nums.length; i++){
            int x =  Math.abs(nums[i]);
            if(nums[x] > 0){
                nums[x] *= -1;
            }else{
                System.out.println(x);
            }
        }
    }

//    When ever the array is contains integers form 0 to N - 1 use this logic.
    public  static void Duplicates2(int[] nums){
        for(int i = 0; i < nums.length; i++){
            int x = nums[i] % nums.length;
            nums[x] = nums[x] + nums.length;
        }

        for(int i = 0; i < nums.length; i++){
            int x = nums[i] / nums.length;
            if(x >= 2){
                System.out.println(i);
            }

        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] nums = new int[size];
        for(int i = 0; i < nums.length; i++){
            nums[i] = sc.nextInt();
        }

        System.out.println("Given Array is : " + Arrays.toString(nums));
        findDuplicates(nums);
//        Duplicates2(nums);
    }
}
