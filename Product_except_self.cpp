#include<bits/stdc++.h>
using namespace std;

 vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        //initializing ans with all values as 1 and size n
        vector<int> ans(n, 1);

        // products of the values to left
        int curLeft = 1;
        for(int i=0; i<n; i++){
            ans[i] = curLeft;
            curLeft *= nums[i];
        }

        // products of the values to the right
        int curRight = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] *= curRight;
            curRight *= nums[i];
        }

        return ans;
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

    vector<int> res = productExceptSelf(arr);
    for(int i=0; i<arr.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}
