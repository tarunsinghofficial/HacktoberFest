// https://leetcode.com/problems/sort-colors/

// or

// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Method 1:
        //sort(nums.begin(), nums.end());
        
        
        // Method 2:
        
        /*
        int n = (int)nums.size();
        
        int f=0, s=0,t=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                f++;
            else if(nums[i]==1)
                s++;
            else
                t++;
        }
        
        for(int i=0;i<f;i++){
            nums[i]=0;
        }
        for(int i=f;i<f+s;i++){
            nums[i]=1;
        }
        for(int i=f+s;i<f+s+t;i++){
            nums[i]=2;
        }
        
        */
        
        
        // Method 3:
        
        int l=0;
        int m=0;
        int h=n-1;
        
        while(m<=h){
            int x = nums[m];
            if(x==0){
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if(x==1){
                m++;
            }
            else{
                swap(nums[h], nums[m]);
                h--;
            }
        }
        
    }
};
















