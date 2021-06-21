#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// approach 1: checking all subarrays for distinct elements T(n): O(n^2)
// approach 2: hashmap-acquire/release T(n): O(n^2)

// appraoch 3: sliding window
int solution(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[nums[i]] = 1;

    int dist = map.size();
    map.clear();

    int count = 0, right = 0, window = 0;
    for (int left = 0; left < n; ++left)
    {
        while (right < n && window < dist)
        {
            ++map[nums[right]];
            if (map[nums[right]] == 1)
                ++window;
            ++right;
        }
        if (window == dist)
            count += (n - right + 1);
        --map[nums[left]];
        if (map[nums[left]] == 0)
            --window;
    }
    return count;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    cout << solution(nums);
    return 0;
}
