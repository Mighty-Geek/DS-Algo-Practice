// recursion just for practice but practically only to be used with
// memoisation otherwise there will be TLE
// or result can be directly printed

#include <iostream>
#include <vector>
using namespace std;

void printStairPaths(int n, string ans)
{
    if (n < 0)
        return;
    if (n == 0)
    {
        cout << ans << " ";
        return;
    }

    printStairPaths(n - 1, ans + "1");
    printStairPaths(n - 2, ans + "2");
    printStairPaths(n - 3, ans + "3");
}

int main()
{
    int n;
    cin >> n;
    printStairPaths(n, "");
    return 0;
}