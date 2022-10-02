#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,const vector<vector<int> >& graph, vector<bool>& visited){
    // preorder
    visited[node] = true;
    cout << node << " ";
    for(int i : graph[node]){
      if(!visited[i]){
        dfs(i, graph, visited);
      }
    }
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<bool> visited(n);
  dfs(0, graph, visited);
}
