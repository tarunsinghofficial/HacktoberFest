class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length ;
        while(n >=3){
    int a = nums[n-3];
        int b = nums[n-2];
        int c = nums[n-1];
        if((a+b > c) && (a+c > b) && (b+c >a))
        {
             return a+b+c ;
        }
            n-=1 ;
        }
        return  0 ;
    }
}
