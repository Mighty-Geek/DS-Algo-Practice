// row_start = 0
// row_end = n-1
// column_start = 0
// column_end = m-1

// Algorithm:
// step 1: traverse row 1 from column_start to column_end, increment row_start
// step 2: traverse column n from column_end to row_start, decrement column_end
// step 3: traverse row n from column_end to column_start, decrement row_end
// step 4: traverse column 1 from row_end to row_start, increment column_start
// step 5: Repeat steps 1-4 till row_start <= row_end and column_start <= column_end

#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int rs = 0, re = n - 1, cs = 0, ce = m - 1;

    while (rs <= re && cs <= ce)
    {
        for (int c = cs; c <= ce; ++c)
        {
            cout << mat[rs][c] << " ";
        }
        rs++;

        for (int r = rs; r <= re; ++r)
        {
            cout << mat[r][ce] << " ";
        }
        ce--;

        if (rs <= re)
        {
            for (int c = ce; c >= cs; --c)
            {
                cout << mat[re][c] << " ";
            }
            re--;
        }

        if (cs <= ce)
            for (int r = re; r >= rs; --r)
            {
                cout << mat[r][cs] << " ";
            }
        cs++;
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
        cout << "SPIRAL TRAVERSAL: \t";
        printSpiral(arr);
        cout << endl;
    }
    return 0;
}
