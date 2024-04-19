class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = nums.length, i=0;
        
        while(i<l){
            if(nums[i]==target)
                return i;
             if(nums[i]>target)
                return i;
            i++;
        }
        return l;
    }
}
