#include<bits/stdc++.h>
#include<vector>

using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> components;
vector<bool> vis;
int get_comp(int idx){
	if(vis[idx]) return 0;
	vis[idx] = true;
	int ans = 1;
	for(auto i:adj[idx]){
		if(!vis[i]){
			ans+= get_comp(i);
			vis[i] = true;
		}
	}
	return ans;
}
int main(){
	cin >> n >> m;
	adj = vector<vector<int>>(n+1);
	vis = vector<bool>(n+1,0);
	for(int i =0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long ans = 0;
	for(int i =0;i<n;i++){
		if(!vis[i]){
			components.push_back(get_comp(i));
		}
	}
	for(auto i:components){
		ans += i*(n-1);
	}
	cout << (ans/2);
	return 0;
}
