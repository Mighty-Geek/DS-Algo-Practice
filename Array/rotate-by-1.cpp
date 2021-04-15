#include <bits/stdc++.h>
using namespace std;

vector<int> rotateByOne(vector<int> arr)
{
    int n = arr.size();
    reverse(arr.begin(), arr.end());

    for (int i = 1, j = n - 1; i <= j; i++, j--)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return arr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    vector<int> res = rotateByOne(arr);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}