#include<iostream>
#include<vector>
using namespace std;

// BRUTE FORCE (O(n^4))

/*
int findMax(vector<vector<int> >mat){
    int n = mat.size();
    int max_val = INT_MIN;

    for(int a=0; a<n-1; a++)
    for(int b =0; b<n-1; b++)
        for(int d = a+1; d<n; d++)
        for(int e = b+1; e<n; e++)
            if(max_val < (mat[d][e] - mat[a][b]))
                max_val = mat[d][e] - mat[a][b];

    return max_val;
}
*/

// O(n^2) solution

int findMax(vector<vector<int> > mat){
    int n = mat.size();
    int max_val = INT_MIN;
    vector<vector<int> >max_arr;

    max_arr[n-1][n-1] = mat[n-1][n-1];
    int maxv = mat[n-1][n-1];

    for(int j=n-2; j>=0; j--){
        if(mat[n-1][j] > maxv)
            maxv = mat[n-1][j];
        max_arr[n-1][j] = maxv;
    }

    maxv = mat[n-1][n-1];

    for(int i=n-2; i>=0; i--){
        if(mat[i][n-1] > maxv)
            maxv = mat[i][n-1];
        max_arr[i][n-1] = maxv;
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            if(max_arr[i+1][j+1] - mat[i][j] > max_val)
                max_val = max_arr[i+1][j+1] - mat[i][j];

            max_arr[i][j] = max(mat[i][j], max(max_arr[i][j+1], max_arr[i+1][j]));
        }
    }
    return max_val;
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
        int result = findMax(arr);
        cout << result;
    }
    cout << endl;
return 0;
}
