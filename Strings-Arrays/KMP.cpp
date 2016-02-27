// KMP implementation
// https://www.youtube.com/watch?v=5i7oKodCRJo

#include <iostream>
#include <vector>
using namespace std;

void prefixTable(string s, vector<int> &v){
    v[0] = 0;
    int i = 0;
    for(int j = 1; j < s.size(); j++){
        while(i > 0 && s[i] != s[j])
            i = v[i-1];
        if(s[i] == s[j])
            i++;
        v[j] = i;
    }
//    for(int i = 0; i < s.size(); i++)
//        cout << v[i] ;
}

int KMP(string s1, string s2){
    vector<int> v(s2.size(),0);
    prefixTable(s2, v);
    int i = 0;
    
    for(int j = 0; j < s1.size(); j++){
        while(i > 0 && s2[i] != s1[j])
            i = v[i-1];
        if(s1[j] == s2[i])
            i++;
        if(i == s2.size())
            return j-i+1;
    }
    return -1;
}

int main() {
	//code
	string s1 = "ABABDABACDABABCABAB";
	string s2 = "ABABCABAB";
	cout << KMP(s1, s2);
	return 0;
}

// Output - 10