#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            // last cell
            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = grid[i][j];
            }
            // last row
            else if (i == n - 1)
            {
                dp[i][j] = dp[i][j + 1] + grid[i][j];
            }
            // last column
            else if (j == m - 1)
            {
                dp[i][j] = dp[i + 1][j] + grid[i][j];
            }
            // rest of matrix
            else
            {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> nums(r);
    for (int i = 0; i < r; i++)
    {
        nums[i].assign(c, 0);
        for (int j = 0; j < c; j++)
        {
            cin >> nums[i][j];
        }
    }
    cout << minPathSum(nums) << endl;
    return 0;
}