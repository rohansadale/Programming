/* 
Given a sequence, find the length of the longest palindromic subsequence in it. For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. 
“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.
*/

#include <iostream>
#include <string>

using namespace std;

int longestPal(string s, int i, int j){
    if(i == j)
        return 1;
    if(i+1 == j)
        return 2;
    if (s[i] == s[j])
        return longestPal(s, i+1, j-1) + 2;
    else
        return max(longestPal(s, i+1, j), longestPal(s, i, j-1));
}

int main() {
    string s = "BBABCBCAB";
    cout << longestPal(s, 0, s.size()-1);
	return 0;
}

//Output - 7
