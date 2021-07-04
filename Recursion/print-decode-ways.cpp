#include <iostream>
using namespace std;

void printEncodings(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    else if (s.length() == 1)
    {
        char ch = s[0];
        if (ch == '0')
            return;
        else
        {
            int ch_val = ch - '0';
            char code = (char)('a' + ch_val - 1);
            ans = ans + code;
            cout << ans << endl;
        }
    }
    else
    {
        char ch = s[0];
        string rest = s.substr(1);

        if (ch == '0')
            return;
        else
        {
            int ch_val = ch - '0';
            char code = (char)('a' + ch_val - 1);
            printEncodings(rest, ans + code);
        }

        string ch12 = s.substr(0, 2);
        string rest2 = s.substr(2);

        int ch12_val = stoi(ch12);
        if (ch12_val <= 26)
        {
            char code = (char)('a' + ch12_val - 1);
            printEncodings(rest2, ans + code);
        }
    }
}
int main()
{
    string str;
    cin >> str;
    printEncodings(str, "");
    return 0;
}