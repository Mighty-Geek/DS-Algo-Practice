#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int leftsum = 0;

        // calculating sum as right sum
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];

        // subtracting values from right from sum,
        // comparing it with left_sum,
        // updating left_sum
        for(int i=0; i<nums.size(); i++){
            sum -= nums[i];
            if(leftsum == sum)
                return i;
            leftsum += nums[i];
        }
        return -1;
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

    int res = pivotIndex(arr);
    cout << res;
    return 0;
}
