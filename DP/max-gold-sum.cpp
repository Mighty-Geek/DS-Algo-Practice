#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxGoldSum(vector<vector<int>> &nums)
{
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (j == m - 1)
            {
                dp[i][j] = nums[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = nums[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else if (i == n - 1)
            {
                dp[i][j] = nums[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            else
            {
                dp[i][j] = nums[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
            }
        }
    }
    int max_gold = dp[0][0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i][0] > max_gold)
            max_gold = dp[i][0];
    }
    return max_gold;
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
    cout << maxGoldSum(nums) << endl;
    return 0;
}