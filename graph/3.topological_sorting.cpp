#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<int> indegree(n, 0);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    indegree[v]++;
  }
  queue<int> pq;
  for(int i = 0; i < n; i++){
    if(indegree[i] == 0){
      pq.push(i);
    }
  }
  while(!pq.empty()){
    int x = pq.front();
    pq.pop();
    cout << x << endl;
    for(auto it: graph[x]){
      indegree[it]--;
      if(indegree[it] == 0)
        pq.push(it);
    }
  }
  return 0;
}
