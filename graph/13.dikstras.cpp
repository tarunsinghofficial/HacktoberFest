#include<bits/stdc++.h>

using namespace std;
const int INF= 1000007;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> dist(n + 1, INF);
  vector<vector<pair<int , int> > > graph(n + 1);
  for(int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, v});
  }
  int src;
  cin >> src;
  dist[src] = 0;
  set<pair<int , int>> s;
  s.insert({0, src});
  while(!s.empty()){
    auto x = *(s.begin());
    s.erase(x);
    for(auto it : graph[x.second]){
      if(dist[it.first] > dist[x.second] + it.second){
        dist[it.first] = dist[x.second] + it.second;
        s.insert({dist[it.first], it.first});
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(dist[i] < INF) cout << dist[i] << " ";
    else cout << "-1" << endl;
  }
  return 0;
}
