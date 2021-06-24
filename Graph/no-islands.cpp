// dfs, bfs, disjoint set [connected components]

#include <iostream>
#include <vector>
using namespace std;

// dfs - to find connected components

void drawTreeForComponent(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited)
{
    visited[i][j] = true;

    if (i + 1 < grid.size() && grid[i + 1][j] == '1' && visited[i + 1][j] == false)
        drawTreeForComponent(grid, i + 1, j, visited);
    if (j + 1 < grid[0].size() && grid[i][j + 1] == '1' && visited[i][j + 1] == false)
        drawTreeForComponent(grid, i, j + 1, visited);
    if (i - 1 >= 0 && grid[i - 1][j] == '1' && visited[i - 1][j] == false)
        drawTreeForComponent(grid, i - 1, j, visited);
    if (j - 1 >= 0 && grid[i][j - 1] == '1' && visited[i][j - 1] == false)
        drawTreeForComponent(grid, i, j - 1, visited);
}

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1' && visited[i][j] == false)
            {
                drawTreeForComponent(grid, i, j, visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> mat;
    char input;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < m; j++)
        {
            cin >> input;
            row.push_back(input);
        }
        mat.push_back(row);
    }
    cout << numIslands(mat) << endl;
    return 0;
}