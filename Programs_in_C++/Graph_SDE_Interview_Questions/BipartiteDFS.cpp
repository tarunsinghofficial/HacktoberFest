#include <iostream>
#include <vector>
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

bool isBipartite(unordered_map<int, vector<int>> adj, unordered_map<int, int> &vis, int node, int parent_color)
{
    vis[node] = (-1) * parent_color; // mark current node as visited and colour it with opposite of parent's colour
    // now, traverse among the friends of node
    for (auto frnd : adj[node])
    {
        if (!vis[frnd])
        { // i.e. new friend
            if (!isBipartite(adj, vis, frnd, vis[node]))
                return false;
        }
        else if (vis[frnd] == vis[node])
        { // if curr node has same color as that of friend node
            return false;
        }
    }
    return true;
}
// This function uses DFS to check if a graph is Bipartite or not (i.e. can it be coloured using <=2 colours):-
void detectBipartite(unordered_map<int, vector<int>> adj)
{
    int n = adj.size(); // no. of vertices
    unordered_map<int, int> vis;
    for (auto x : adj)
    {
        int ver = x.first;
        if (vis.find(ver) == vis.end())
        {
            if (!isBipartite(adj, vis, ver, -1))
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