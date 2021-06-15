#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string customSort(string o, string &s)
{
    int count[26] = {0};
    string res = "";
    for (auto i : s)
    {
        count[i - 'a']++;
    }
    for (auto i : o)
    {
        res.append(count[i - 'a'], i);
        count[i - 'a'] = 0;
    }
    for (int i = 0; i < 26; i++)
        if (count[i] > 0)
            res.append(count[i], i + 'a');

    return res;
}

int main()
{
    string str, order;
    cin >> order >> str;
    cout << "String after custom sort : " << customSort(order, str);
    return 0;
}