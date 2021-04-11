#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int maxHist(vector<int> row, int c){
    stack<int> result;
    int top_val;

    int max_area = 0;
    int area = 0;
    int i=0;
    while(i < c){
        if(result.empty() || row[result.top()] <= row[i])
            result.push(i++);
        else{
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if(!result.empty())
                area = top_val * (i-result.top()-1);
            max_area = max(area, max_area);
        }
    }
    while(!result.empty()){
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;

        if(!result.empty())
            area = top_val * (i-result.top()-1);

        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(vector<vector<int> >mat, int r, int c){
    int result = maxHist(mat[0], c);

    for(int i=1; i<r; i++){
        for(int j=0; j<c; j++)
            if(mat[i][j])
                mat[i][j] += mat[i-1][j];
        result = max(result, maxHist(mat[i], c));
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
        int result = maxRectangle(arr, r, c);
        cout << result;
    }
    cout << endl;
return 0;
}
