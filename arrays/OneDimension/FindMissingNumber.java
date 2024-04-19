/*
Given an array of n - 1 of distinctive number in range from 1 to n. Find
the missing number in it.

EXAMPLE:
    arr[] = [2, 4, 1, 8, 6, 3 ,7]

Output:
    5.
 */
package arrays.OneDimension;

import java.util.Scanner;

public class FindMissingNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        n += 1;

        for(int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }

//        usingArray(arr, n);
        System.out.println(usingArray(arr, n));
        System.out.println(usingBitwise(arr));

    }

    static  int usingBitwise(int nums[]){
        int n = nums.length ;
        int ans = 0 ;
        for (int i = 0 ; i < n ; i++){
            ans = ans^nums[i]^(i+1);
        }
        return ans ;
    }
    static  int usingArray(int arr[], int n){
        int sumOfN = (n * (n + 1)) / 2;
        int sum = 0;
        for(int i = 0; i < arr.length; i++){
            sum += arr[i];
        }

        return sumOfN  - sum;
    }
}
