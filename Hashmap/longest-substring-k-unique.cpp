#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

string findLongestSubstr(string s, int k)
{
    int n = s.length();
    int i = -1, j = -1;
    string res;
    int start = 0;
    int max_len = INT_MIN;
    unordered_map<char, int> map;
    while (true)
    {
        bool f1 = false, f2 = false;
        while (i < n - 1)
        {
            f1 = true;
            i++;
            map[s[i]]++;
            if (map.size() < k)
            {
                res = "-1";
                continue;
            }
            else if (map.size() == k)
            {
                int curr_len = i - j;
                if (curr_len > max_len)
                {
                    max_len = curr_len;
                    start = j + 1;
                    res = s.substr(start, max_len);
                }
            }
            else
                break;
        }
        while (j < i)
        {
            f2 = true;
            j++;
            // release
            if (map[s[j]] == 1)
                map.erase(s[j]);
            else
                map[s[j]]--;

            // check
            if (map.size() > k)
                continue;
            else if (map.size() == k)
                break;
        }
        if (f1 == false && f2 == false)
            break;
    }
    return res;
}

int main()
{
    string str;
    int k;
    cin >> str >> k;
    cout << findLongestSubstr(str, k);
    return 0;
}