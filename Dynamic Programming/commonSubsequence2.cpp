#include <iostream>
using namespace std;

int commonSubsequence(string s1, string s2, int n1, int n2){
    int m[n1+1][n2+1];
    
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            if(i == 0 || j == 0)
                m[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                m[i][j] = 1 + m[i-1][j-1];
            else
                m[i][j] = max(m[i-1][j], m[i][j-1]);
        }
    }
    
    return m[n1][n2];
}


int main() {
	string s1 = "ABC";
	string s2 = "ABD";
	cout << commonSubsequence(s1,s2, s1.size(), s2.size());
	return 0;
}
