#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dfs(vector<vector<int>> grid, vector<vector<int>> &cpy, int x, int y, int newCol)
{
    cpy[x][y] = newCol;
    int x_mask[4] = {-1, 0, 1, 0};
    int y_mask[4] = {0, 1, 0, -1};

    int r = cpy.size(), c = cpy[0].size();

    for (int i = 0; i < 4; i++)
    {
        int p = x + x_mask[i];
        int q = y + y_mask[i];
        if (p >= 0 && p < r && q >= 0 && q < c && cpy[p][q] == grid[p][q] && grid[p][q] == grid[x][y])
            dfs(grid, cpy, p, q, newCol);
    }
    return cpy;
}

vector<vector<int>> floodFill(vector<vector<int>> grid, int sr, int sc, int newCol)
{
    int currColor = grid[sr][sc];
    vector<vector<int>> cpy = grid;
    return dfs(grid, cpy, sr, sc, newCol);
}

int main(void)
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    int sr, sc, newCol;
    cin >> sr >> sc >> newCol;
    sr--;
    sc--;

    vector<vector<int>> v = floodFill(grid, sr, sc, newCol);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << v[i][j] << " ";
        cout << '\n';
    }

    return 0;
}