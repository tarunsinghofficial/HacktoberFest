/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

class Solution {
public:
    void reverse(vector<int>& num,int low,int high){
        while(low < high){
            swap(num[high],num[low]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        reverse(nums,0,n-k-1); 
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};