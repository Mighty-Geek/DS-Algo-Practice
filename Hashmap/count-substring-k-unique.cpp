#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

// approach 1:
// int countSubstrkUnique(string s, int k)
// {
//     int n = s.length();
//     int array[26];
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int temp = 0;
//         memset(array, 0, sizeof(array));
//         for (int j = i; j < n; j++)
//         {
//             if (array[s[j] - 'a'] == 0)
//                 temp++;
//             array[s[j] - 'a']++;
//             if (temp == k)
//                 count++;
//             if (temp > k)
//                 break;
//         }
//     }
//     return count;
// }

// approach 2 (HashMap):
// int solutionfork1(string s)
// {
//     int count = 0;
//     unordered_map<char, int> map;
//     int i = -1, j = -1;
//     while (true)
//     {
//         bool f1 = false, f2 = false;
//         while (i < s.length() - 1)
//         {
//             f1 = true;
//             i++;
//             map[s[i]]++;
//             if (map.size() == 2)
//             {
//                 if (map[s[i]] == 1)
//                     map.erase(s[i]);
//                 else
//                     map[s[i]]--;
//                 i--;
//                 break;
//             }
//         }
//         while (j < i)
//         {
//             f2 = true;
//             if (map.size() == 1)
//             {
//                 count += i - j;
//             }
//             j++;
//             if (map[s[j]] == 1)
//                 map.erase(s[j]);
//             else
//                 map[s[j]]--;

//             if (map.size() == 0)
//                 break;
//         }
//         if (f1 == false && f2 == false)
//             break;
//     }
//     return count;
// }

// int countSubstrkUnique(string s, int k)
// {
//     int n = s.length();
//     int count = 0;
//     if (k == 1)
//     {
//         return solutionfork1(s);
//     }
//     unordered_map<char, int> small;
//     unordered_map<char, int> big;

//     int is = -1;
//     int ib = -1;
//     int j = -1;

//     while (true)
//     {
//         bool f1 = false;
//         bool f2 = false;
//         bool f3 = false;

//         while (ib < n - 1)
//         {
//             f1 = true;
//             ib++;
//             char ch = s[ib];
//             big[ch]++;
//             // release if size (big hashmap) > k
//             if (big.size() == k + 1)
//             {
//                 if (big[s[ib]] == 1)
//                     big.erase(s[ib]);
//                 else
//                     big[s[ib]]--;
//                 ib--;
//                 break;
//             }
//         }

//         while (is < ib)
//         {
//             f2 = true;
//             is++;
//             char ch = s[is];
//             small[ch]++;
//             if (small.size() == k)
//             {
//                 if (small[s[is]] == 1)
//                     small.erase(s[is]);
//                 else
//                     small[s[is]]--;
//                 is--;
//                 break;
//             }
//         }

//         while (j < is)
//         {
//             f3 = true;
//             if (big.size() == k && small.size() == k - 1)
//             {
//                 count += ib - is;
//             }
//             j++;
//             if (big[s[j]] == 1)
//                 big.erase(s[j]);
//             else
//                 big[s[j]]--;

//             if (small[s[j]] == 1)
//                 small.erase(s[j]);
//             else
//                 small[s[j]]--;

//             if (small.size() < k - 1 && big.size() < k)
//                 break;
//         }

//         if (f1 == false && f2 == false && f3 == false)
//         {
//             break;
//         }
//     }
//     return count;
// }

// approach 3:
int solutionBuilder(string s, int k)
{
    int n = s.size();
    int j = 0, res = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int num = s[i];
        if (map[num] == 0)
            k--;
        map[num]++;
        while (k < 0)
        {
            int num_at_j = s[j];
            map[num_at_j]--;
            if (map[num_at_j] == 0)
                k++;
            j++;
        }
        res += i - j + 1;
    }
    return res;
}
int countSubstrkUnique(string s, int k)
{
    return solutionBuilder(s, k) - solutionBuilder(s, k - 1);
}
int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    cout << countSubstrkUnique(str, k);

    return 0;
}