/*

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.
 

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?

*/

// Solution 1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

// Solution 2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int si = nums.size();
        int f = 0; int s = 0;
        int t = 0;
        for(int i=0; i<si; i++){
            if(nums[i] == 1){
                f++;
            }else if(nums[i] == 2){
                s++;
            }else{
                t++;
            }
        }
        for(int i=0; i<f;i++){
            nums[i] = 0;
        }
        for(int  i=f; i<f+s; i++){
            nums[i] = 1;
        }
        for(int i=f+s; i<f+s+t; i++){
            nums[i] = 2;
        }
    }
};

// solution 3



