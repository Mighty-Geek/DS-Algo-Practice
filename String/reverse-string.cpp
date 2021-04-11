#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << reverseWord(s) << endl;
    }
    return 0;
}

string reverseWord(string str){
    for(int i=0, j=str.length()-1; i<j; i++, j--){
        swap(str[i], str[j]);
    }
    return str;
}

// other ways to solve the problem are:

// 1. iterative approach + swapping start and end
// 2. recursive approach with updating start and end value in function call as s+1, e-1
// 3. to have constant string copy string to another string and swap that
// 4. simply print reversed string using for loop
