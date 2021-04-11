#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPalindrome(string s)
	{
	    string rev;
	    rev = s;
	    for(int i=0, j=s.length()-1; i<j; i++, j--){
	        swap(rev[i], rev[j]);
	    }
	    if(s == rev)
	        return 1;
	   else
	        return 0;
	}
	// check for alphanumeric and also consider uppercase letters for a sentence
/*
     bool isPalindrome(string s) {
        int n= s.size();
        int start = 0;
        int end = n-1;
        while(start<end){
            while(isalnum(s[start]) == false && start < end)
                start++;
            while(isalnum(s[end]) == false && start<end)
                  end--;

            if (toupper(s[start]) != toupper(s[end]))
                return false;
            start++;
            end--;
        }
            return true;
    }
 */
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        Solution object_s;
        cout << object_s.isPalindrome(s) << "\n";
    }
    return 0;
}

// another solution can be two pointer approach comparing str[start] with str[end]
