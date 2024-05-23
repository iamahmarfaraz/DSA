#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

void dfsIsland(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
    {
        return;
    }
    grid[i][j] = '-';
    // Mark Left
    dfsIsland(grid, i, j - 1);
    // Mark Right
    dfsIsland(grid, i, j + 1);
    // Mark Upside
    dfsIsland(grid, i - 1, j);
    // Mark DownSide
    dfsIsland(grid, i + 1, j);
}
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                dfsIsland(grid, i, j);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        { '1', '1', '0', '1', '0' },
        { '1', '1', '0', '0', '0' },
        { '0', '0', '0', '0', '0' }
    };
    int ans = numIslands(grid);
    cout<<"No. Of Island Present : "<<ans<<endl<<endl;
    return 0;
}