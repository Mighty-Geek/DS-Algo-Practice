#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int> arr, int k){
    int n = arr.size();

    if(n<k){
        cout << "INVALID";
        return -1;
    }

    int max_sum = 0;
    for(int i=0; i < k; i++){
        max_sum += arr[i];
    }
    int window_sum = max_sum;
    for(int i=k; i<n; i++){
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> arr;
        int n;
        cin >> n;
        int k;
        cin >> k;
        for(int i=0;i<n;i++){
            int data;
            cin >> data;
            arr.push_back(data);
        }
        int result = maxSum(arr, k);
        cout << result;
    }
   return 0;
}
