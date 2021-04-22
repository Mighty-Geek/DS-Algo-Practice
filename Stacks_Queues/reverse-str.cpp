#include <iostream>
#include <stack>
using namespace std;

string reverseIt(string str)
{
    stack<char> s;
    int l = str.length();
    for (int i = 0; i < l; i++)
    {
        s.push(str[i]);
    }
    for (int i = 0; i < l; i++)
    {
        str[i] = s.top();
        s.pop();
    }
    return str;
}

int main()
{
    string str;
    cin >> str;

    cout << reverseIt(str);
    return 0;
}
