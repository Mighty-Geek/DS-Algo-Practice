// using Hashing

#include <iostream>
#include <unordered_map>
using namespace std;

void duplicateCharCount(string s)
{
    int n = s.length();
    unordered_map<char, int> count;
    for (int i = 0; i < n; i++)
    {
        count[s[i]]++;
    }
    for (auto x : count)
    {
        if (x.second > 1)
            cout << "Count of \'" << x.first << "\' is " << x.second << endl;
    }
}

int main()
{
    string str;
    cin >> str;
    duplicateCharCount(str);
    return 0;
}
