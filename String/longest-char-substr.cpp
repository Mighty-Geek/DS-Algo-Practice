#include <iostream>
using namespace std;

int longestCharSubstr(string str)
{
    int size = str.length();
    int curr_count = 0;
    int count = 0;
    string substr = " ";
    for (int i = 0; i < size; i++)
    {
        if (str[i] == str[i + 1])
        {
            substr += str[i];
            curr_count++;
            count = max(count, curr_count);
        }
        else
        {
            substr = " ";
            curr_count = 0;
        }
    }
    return count;
}

int main()
{
    string str;
    cin >> str;
    cout << longestCharSubstr(str);
    return 0;
}