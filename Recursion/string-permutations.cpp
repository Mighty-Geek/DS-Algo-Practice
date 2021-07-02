#include <iostream>
using namespace std;

void permute(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << " ";
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_rest = s.substr(0, i);
        string right_rest = s.substr(i + 1);
        string rest = left_rest + right_rest;
        permute(rest, ans + ch);
    }
}
int main()
{
    string str;
    cin >> str;
    permute(str, "");
    return 0;
}