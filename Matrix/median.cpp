#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    int findMedian(vector<int> arr)
        {
            int n = arr.size();
            sort(arr.begin(), arr.end());
            return arr[n/2];
        }

    int median(vector<vector<int> > &matrix, int r, int c){
        vector<int> arr;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                arr.push_back(matrix[i][j]);
            }
        }
        int result = findMedian(arr);
        return result;
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
        int result = median(arr, r, c);
        cout << result;
    }
    cout << endl;
return 0;
}
*/

// approach 2: Binary search

int binaryMedian(vector<vector<int> >m, int r, int c){
    int min_m = INT_MAX, max_m = INT_MIN;
    for(int i=0; i<r; i++){
        if(m[i][0] < min_m)
            min_m = m[i][0];
        if(m[i][c-1] > max_m)
            max_m = m[i][c-1];
    }

    int desired = (r*c + 1)/2;
    while(min_m < max_m){
            int mid = min_m + (max_m-min_m)/2;
            int place = 0;

            for(int i=0; i<r; i++)
                place+=upper_bound(m[i], m[i]+c, mid) - m[i]; //count of numbers till upper bound of val is reached
            if(place < desired)
                min_m = mid+1;
            else
                max_m = mid;
    }
    return min_m;
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
        int result = binaryMedian(arr, r, c);
        cout << result;
    }
    cout << endl;
return 0;
}






