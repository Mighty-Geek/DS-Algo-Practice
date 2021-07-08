#include <iostream>
#include <vector>
using namespace std;

bool targetSumSubsets(vector<int> input_arr, int target)
{
    int size = input_arr.size();
    vector<vector<bool>> dp(size + 1, vector<bool>(target + 1, false));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            // first cell
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            // first row: sum for empty subset
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            // first column: sum for subsets=0
            else if (j == 0)
            {
                dp[i][j] = true;
            }
            // rest
            else
            {
                // did the subset prior to including me was making sum=j
                if (dp[i - 1][j] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    // value contributed by new element at (i, j)
                    int val = input_arr[i - 1];
                    if (j >= val && dp[i - 1][j - val] == true)
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }
    }
    return dp[size][target];
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    int target;
    cin >> target;
    cout << boolalpha << targetSumSubsets(arr, target) << endl;
    return 0;
}
