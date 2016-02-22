// All possible permutations of string with repeated characters.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<char> &v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
}

void permute(string s, vector<char> &v, int len){
    if(len == 0)
        print(v);
    else{
        for(int i = 0; i < s.size(); i++){
            swap(s[i], s[0]);
            v.push_back(s[0]);
            permute(s, v, len-1);
            swap(s[i], s[0]);
            v.pop_back();
        }
    }
}


int main() {
	string s = "abc";
	vector<char> v;
	permute(s,v, s.size());
	return 0;
}

/*

aaa
aab
aac
abb
aba
abc
acc
acb
aca
bbb
bba
bbc
baa
bab
bac
bcc
bca
bcb
ccc
ccb
cca
cbb
cbc
cba
caa
cab
cac

*/
