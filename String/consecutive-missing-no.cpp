#include <iostream>
#include <math.h>
using namespace std;
const int MAX_DIGITS = 6;

int getValue(const string &s, int i, int m)
{
    if (i + m > s.length())
        return -1;

    int val = 0;
    for (int j = 0; j < m; j++)
    {
        int c = s[i + j] - '0';
        if (c < 0 || c > 9)
            return -1;
        val = val * 10 + c;
    }
    return val;
}
int findMissingNumber(const string &s)
{
    for (int m = 1; m < MAX_DIGITS; ++m)
    {
        int n = getValue(s, 0, m);
        if (n == -1)
            break;

        int missing_no = -1;
        bool fail = false;

        for (int i = m; i != s.length(); i += 1 + log10l(n))
        {
            if ((missing_no == -1) && (getValue(s, i, 1 + log10l(n + 2)) == n + 2))
            {
                missing_no = n + 1;
                n += 2;
            }
            else if (getValue(s, i, 1 + log10l(n + 1)) == n + 1)
                n++;
            else
            {
                fail = true;
                break;
            }
        }
        if (!fail)
            return missing_no;
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << findMissingNumber(str) << endl;
    }
    return 0;
}
