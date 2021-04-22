#include <iostream>
using namespace std;

// brute force Theta(logn)
/*
int printCount(int n)
{
    unsigned int c = 0;
    while (n > 0)
    {
        c += n & 1;
        n >>= 1;
    }
    return c;
}
*/

// Brian kernighan Algorithm O(logn)

int printCount(int n)
{
    if (n == 0)
        return 0;
    else
        return 1 + printCount(n & (n - 1));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        cout << printCount(n);
    }
    cout << endl;
    return 0;
}