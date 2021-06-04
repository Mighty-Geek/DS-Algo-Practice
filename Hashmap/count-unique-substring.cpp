// count all substrings with unique characters

#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int countUniqueSubstr(string s)
{
    int n = s.length();
    int i = -1, j = -1;
    int count = 0;
    unordered_map<char, int> map;
    bool flag = true;
    while (flag)
    {
        bool f_acquire = false, f_release = false;
        while (i < n - 1)
        {
            f_acquire = true;
            i++;
            map[s[i]]++;
            if (map[s[i]] == 2)
                break;
            else
                count += i - j;
        }
        while (j < i)
        {
            f_release = true;
            j++;
            map[s[j]]--;
            if (map[s[j]] == 1)
            {
                count += i - j;
                break;
            }
        }
        if (f_acquire == false && f_release == false)
        {
            flag = false;
        }
    }
    return count;
}
int main()
{
    string str;
    cin >> str;
    cout << "Count is :\t" << countUniqueSubstr(str);
    return 0;
}