
// User function Template for Java

class Solution {
    int MissingNumber(int array[], int n) {
        // Your Code Here=
        int cnt=0;
        for(int i=0;i<array.length;i++){
            cnt+=array[i];
        }
        
        int tt=n*(n+1)/2;
        int res=tt-cnt;
        
        return res;
        
        
    }
}
