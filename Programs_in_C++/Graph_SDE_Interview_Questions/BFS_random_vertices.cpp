#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> input(vector<int> &vec)
{
    int n, e, u, v;
    cin >> n >> e;
    unordered_map<int, int> m;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        if (m.find(u) == m.end())
        {
            m[u] = 1;
            vec.push_back(u);
        }
        if (m.find(v) == m.end())
        {
            m[v] = 1;
            vec.push_back(v);
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // ignore this small jugaad
    adj[0].push_back(n);
    adj[0].push_back(e);
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

void bfs(unordered_map<int, vector<int>> adj, unordered_map<int, int> &vis, int start)
{
    vector<int> traversal;
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    traversal.push_back(start);
    while (!q.empty())
    {
        // travel in the friend list of current vertex
        int curr = q.front();
        q.pop();
        // for (auto frnd : adj[curr]) -> short cut
        for (int i = 0; i < adj[curr].size(); i++)
        {
            int frnd = adj[curr][i];
            if (vis[frnd])
                continue;
            // else:-
            vis[frnd] = 1;
            q.push(frnd);
            traversal.push_back(frnd);
        }
    }
    print(traversal);
    return;
}

int main(void)
{
    // input
    vector<int> vertices;
    unordered_map<int, vector<int>> adj = input(vertices);
    // ignore this small jugaad to get no. of vertices
    // and edges in main function from the helper function
    int n = adj[0][0];
    int e = adj[0][1];
    adj[0].clear();
    // ----------------
    // given : adjacency list and no. of vertices
    // to do : bfs traversal

    // Step-0 :-  for step-1, I need to make a visited array/vector before the loop
    // int vis[n + 1] = {0};
    unordered_map<int, int> vis;

    // Step-1 :- Traverse through all vertices
    // for (int i = 1; i <= n; i++)
    for (int i = 0; i < n; i++)
    {
        if (!vis[vertices[i]])
        {
            bfs(adj, vis, vertices[i]);
        }
    }

    return 0;
}