#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
int findIndex(vector<int>, int);
int maxOnes(vector<vector<int> >mat, int r, int c){
    vector<int> arr;
    int res;
    for(int i=0; i<r; i++){
            int sum = 0;
        for(int j=0; j<c; j++){
            if(mat[i][j] == 1)
                sum++;
        }
        arr.push_back(sum);
    }
    int x = *max_element(arr.begin(), arr.end());
    if(x == 0){
        return -1;
    }
    res = findIndex(arr, x);
    return res;
}

int findIndex(vector<int> nums, int x){
    for(int i=0 ;i<nums.size(); i++){
        if(nums[i] == x)
            return i;
    }
}

*/

// 2nd approach: Binary Search

int first(vector<int> arr, int low, int high)
{
    if(high >= low)
    {
        int mid = low + (high - low)/2;
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);
        else
            return first(arr, low, (mid -1));
    }
    return -1;
}


int maxOnes(vector<vector<int> >mat, int r, int c){
    int i, index;
    int max_row_index = 0;
    int max = first(mat[0], 0, c-1);

    for(i=1; i<r; i++){
        if(max != -1 && mat[i][c-max-1] == 1){
            index = first(mat[i], 0, c-max);

            if(index != -1 && c-index > max){
                max = c-index;
                max_row_index = i;
            }
        }
        else{
            max = first(mat[i], 0, c-1);
        }
    }
    return max_row_index;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        vector<vector<int> > arr(r);
        for(int i=0; i<r; i++){
            arr[i].assign(c, 0);
            for(int j=0; j<c; j++){
                cin >> arr[i][j];
            }
        }
        cout << maxOnes(arr, r, c);
        //cout << result;
        }
    cout << endl;
return 0;
}
