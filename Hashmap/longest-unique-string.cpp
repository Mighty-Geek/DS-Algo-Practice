#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

// string longestSubstr(string s)
// {
//     int n = s.length();
//     unordered_map<char, int> pos;
//     int start = 0;
//     int curr_len;
//     int max_len = 0;
//     int start_index;
//     pos[s[0]] = 0;
//     int i;
//     for (i = 1; i < n; i++)
//     {
//         if (pos.find(s[i]) == pos.end())
//             pos[s[i]] = i;
//         else
//         {
//             if (pos[s[i]] >= start)
//             {
//                 curr_len = i - start;
//                 if (max_len < curr_len)
//                 {
//                     max_len = curr_len;
//                     start_index = start;
//                 }
//                 start = pos[s[i]] + 1;
//             }
//             pos[s[i]] = i;
//         }
//     }
//     if (max_len < i - start)
//     {
//         max_len = i - start;
//         start_index = start;
//     }
//     return s.substr(start_index, max_len);
// }

string solution(string s)
{
    int ans = 0;
    unordered_map<char, int> map;
    int l = s.length();
    int i = -1, j = -1;
    bool flag = true;
    int start = -1;

    while (flag)
    {
        bool f1 = false, f2 = false;
        while (i < l)
        {
            // acquire
            f1 = true;
            i++;
            map[s[i]]++;
            if (map[s[i]] == 2)
            {
                break;
            }
            else
            {
                int len = i - j;
                if (len > ans)
                {
                    ans = len;
                    start = j + 1;
                }
            }
        }
        while (j < i)
        {
            // release
            f2 = true;
            j++;
            map[s[j]]--;
            if (map[s[j]] == 1)
                break;
        }
        if (f1 == false && f2 == false)
            break;
    }
    cout << "length : " << ans;
    return s.substr(start, ans);
}

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    unordered_map<char, int> map;
    int i = 0;
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, map[s[j]] + 1);
        res = max(res, j - i + 1);
        map[s[j]] = j;
    }
    return res;
}

int main()
{
    string str;
    cin >> str;
    cout << solution(str) << endl;
    cout << lengthOfLongestSubstring(str);
    return 0;
}