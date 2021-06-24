#include <bits/stdc++.h>
using namespace std;

static int myCompare(string A, string B)
{
    string AB = A.append(B);
    string BA = B.append(A);

    return (AB.compare(BA) > 0) ? 1 : 0;
}
string largestNumber(vector<int> &nums)
{
    int n = nums.size();
    string str[100];
    for (int i = 0; i < nums.size(); i++)
    {
        str[i] = to_string(nums[i]);
    }
    string res = "";
    sort(str, str + n, myCompare);
    int s = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < s; i++)
        res += str[i];
    if (res[0] == '0')
        return "0";
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    cout << largestNumber(nums) << endl;
    return 0;
}