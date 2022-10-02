#include<bits/stdc++.h>

using namespace std;
const int INF = 10e5;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++){
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({u, v, w});
    }
    int src;
    cin >> src;
    vector<int> dist(n, INF);
    dist[src] = 0;
    for(int iter = 0; iter < n - 1; iter++){
      bool change = false;
      for(auto e :edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(dist[u] > w + dist[u]){
          change = true;
          break;
        }
        dist[v] = min(dist[v], w + dist[u]);
      }
      if(change){
        cout << "cycle detected in the graph" << endl;
        break;
      }
      else cout << "no negative waight cycle is found " << endl;
    }
    for(auto i : dist){
      cout << i << " ";
    }
    cout << endl;
}
