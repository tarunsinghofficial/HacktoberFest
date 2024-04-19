#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void input(int &n, int &e, unordered_map<int, vector<int>> &adj)
{
    cin >> n >> e;
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return;
}

void print(vector<vector<int>> v)
{
    for (auto x : v)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
    return;
}

bool isValid(vector<vector<int>> vec, int x, int y)
{
    int r = vec.size(), c = vec[0].size();
    if (x >= 0 && y >= 0 && x < r && y < c)
        return true;
    return false;
}
// This function uses BFS to check if a graph is Bipartite or not (i.e. can it be coloured using <=2 colours):-
bool isBipartite(unordered_map<int, vector<int>> adj, unordered_map<int, int> &vis, int node)
{
    vis[node] = 1; // starting colour of the first node = 1 (assumed)
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto frnd : adj[curr])
        {
            if (!vis[frnd])
            {
                vis[frnd] = (-1) * vis[curr];
                q.push(frnd);
            }
            else if (vis[frnd] == vis[curr])
            { // if friends have same colour, then it's not a Bipartite Graph
                return false;
            }
        }
    }
    return true;
}

void detectBipartite(unordered_map<int, vector<int>> adj)
{
    int n = adj.size(); // no. of vertices
    unordered_map<int, int> vis;
    for (auto x : adj)
    {
        int ver = x.first;
        if (vis.find(ver) == vis.end())
        {
            if (!isBipartite(adj, vis, ver))
            {
                cout << "Not a Bipartite graph";
                return;
            }
            // this should not be here :-
            // else
            //     cout << "A Bipartite graph";
        }
    } // end for
    cout << "A Bipartite graph";
    return;
}

int main(void)
{
    int n, e;
    unordered_map<int, vector<int>> adj;
    input(n, e, adj);

    detectBipartite(adj);

    return 0;
}