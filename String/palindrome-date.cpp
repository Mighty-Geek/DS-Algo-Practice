#include <bits/stdc++.h>
using namespace std;

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isLeap(int);
bool isValidDate(int, int, int);
void findPalindromeDate(int);

bool isLeap(int yr)
{
    return (((yr % 4 == 0) && (yr % 100 != 0)) || (yr % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            (d <= 28);
    }

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return (d <= 30);

    return true;
}

void findPalindromeDate(int year)
{
    string str = to_string(year);
    string rev = str;
    reverse(rev.begin(), rev.end());

    int day = stoi(rev.substr(0, 2));
    int month = stoi(rev.substr(2, 3));

    if (isValidDate(day, month, year))
    {
        cout << day << "-" << month << "-" << year << endl;
    }
    else
        cout << "Palindrome date doesn't exist in year " << year;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        findPalindromeDate(N);
    }
    return 0;
}