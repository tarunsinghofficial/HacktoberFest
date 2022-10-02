#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,source;
    cin >> n >> m;
    int u,v,w;
    vector <pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> source;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector <int> dis(n+1,INT_MAX);
    pq.push({0,source});
    dis[source] = 0;
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for(auto &it:adj[prev]){
            int next = it.first;
            int nextDis = it.second;
            if(nextDis + dist < dis[next]){
                dis[next] = dist + nextDis; 
                pq.push({dis[next],next});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dis[i] << " ";
    }
    return 0;
}

// 3 3
// 1 2 2
// 2 3 4
// 1 3 1
// 1
