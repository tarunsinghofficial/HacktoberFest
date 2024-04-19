#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void input(vector<vector<int>> &adj, int &n)
{
    int e;
    cin >> n >> e;
    vector<vector<int>> tmp(n + 1);
    adj = tmp;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return;
}

void topo_sort_bfs(vector<vector<int>> adj, vector<int> &ans)
{
    int n = adj.size() - 1;
    vector<int> vis(n + 1, 0), indeg(n + 1, 0);
    for (auto x : adj)
    {
        for (auto frnd : x)
        {
            indeg[frnd]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!indeg[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        ans.push_back(tmp);

        for (auto frnd : adj[tmp])
        {
            if (!vis[frnd])
            {
                indeg[frnd]--;
                if (!indeg[frnd])
                {
                    q.push(frnd);
                    vis[frnd] = 1;
                }
            }
        }
    }
    return;
}

int main(void)
{
    vector<vector<int>> adj;
    int n;
    input(adj, n);
    // cout << adj[1][0] << " " << adj[1][1];
    vector<int> ans;
    topo_sort_bfs(adj, ans);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
