#include<bits/stdc++.h>
using namespace std;

// Solved using XOR approach, Time complexity: O(n)

int missingNumber(vector<int>& nums){
    int a = nums[0];
    int b = 1;

    for(int i=1; i < nums.size(); i++)
        a = a ^ nums[i];

    for(int i=2; i <= nums.size(); i++)
        b = b ^ i;

    return (a ^ b);
}
int main()
{
   vector<int> arr;
   int n;
   cin>>n;
    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        arr.push_back(data);
    }

    int ans = missingNumber(arr);
    cout << ans;
    return 0;
}
