/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size() <= 1)
            return s;
        
        bool table[1000][1000] = {false};
        int maxLen = 1;
        int start = 0;
        
        for(int i = 0; i < s.size(); i++)
            table[i][i] = true;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s[i+1]){
                table[i][i+1] = true;
                maxLen = 2;
                start = i;
            }
        }
        
        int n = s.size();
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n-len+1; i++){
                int j = len+i-1;
                if(s[i] == s[j] && table[i+1][j-1]){
                    table[i][j] = true;
                    maxLen = len;
                    start = i;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};

