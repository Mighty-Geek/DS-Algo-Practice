#include <iostream>
#include <stack>
using namespace std;

bool isValid(string input)
{
    stack<char> s;
    char x;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{')
        {
            s.push(input[i]);
            continue;
        }
        if (s.empty())
            return false;

        switch (input[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x == '{' || x == '(')
                return false;
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x == ')' || x == '[')
                return false;
            break;
        }
    }
    return (s.empty());
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string input;
        cout << "\n[-] Enter string of parentheses to be checked : ";
        cin >> input;

        if (isValid(input))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}