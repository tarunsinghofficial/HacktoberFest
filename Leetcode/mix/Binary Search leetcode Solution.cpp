// https://leetcode.com/problems/binary-search/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = (int)nums.size();
        
        int low = 0;
        int high = n-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target ){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return -1;
        
    }
};
