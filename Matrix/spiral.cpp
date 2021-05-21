#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int> > arr, int m, int n){
    int i, k=0, l=0;
    vector<int> result;
    while(k<m && l<n){
     for(i=l; i<n; ++i){
        result.push_back(arr[k][i]);
     }
     k++;
     for(i=k; i<m; ++i){
        result.push_back(arr[i][n-1]);
     }
     n--;

     if(k<m){
        for(i=n-1; i>=l; --i){
            result.push_back(arr[m-1][i]);
        }
        m--;
     }

     if(l<n){
        for(i=m-1; i>=k; --i){
            result.push_back(arr[i][l]);
        }
        l++;
     }
    }
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
        vector<int> result = spiralPrint(arr, r, c);
        for(int i=0; i<result.size(); i++){
            cout << result[i] << " ";
        }
    }
    cout << endl;
return 0;
}
