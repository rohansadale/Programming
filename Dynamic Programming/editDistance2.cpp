/*
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of equal cost
*/

#include <iostream>
using namespace std;

int editDistance(string s1, string s2, int n1, int n2){
    int m[n1+1][n2+1];
    
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            if(i == 0)
                m[i][j] = j;
            else if (j == 0)
                m[i][j] = i;
            else if(s1[i] == s2[j])
                m[i][j] = m[i-1][j-1];
            else
                m[i][j] = 1 + min(m[i][j-1], min(m[i-1][j], m[i-1][j-1]));
        }
    }
    
    return m[n1][n2];
        
}

int main() {
	string s1 = "ABCEF";
	string s2 = "ABD";
	cout << editDistance(s1,s2, s1.size(), s2.size());
	return 0;
}

// Output - 4
