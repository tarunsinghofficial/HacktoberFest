//https://leetcode.com/problems/single-number/



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = (int)nums.size();
        int a=0;
        for(int i=0;i<n;i++){
            //a= a^nums[i];
            a ^= nums[i];
        }
        return a;
    }
};
