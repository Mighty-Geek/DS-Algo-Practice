#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

string longestSubstr(string s)
{
    int n = s.length();
    unordered_map<char, int> pos;
    int start = 0;
    int curr_len;
    int max_len = 0;
    int start_index;
    pos[s[0]] = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if (pos.find(s[i]) == pos.end())
            pos[s[i]] = i;
        else
        {
            if (pos[s[i]] >= start)
            {
                curr_len = i - start;
                if (max_len < curr_len)
                {
                    max_len = curr_len;
                    start_index = start;
                }
                start = pos[s[i]] + 1;
            }
            pos[s[i]] = i;
        }
    }
    if (max_len < i - start)
    {
        max_len = i - start;
        start_index = start;
    }
    return s.substr(start_index, max_len);
}

int main()
{
    string str;
    cin >> str;
    cout << longestSubstr(str) << endl;
    return 0;
}