#include <iostream>
#include <vector>
using namespace std;

// TC: O(n) Extra Space: O(n)
long paintFence(int n, int k)
{
    vector<long> dp(n + 1);
    long last_same = 0;
    long last_diff = k;
    dp[1] = last_same + last_diff;
    for (int i = 2; i < n + 1; i++)
    {
        last_same = last_diff;
        last_diff = dp[i - 1] * (k - 1);
        dp[i] = last_same + last_diff;
    }
    return dp[n];
}

// TC: O(n) Extra Space: O(1)
long paintFence(int n, int k)
{
    long last_same = k;
    long last_diff = k * (k - 1);
    for (int i = 2; i < n + 1; i++)
    {
        long new_last_same = last_diff;
        long new_last_diff = (last_same + last_diff) * (k - 1);

        last_same = new_last_same;
        last_diff = new_last_diff;
    }
    return (last_same + last_diff);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << paintFence(n, k) << endl;
    return 0;
}
