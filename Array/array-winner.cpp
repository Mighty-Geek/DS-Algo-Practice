// Find winner of an Array

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

// Brute force, T(n)=O(n^2)
// vector<int> leftRotatebyOne(vector<int> a)
// {
//     int n = a.size();
//     int temp = a[1], i;
//     for (i = 1; i < n - 1; i++)
//         a[i] = a[i + 1];

//     a[n - 1] = temp;
//     return a;
// }
// int findWinner(vector<int> a, int k)
// {
//     int n = a.size();
//     if (n == 0)
//         return 0;
//     unordered_map<int, int> count;
//     int i = 0;
//     while (i < n && count[a[0]] < k)
//     {
//         if (k == 1)
//         {
//             return (a[0] > a[1]) ? a[0] : a[1];
//         }
//         else
//         {
//             if (a[1] > a[0])
//             {
//                 count[a[1]]++;
//                 count[a[0]] = 0;
//                 swap(a[1], a[0]);
//             }
//             else
//             {
//                 count[a[0]]++;
//                 count[a[1]] = 0;
//             }
//             a = leftRotatebyOne(a);
//         }
//         i++;
//     }
//     return a[0];
// }

// T(n) = O(n)
// int findWinner(vector<int> a, int k)
// {
//     int n = a.size();
//     if (n == 0)
//         return 0;
//     int count = 0;
//     int res = a[0];
//     int i = 1;
//     while (true)
//     {
//         if (res > a[i])
//             count++;
//         else
//         {
//             res = a[i];
//             count = 1;
//         }
//         i++;
//         if (count == k)
//             break;
//         if (i == n - 1)
//             break;
//     }
//     return res;
// }

// using stack
int findWinner(vector<int> a, int k)
{
    int n = a.size();
    if (n == 0)
        return 0;
    stack<int> s;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(a[i]);
        }
        else
        {
            if (s.top() < a[i])
            {
                count[a[i]]++;
                count[s.top()] = 0;
                s.pop();
                s.push(a[i]);
            }
            else
            {
                count[s.top()]++;
            }
            if (count[s.top()] >= k)
                return s.top();
        }
    }
    return s.top();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr;
        int size, k;
        cin >> size >> k;
        for (int i = 0; i < size; i++)
        {
            int d;
            cin >> d;
            arr.push_back(d);
        }
        cout << findWinner(arr, k) << endl;
    }
    return 0;
}