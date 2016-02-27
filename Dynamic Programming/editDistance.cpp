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
    if(n1 < 0)
        return 0;
    if(n2 < 0)
        return 0;
    
    if(s1[n1] == s2[n2])
        return editDistance(s1, s2, n1-1, n2-1);
    else
        return 1 + min(editDistance(s1, s2, n1, n2-1),
                    min(editDistance(s1, s2, n1-1, n2),
                        editDistance(s1, s2, n1-1, n2-1)));
    
}

int main() {
	string s1 = "ABCEF";
	string s2 = "ABD";
	cout << editDistance(s1,s2, s1.size()-1, s2.size()-1);
	return 0;
}

// Output - 3
