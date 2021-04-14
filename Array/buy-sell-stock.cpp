#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int profit = 0;
    int max_profit = 0;

    if (n == 0)
        return 0;
    int min_price = prices[0];

    for (int i = 0; i < n; i++)
    {
        min_price = min(min_price, prices[i]);
        profit = prices[i] - min_price;
        max_profit = max(max_profit, profit);
    }
    return max_profit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        prices.push_back(data);
    }
    cout << maxProfit(prices);
    return 0;
}