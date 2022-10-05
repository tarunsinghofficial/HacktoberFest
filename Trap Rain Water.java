class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int left[] = new int[n];
        int right[] = new int[n];
        int max = 0;
      
        //left
        for(int i=0;i<n;i++){
            max = Math.max(max, height[i]);
            left[i] = max;
        }
        
        max = 0;
        //right
        for(int i=n-1;i>=0;i--){
            max = Math.max(max, height[i]);
            right[i] = max;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int min = Math.min(left[i],right[i]);
            ans += min - height[i];
        }
        return ans;
    }
}
