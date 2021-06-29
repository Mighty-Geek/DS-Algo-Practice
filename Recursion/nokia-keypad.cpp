#include <iostream>
#include <vector>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
vector<string> kpc(string s)
{
    int n = s.length();
    if (s == "")
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> res;
    char first = s[0];
    string rest = s.substr(1, n - 1);
    vector<string> rec_res = kpc(rest);

    string codesforfirst = codes[first - '0'];
    for (int i = 0; i < codesforfirst.length(); i++)
    {
        char first_ch = codesforfirst[i];
        for (string itr : rec_res)
        {
            res.push_back(first_ch + itr);
        }
    }
    return res;
}

int main()
{
    string str;
    cin >> str;
    vector<string> res = kpc(str);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ",";
    }
    cout << res[res.size() - 1];
    cout << "]";
    return 0;
}