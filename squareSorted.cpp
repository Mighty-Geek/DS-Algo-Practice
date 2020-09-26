#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& A){
    int k = 0;
    int n = A.size();
    for(k=0; k<n; k++)
        if(A[k] >= 0)
            break;
    int i = k-1;
    int j = k;
    int temp_index = 0;
    int temp[n];
    while(i>=0 && j<n) {
        if(A[i] * A[i] < A[j] * A[j]) {
            temp[temp_index] = A[i] * A[i];
            i--;
        }
        else {
            temp[temp_index] = A[j] * A[j];
            j++;
        }
        temp_index++;
    }

    while (i >= 0) {
        temp[temp_index] = A[i] * A[i];
        i--;
        temp_index++;
    }

    while (j < n) {
        temp[temp_index] = A[j] * A[j];
        j++;
        temp_index++;
    }
    for (int i = 0; i < n; i++)
        A[i] = temp[i];
    return A;
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

    vector<int> res = sortedSquares(arr);
    for(int i=0; i<arr.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}
