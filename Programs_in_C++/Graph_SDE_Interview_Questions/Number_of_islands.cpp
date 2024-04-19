#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input(int &r, int &c)
{
    cin >> r >> c;
    vector<vector<int>> vec(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> vec[i][j];
    return vec;
}

void dfs(vector<vector<int>> adj_mat, vector<vector<int>> &not_vis, int x, int y)
{
    not_vis[x][y] = 0; // so that next time, no one enters this cell again
    int r = adj_mat.size(), c = adj_mat[0].size();

    /*
        // left friend
        if ((y - 1) >= 0 && not_vis[x][y - 1] == 1)
            dfs(adj_mat, not_vis, x, y - 1);
        // top friend
        if ((x - 1) >= 0 && not_vis[x - 1][y] == 1)
            dfs(adj_mat, not_vis, x - 1, y);
        // right friend
        if ((y + 1) < c && not_vis[x][y + 1] == 1)
            dfs(adj_mat, not_vis, x, y + 1);
        // down friend
        if ((x + 1) < r && not_vis[x + 1][y] == 1)
            dfs(adj_mat, not_vis, x + 1, y);
    */

    // saves time :-

    int x_mask[4] = {0, -1, 0, 1};
    int y_mask[4] = {-1, 0, 1, 0};

    int p, q;

    for (int i = 0; i < 4; i++)
    {
        p = x + x_mask[i];
        q = y + y_mask[i];
        if (p >= 0 && p < r && q >= 0 && q < c && not_vis[p][q] == 1)
            dfs(adj_mat, not_vis, p, q);
    }

    return;
}

int cntIslands(vector<vector<int>> adj_mat)
{
    vector<vector<int>> not_vis = adj_mat;
    int n_islands = 0, rows = adj_mat.size(), cols = adj_mat[0].size();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            // search for landmass
            if (not_vis[i][j])
            {
                dfs(adj_mat, not_vis, i, j);
                n_islands++;
            }
        }
    return n_islands;
}

int main(void)
{
    // input
    int rows, cols;
    vector<vector<int>> adj_mat = input(rows, cols);

    int ans = cntIslands(adj_mat);

    cout << ans;

    return 0;
}