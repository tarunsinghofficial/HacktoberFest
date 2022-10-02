#include<bits/stdc++.h>

using namespace std;

int get_comp(int idx, vector<vector<int>> &adj, vector<bool> &vis){
  if(vis[idx]) return 0;
  vis[idx] = true;
  int ans = 1;
  for(auto i : adj[idx]){
    if(!vis[i]){
      ans += get_comp(i, adj, vis);
      vis[i] = true;
    }
  }
  return ans;
}

int main(){
  int m, n;
  cin >> m >> n;
  vector<vector<int>> adj(m, vector<int>());
  vector<bool> vis(n, false);
  vector<int> components;
  for(int i = 0; i < n; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0; i < n; i++){
    if(!vis[i]){
      components.push_back(get_comp(i, adj, vis));
    }
  }
  for(auto i : components){
    cout << i << " ";
  }
  return 0;
}
