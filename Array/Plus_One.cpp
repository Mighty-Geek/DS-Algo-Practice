#include<bits/stdc++.h>
using namespace std;

  vector<int> plusOne(vector<int> &nums)
    {
        int n = nums.size();

        nums[n-1] += 1;
        int carry = nums[n-1]/10;
        nums[n-1] = nums[n-1] % 10;

        for (int i=n-2; i>=0; i--)
        {
            if (carry == 1)
            {
               nums[i] += 1;
               carry = nums[i]/10;
               nums[i] = nums[i] % 10;
            }
        }

        if (carry == 1)
          nums.insert(nums.begin(), 1);
        return nums;
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

    vector<int> res = plusOne(arr);
    for(int i=0; i<arr.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}

