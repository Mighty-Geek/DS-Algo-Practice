#include <iostream>
#include <vector>
using namespace std;

// 1. recursive: Time complexity: O(3^n)

// 2. dp: Time complexity: O(n)
long paintHouse(vector<vector<int>> rgb, int n)
{
    long red = rgb[0][0];
    long blue = rgb[0][1];
    long green = rgb[0][2];
    for (int i = 1; i < n; i++)
    {
        long new_red = rgb[i][0] + min(blue, green);
        long new_blue = rgb[i][1] + min(red, green);
        long new_green = rgb[i][2] + min(red, blue);

        red = new_red;
        blue = new_blue;
        green = new_green;
    }
    long ans = min(red, min(blue, green));
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> rgb;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < 3; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        rgb.push_back(row);
    }
    cout << paintHouse(rgb, n) << endl;
    return 0;
}

// dry run:
// 4
// 1 5 3 1
// 5 8 2 2
// 7 4 9 4

// dp[][]:
// 1 10 8 8
// 5 9 7 10
// 7 5 18 11