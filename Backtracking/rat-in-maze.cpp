#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> visited(5, vector<int>(5, 0));
vector<string> res;

void path(vector<vector<int>> &m, int x, int y, string dir, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        res.push_back(dir);
        return;
    }

    if (m[x][y] == 0 || visited[x][y] == 1)
        return;

    visited[x][y] = 1;
    if (x > 0)
        path(m, x - 1, y, dir + 'U', n);
    if (y > 0)
        path(m, x, y - 1, dir + 'L', n);
    if (x < n - 1)
        path(m, x + 1, y, dir + 'D', n);
    if (y < n - 1)
        path(m, x, y + 1, dir + 'R', n);

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    res.clear();
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return res;

    path(m, 0, 0, "", n);
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> maze(n);
        for (int i = 0; i < n; i++)
        {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
            }
        }
        vector<string> res = findPath(maze, n);
        if (res.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < res.size(); i++)
            {
                cout << res[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}