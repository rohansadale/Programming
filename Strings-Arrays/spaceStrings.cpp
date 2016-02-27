/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

Input:  str[] = "ABC"
Output: ABC
        AB C
        A BC
        A B C
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<char> &buff){
    int i = 0;
    while(buff[i] != '1'){
        cout << buff[i];
        i++;
    }
    cout << endl;
}

void allSpaceUtil(string s, vector<char> &buff, int i, int j){
    if(i == s.size()){
        buff[j] = '1';
        print(buff);
        return;
    }
    
    buff[j] = s[i];
    allSpaceUtil(s, buff, i+1, j+1);
    
    buff[j] = ' ';
    buff[j+1] = s[i];
    allSpaceUtil(s, buff, i+1, j+2);
}

void allSpaceStrings(string s){
    vector<char> buff(2*s.size());
    buff[0] = s[0];
    allSpaceUtil(s, buff, 1, 1);
}

int main() {
	//code
	string s = "ABCD";
    allSpaceStrings(s);
	return 0;
}

/*
Output 
ABCD
ABC D
AB CD
AB C D
A BCD
A BC D
A B CD
A B C D
*/