/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 */



//Need To Optimise more.
package arrays.OneDimension;

import java.util.Arrays;

public class medianOfTwoArrays {

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] mergedArray = mergeArray(nums1, nums2);
        int sizeOfArray = mergedArray.length;
        int mid = (mergedArray.length -1) / 2;
        mid = Math.abs(mid);
        double ans = 0.0;
        if((sizeOfArray & 1)  == 1){
            ans = (double)(mergedArray[mid] + mergedArray[mid + 1]) / 2;
        }else{
            ans = (double)mergedArray[mid];
        }
        return ans;
    }

    public static int[] mergeArray(int[] nums1, int[] nums2){
        int[] mArray = new int[nums1.length + nums2.length];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < nums1.length){
            mArray[k++] = nums1[i++];
        }

        while(j < nums2.length){
            mArray[k++] = nums2[j++];

        }
        Arrays.sort(mArray);
        return mArray;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2};
        int[] nums2 = {3, 4};

        System.out.println(findMedianSortedArrays(nums1, nums2));
    }
}
