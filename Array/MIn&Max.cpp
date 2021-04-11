#include<bits/stdc++.h>
using namespace std;

struct MinMax{
    int minNo;
    int maxNo;
};

struct MinMax getMinMax(vector<int> arr){
    int n=arr.size();
    struct MinMax min_max;
    //let min=arr[0], max=arr[0]
    if(n==1){
        min_max.minNo = arr[0];
        min_max.maxNo = arr[0];
    }

    if(arr[0]>arr[1]){
        min_max.minNo = arr[1];
        min_max.maxNo = arr[0];
    }

    else{
        min_max.minNo = arr[0];
        min_max.maxNo = arr[1];
    }

    for(int i=2; i<n; i++){
        if(arr[i]>min_max.maxNo){
            min_max.minNo = arr[i];
        }
        else if(arr[i]<min_max.minNo){
            min_max.minNo = arr[i];
        }
        return min_max;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> arr;
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int data;
            cin >> data;
            arr.push_back(data);
        }
        struct MinMax min_max = getMinMax(arr);
        cout << "Min is: " << min_max.minNo << endl;
        cout << "Max is: " << min_max.maxNo << endl;
    }
    return 0;
}
