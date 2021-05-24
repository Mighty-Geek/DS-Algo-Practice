#include <iostream>
#include <climits>
using namespace std;

// Solution using Hashmap
// Time complexity: O(m+n)
// Auxiliary space: O(m+n)
/*
const int no_of_chars = 256;

string findSubstr(string str, string pat)
{
    int i = 0;
    int l1 = str.length();
    int l2 = pat.length();

    if (l1 < l2)
    {
        cout << "[!]Attention :: no such window exists";
    }

    int hash_str[no_of_chars] = {0};
    int hash_pat[no_of_chars] = {0};

    // step to record frequency of char in t
    for (int i = 0; i < l2; i++)
    {
        hash_pat[pat[i]]++;
    }

    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0;
    for (int j = 0; j < l1; j++)
    {
        // step to record frequency of char in s
        hash_str[str[j]]++;

        // step to increment count if char in s and t match
        if (hash_str[str[j]] <= hash_pat[str[j]])
            count++;

        if (count == l2)
        {
            // step to release chars not required
            while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
            {
                if (hash_str[str[start]] > hash_pat[str[start]])
                    hash_str[str[start]]--;

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

    if (start_index == -1)
    {
        cout << "[!]Attention :: no such window exists";
        return "";
    }
    cout << "Minimum length : " << min_len;
    return str.substr(start_index, min_len);
}
*/
// Solution using sliding window
string findSubstr(string s, string t)
{
    int m[256] = {0};

    int ans = INT_MAX;
    int start = 0;
    int count = 0;

    for (int i = 0; i < t.length(); i++)
    {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    int i = 0, j = 0;
    while (j < s.length())
    {
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;
        if (count == 0)
        {
            while (count == 0)
            {
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}

int main()
{
    string str1;
    string str2;

    cin >> str1;
    cin >> str2;

    string res = findSubstr(str1, str2);

    cout << "Length of smallest window : \t" << res;
    return 0;
}
