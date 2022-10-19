#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> input(vector<int> &ver, int &n, int &e)
{
    // int n, e, u, v;
    int u, v;
    cin >> n >> e;
    unordered_map<int, vector<int>> adj(n + 1);
    unordered_map<int, int> m;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        // storing unvisited(unique) vertices in vector : "ver"
        if (m.find(u) == m.end())
        {
            ver.push_back(u);
            m[u] = 1;
        }
        if (m.find(v) == m.end())
        {
            ver.push_back(v);
            m[v] = 1;
        }
    }
    // ignore this small jugaad
    // adj[0].push_back(n);
    // adj[0].push_back(e);
    // -----------------
    return adj;
}

void print(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    return;
}

void dfs(unordered_map<int, vector<int>> adj, unordered_map<int, int> &vis, int head, vector<int> &traversal)
{
    vis[head] = 1;
    stack<int> stk, tmp;
    stk.push(head);
    while (!stk.empty())
    {
        int current = stk.top();
        stk.pop();
        traversal.push_back(current);
        for (auto frnd : adj[current])
        {
            if (!vis[frnd])
            {
                tmp.push(frnd);
                vis[frnd] = 1;
            }
        }
        while (!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
        }
    }
    return;
}

int main(void)
{
    // input
    vector<int> vertices;
    int n, e;
    unordered_map<int, vector<int>> adj = input(vertices, n, e);
    // ignore this small jugaad to get no. of vertices
    // and edges in main function from the helper function
    // int n = adj[0][0];
    // int e = adj[0][1];
    // adj[0].clear();
    // ----------------
    // given : adjacency list and no. of vertices
    // to do : bfs traversal

    // Step-0 :-  for step-1, I need to make a visited array/vector before the loop
    // int vis[n + 1] = {0};
    unordered_map<int, int> vis;

    vector<int> ans;

    // Step-1 :- Traverse through all vertices
    for (int i = 0; i < n; i++)
    {
        if (!vis[vertices[i]])
        {
            dfs(adj, vis, vertices[i], ans);
        }
    }

    print(ans);

    return 0;
}