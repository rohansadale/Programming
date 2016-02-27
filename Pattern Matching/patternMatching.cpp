// Find needle in haystack. Pattern matching algorithm

#include <iostream>
using namespace std;

int pattern(string s1, string s2){
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == s2[0]){
            int temp = i;
            int count = 0;
            for(int j = 0; j < s2.size(); j++){
                if(s1[temp] == s2[j])
                    count++;
                else
                    break;
                temp++;
            }
            if(count == s2.size())
                return i;
        }
    }
    return -1;
}

int main() {
	//code
	
	string s1 = "AABCCAADDEE";
	string s2 = "AAD";
	cout << pattern(s1, s2);
	return 0;
}

// Output - 5