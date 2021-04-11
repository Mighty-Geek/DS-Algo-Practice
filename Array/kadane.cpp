#include<iostream>
#include<vector>

using namespace std;

int findSum(vector<int>arr){
    int n = arr.size();
    int max_so_far = 0;
    int max_ending_here = 0;

    for(int i=0; i<n; i++){
        max_ending_here += arr[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if(max_ending_here < 0 )
            max_ending_here = 0;
    }
    return max_so_far;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int data;
            cin >> data;
            arr.push_back(data);
        }
        cout << "Max subarray sum : " << findSum(arr);
    }
    return 0;
}



