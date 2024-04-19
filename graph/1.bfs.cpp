#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph (n);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << endl;
    for(int i : graph[node]){
      if(!visited[i]){
        visited[i] = true;
        q.push(i);
      }
    }
  }
  return 0;
}
