#include <iostream>
#include <vector>
using namespace std;

void spiralOrder(vector<vector<int>> &arr)
{
    vector<int> res;
    int n = arr.size();
    int m = arr[0].size();

    int rs = 0;
    int cs = 0;
    int re = n - 1;
    int ce = m - 1;

    while (rs <= re && cs <= ce)
    {
        for (int c = cs; c <= ce; ++c)
        {
            cout << arr[rs][c] << " ";
        }
        rs++;
        for (int r = rs; r <= re; ++r)
        {
            cout << arr[r][ce] << " ";
        }
        ce--;
        if (rs <= re)
        {
            for (int c = ce; c >= cs; --c)
            {
                cout << arr[re][c] << " ";
            }
            re--;
        }
        if (cs <= ce)
        {
            for (int r = re; r >= rs; --r)
            {
                cout << arr[r][cs] << " ";
            }
            cs++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> arr(r);
        for (int i = 0; i < r; i++)
        {
            arr[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        spiralOrder(arr);
    }
    cout << endl;
    return 0;
}
