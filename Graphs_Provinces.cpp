There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

class Solution {
public:
    vector<int> ad[205];
    bool vis[205];
    void dfs(int node){
        vis[node]=1;
        for(int i=0;i<ad[node].size();i++){
            if(vis[ad[node][i]]==0){
                dfs(ad[node][i]);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    ad[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i);
                ans++;
            }
        }
          return ans;
    }
};
