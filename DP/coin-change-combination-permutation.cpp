#include <iostream>
#include <vector>
using namespace std;

int coinCombination(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int i = 1; i < dp.size(); i++)
        {
            if (i >= coin)
            {
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[amount];
}

int coinPermutation(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int coin : coins)
        {
            if (i >= coin)
            {
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[amount];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        coins.push_back(data);
    }
    int target;
    cin >> target;
    cout << coinCombination(coins, target) << endl;
    cout << coinPermutation(coins, target) << endl;
    return 0;
}