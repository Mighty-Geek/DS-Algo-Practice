#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#define INF INT_MAX

void youngify(vector<vector<int> >mat, int i, int j){
    int n = mat.size();
    int down_val = (i+1 < c)? mat[i+1][j]: INF;
    int right_val = (j+1 < c)? mat[i][j+1]: INF;

    if(down_val == INF && right_val == INF)
        return;

    if(down_val < right_val){
        mat[i][j] = down_val;
        mat[i+1][j] = INF;
        youngify(mat, i+1, j);
    }
    else{
        mat[i][j] = right_val;
        mat[i][j+1] = INF;
        youngify(mat, i, j+1);
    }
}

int extractMin(vector<vector<int> >mat){
    int ret = mat[0][0];
    mat[0][0] = INF;
    youngify(mat, 0, 0);
    return ret;
}

void printSorted(vector<vector<int> >mat,int c){
    for(int i=0; i<c*c; i++){
            cout << extractMin(mat) << " ";
        }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int> > arr(r);
        for(int i=0; i<n; i++){
            arr[i].assign(n, 0);
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        printSorted(arr, n);
    }
return 0;
}
