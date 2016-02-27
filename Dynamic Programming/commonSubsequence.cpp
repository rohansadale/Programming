/*
Given two sequences, find the length of longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

*/

#include <iostream>
using namespace std;

int commonSubsequence(string s1, string s2, int n1, int n2){
    if(n1 < 0 || n2 < 0)
        return 0;
    if(s1[n1] == s2[n2])
        return 1 + commonSubsequence(s1, s2, n1-1, n2-1);
    
    else
        return max(commonSubsequence(s1, s2, n1-1, n2), 
                        commonSubsequence(s1, s2, n1, n2-1));
}


int main() {
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	cout << commonSubsequence(s1,s2, s1.size()-1, s2.size()-1);
	return 0;
}

// Output - 4
