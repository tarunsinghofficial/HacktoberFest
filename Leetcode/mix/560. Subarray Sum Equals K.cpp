/*
560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
Accepted

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numsSize = (int) nums.size();
        int count = 0;
        unordered_map<int,int> prevval;
        int sum = 0;
        for(int i=0; i<numsSize; i++){
            sum+=nums[i];
            
            if(sum == k){
                count++;
            }
            
            if(prevval.find(sum-k) != prevval.end()){
                count+=prevval[sum-k];
            }
            prevval[sum]++;
        }
        return sum;
    }
};