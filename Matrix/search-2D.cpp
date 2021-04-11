#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> >&arr, int target){
    int m = arr.size();
    int n = arr[0].size();

    if(n==0 && m==0)
        return 0;

    int smallest = arr[0][0], largest = arr[m-1][n-1];

    if(target<smallest || target>largest)
        return 0;

    int i=0, j= n-1;
    while(i<m && j>=0){
        if(arr[i][j] == target){
            return 1;
        }
        if(arr[i][j] > target)
            j--;
        else
            i++;
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        int x;
        vector<vector<int> > arr(r);
        for(int i=0; i<r; i++){
            arr[i].assign(c, 0);
            for(int j=0; j<c; j++){
                cin >> arr[i][j];
            }
        }
        cin >> x;
        bool result = searchMatrix(arr, x);
        cout << boolalpha << result;
    }
    cout << endl;
return 0;
}
