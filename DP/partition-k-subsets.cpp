#include <iostream>
using namespace std;

void partitionKSubsets(int n, int k)
{
    if (n == 0 || k == 0 || n < k)
    {
        cout << 0 << endl;
        return;
    }
    long dp[k + 1][n + 1];
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] * i;
        }
    }
    cout << dp[k][n] << endl;
}
int main()
{
    int n, k;
    cin >> n >> k;
    partitionKSubsets(n, k);
    return 0;
}