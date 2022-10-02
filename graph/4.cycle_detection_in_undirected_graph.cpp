#include<iostream>
#include<vector>
using namespace std;

bool isCycle(int src,const vector<vector<int> > &graph, vector<bool> &visited, int parent){
  visited[src] = true;
  for(auto i : graph[src]){
    if(i != parent){
      if(visited[i]) return true;
      if(!visited[i] and isCycle(i, graph, visited, src)){
        return true;
      }
    }
  }
  return false;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  bool cycle = false;
  vector<bool> visited(n, false);
  for(int i = 0; i < n; i++){
    if(cycle) break;
    if(!visited[i] and isCycle(i, graph, visited, -1)) cycle = true;
    else cycle = false;
  }
  if(cycle){
    cout << "cycle is present in graph" << endl;
  }else{
    cout << "cycle not present in graph" << endl;
  }
  return 0;
}
