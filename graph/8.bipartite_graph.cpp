#include<bits/stdc++.h>

using namespace std;

void color(int u, int curr, vector<vector<int>> &adj, vector<int>& col, vector<bool> & vis, bool &bipart){
  if(col[u] != -1 and col[u] != curr){
    bipart = false;
    return;
  }
  col[u] = curr;
  if(vis[u]) return;
  vis[u] = true;
  for(auto i :  adj[u]){
    color(i, curr ^ 1, adj, col, vis, bipart);
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<bool> vis(n, false);
  vector<int> col(n, -1);
  bool bipart = true;
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0; i < n; i++){
    if(!vis[i]) color(i, 0,adj, col, vis, bipart);
  }
  if(bipart)
    cout << "graph is biparted" << endl;
  else
    cout << "graph is not biparted" << endl;
}
