#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int w;
    node(int first, int second, int weight)
    {
        u=first;
        v=second;
        w=weight;
    }
};
bool comp(node a,node b)
{
    return a.w<b.w;
}
int find_parent(int vertex,vector<int> &parent)
{
    if(parent[vertex]==vertex) return vertex;
    return parent[vertex]=find_parent(parent[vertex],parent);
}
void unionn(int u, int v,vector<int> &parent,vector<int> &rank)
{
  u=find_parent(u,parent);
  v=find_parent(v,parent);
  if(rank[u]<rank[v])
      {
         parent[u]=v;
      }
      else if(rank[v]<rank[u])
      {
          parent[v]=u;
      }
      else
      {
         parent[v]=u;
         rank[u]++;
      }
}
int main()
{
    int n,m; cin>>n>>m;
    vector<int> parent;
    vector<int> rank(n,0);
    vector<pair<int,int>> mst;
    int cost=0;
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    vector<node> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }
    sort(edges.begin(),edges.end(),comp);
    for(node x: edges)
    {
        if(find_parent(x.u,parent)!=find_parent(x.v,parent))
        {
            unionn(x.u,x.v,parent,rank);
            mst.push_back({x.u,x.v});
            cost=cost+x.w; 
        }
    }
    cout<<"cost of mst is "<<cost<<endl;
    for(int i=0;i<n-1;i++) cout<<mst[i].first<<"-----"<<mst[i].second<<endl;
}
