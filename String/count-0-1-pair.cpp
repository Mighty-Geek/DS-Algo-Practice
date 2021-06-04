#include <iostream>
using namespace std;

int findPairCount(string s)
{
    int i = 0;
    int count = 0;
    int n = s.length();
    int cnt_1 = 0, cnt_0 = 0;
    while (i < n)
    {
        if (s[i] == '0')
            cnt_0++;
        else
            cnt_1++;
        if (cnt_0 == cnt_1)
        {
            count++;
            cnt_1 = cnt_0 = 0;
        }
        i++;
    }
    return count;
}

int main()
{
    string str;
    cin >> str;
    cout << findPairCount(str);
    return 0;
}