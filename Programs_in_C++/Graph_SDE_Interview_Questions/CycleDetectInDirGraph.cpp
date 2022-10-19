#include <iostream>
#include <vector>
using namespace std;

pair<vector<vector<int>>, int> input()
{
    int n, e, u, v;
    cin >> n >> e;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    return {adj, n};
}
// DFS way :-
bool isCyclic(vector<vector<int>> adj, vector<int> &vis, int node, int caller)
{
    vis[node] = 1;
    for (auto frnd : adj[node])
    {
        if (!vis[frnd])
        {
            if (isCyclic(adj, vis, frnd, node))
                return true;
        }
        else
            return true;
        // else if (frnd != caller) return true;  // -> this is stricter checking, needed if bi-directional edges exist
    }
    return false;
}

bool cycleDetect(vector<vector<int>> adj, int n)
{
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCyclic(adj, vis, i, -1))
                return true;
        }
    }
    return false;
}

int main(void)
{
    pair<vector<vector<int>>, int> p = input();
    vector<vector<int>> adj = p.first;
    int n = p.second;
    // input done

    if (cycleDetect(adj, n))
        cout << "Cycle Present";
    else
        cout << "No Cycle Present";

    return 0;
}