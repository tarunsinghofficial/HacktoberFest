#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

void input(unordered_map<int, vector<int>> &adj, vector<int> &ver, int &n, int &e)
{
    int u, v;
    cin >> n >> e;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        ver.push_back(tmp);
    }
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return;
}

void print(vector<int> v)
{
    for (auto x : v)
        cout << x << ' ';
    return;
}

void dfsRec(unordered_map<int, vector<int>> adj, unordered_map<int, int> &vis, int current)
{
    vis[current] = 1;
    for (auto frnd : adj[current])
    {
        if (!vis[frnd])
        {
            dfsRec(adj, vis, frnd);
        }
    }
    return;
}

void dfsStk(unordered_map<int, vector<int>> adj, unordered_map<int, int> &vis, int current)
{
    // using stack and iteration
    stack<int> stk, tmp;
    stk.push(current);

    while (!stk.empty())
    {
        current = stk.top();
        stk.pop();
        for (auto frnd : adj[current])
        {
            if (!vis[frnd])
            {
                vis[frnd] = 1;
                tmp.push(frnd);
            }
        }
        // flipping the order of the friends in tmp stack to get original visiting sequence in dfs
        while (!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
        }
    }
    return;
}

void bfs(unordered_map<int, vector<int>> adj, unordered_map<int, int> &vis, int starter)
{
    vis[starter] = 1;
    queue<int> q;
    q.push(starter);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < adj[curr].size(); i++)
        {
            int frnd = adj[curr][i];
            if (!vis[frnd])
            {
                vis[frnd] = 1;
                q.push(frnd);
            }
        }
    }
    return;
}

int findConnPro(unordered_map<int, vector<int>> &adj, vector<int> vertices)
{
    unordered_map<int, int> vis;
    int counter = 0;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (!vis[vertices[i]])
        {
            // dfsRec(adj, vis, vertices[i]);
            // dfsStk(adj, vis, vertices[i]);
            bfs(adj, vis, vertices[i]);
            counter++;
        }
    }
    return counter;
}

int main(void)
{
    // input :-
    vector<int> vertices;
    int n, e;
    unordered_map<int, vector<int>> adj;
    input(adj, vertices, n, e);
    // vector<int> ans;
    // print(ans);
    int ans = findConnPro(adj, vertices);
    cout << ans;
    return 0;
}