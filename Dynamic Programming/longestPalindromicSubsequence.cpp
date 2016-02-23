/*
Given a sequence, find the length of the longest palindromic subsequence in it. 
For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it.
“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.
*/

#include <iostream>
#include <string>
using namespace std;

int longestPalSubsequence(string s){
    int n = s.size();
    int A[n][n];
    for(int i = 0; i < s.size(); i++)
        A[i][i] = 1;
    
    for(int len = 2; len <= n; len++){
        for(int i = 0; i < n-len+1; i++){
            int j = i+len-1;
            if(s[i] == s[j] && len == 2)
                A[i][j] = 2;
            else if(s[i] == s[j])
                A[i][j] = A[i+1][j-1] + 2;
            else
                A[i][j] = max(A[i+1][j], A[i][j-1]);
        }
    }
    
    return A[0][n-1];
}

int main() {
	string s = "BBABCBCAB";
	cout << longestPalSubsequence(s);
	return 0;
}

// Output - 7
