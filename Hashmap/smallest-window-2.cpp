// smallest window containing all characters of yourself

#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

/*
// not the best solution since time complexity : O(n^2)
string smallestDistinct(string s)
{
    unordered_map<char, int> map;
    string res;
    int count = 0;
    int ans = INT_MAX;
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
    }
    count = map.size();
    for (int i = 0; i < s.length(); i++)
    {
        int c = 0;
        int visited[256] = {0};
        string sub_str = "";
        for (int j = i; j < s.length(); j++)
        {
            if (visited[s[j]] == 0)
            {
                c++;
                visited[s[j]] = 1;
            }
            sub_str += s[j];
            if (c == count)
                break;
        }
        if (sub_str.length() < ans && c == count)
        {
            res = sub_str;
            ans = sub_str.length();
        }
    }
    return res;
}
*/

// sliding window : time complexity = O(n)
string smallestDistinct(string s)
{
    int n = s.length();
    int visited[256] = {0};
    int c = 0; // no. of distinct characters
    for (int i = 0; i < n; i++)
    {
        if (visited[s[i]] == 0)
        {
            c++;
            visited[s[i]] = 1;
        }
    }
    int start = 0, start_index = -1, min_len = INT_MAX;
    int counter = 0;
    int curr_count[256] = {0};
    for (int j = 0; j < n; j++)
    {
        curr_count[s[j]]++;
        if (curr_count[s[j]] == 1)
            counter++;
        if (counter == c)
        {
            while (curr_count[s[start]] > 1)
            {
                if (curr_count[s[start]] > 1)
                    curr_count[s[start]]--;
                start++;
            }
            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    return s.substr(start_index, min_len);
}
int main()
{
    string str;
    cin >> str;

    string res = smallestDistinct(str);
    cout << res << endl;
    return 0;
}