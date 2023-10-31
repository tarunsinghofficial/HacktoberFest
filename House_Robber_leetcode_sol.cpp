class Solution {
public:
    int dp[105];
    int solve(vector<int> &v,int i){
        if(i>=v.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]= max(solve(v,i+1),solve(v,i+2)+v[i]);
       
    }
    int rob(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
       return  solve(v,0);
         
    }
};

// dp
class Solution {
public:
    
    int rob(vector<int>& v) {
        int n=v.size();
       int dp[n+1];
        dp[n-1]=v[n-1];
        dp[n]=0;
        for(int i=n-2;i>=0;i--){
            dp[i]=max(v[i]+dp[i+2],dp[i+1]);
        }
         return dp[0];
    }
};
