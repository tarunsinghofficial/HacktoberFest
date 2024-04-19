#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void input(vector<vector<int>> &adj, int &n)
{
    cin >> n;
    vector<vector<int>> tmp(n + 1);
    int e, u, v;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        tmp[u].push_back(v);
    }
    adj = tmp;
    tmp.clear();
    return;
}

bool isCycle(vector<vector<int>> adjacent, int n)
{
    vector<int> vis(n + 1, 0), indeg(n + 1, 0), ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adjacent[i].size(); j++)
        {
            int frnd = adjacent[i][j];
            indeg[frnd]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!indeg[i])
        {
            q.push(i);
            // vis[i] = 1;
        }
    }

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        ans.push_back(tmp);
        for (auto frnd : adjacent[tmp])
        {
            // if (indeg[frnd] > 0)
            indeg[frnd]--;
            if (!indeg[frnd])
            {
                q.push(frnd);
                // vis[frnd] = 1;
            }
        }
    }
    if (ans.size() == n)
        return false;
    // else:-
    return true; // cycle is there
}

int main(void)
{
    int n;
    vector<vector<int>> adj;
    input(adj, n);
    if (isCycle(adj, n))
        cout << "Cycle Detected";
    else
        cout << "No Cycle Detected";
    return 0;
}