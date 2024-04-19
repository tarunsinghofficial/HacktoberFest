#include<bits/stdc++.h>
#define N 1000003
using namespace std;

vector<bool> vis(N);
vector<vector<int> > g[N];
int cost =0;
vector<int> dist(N);
vector<int> parent(N);
const int INF = 1e9;

void primsMST(int src){
  set<vector<int>> s;
  dist[src] = 0;
  s.insert({0, src});
  while(!s.empty()){
    auto x = *(s.begin());
    s.erase(x);
    vis[x[1]] = true;
    int u = x[1];
    int v = parent[x[1]];
    int w = x[0];
    cout << u << " " << v << " " << w << endl;
    cost += w;
    for(auto it : g[x[1]]){
      if(vis[it[0]]) continue;
      if(dist[it[0]] > it[1]){
        s.erase({dist[it[0]], it[0]});
        dist[it[0]] = it[1];
        s.insert({dist[it[0]], it[0]});
        parent[it[0]] = x[1];
      }
    }
  }
}
int main(){
  int n, m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
  for(int i =0; i < m; i++){
    dist[i] = INF;
  }
  primsMST(0);
  cout << cost << endl;
}
