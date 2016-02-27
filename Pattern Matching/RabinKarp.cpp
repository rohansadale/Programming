// Rabin-Karp implementation
// Concept - https://www.youtube.com/watch?v=H4VrKHVG5qI

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int Rabin_Karp(string s1, string s2){
    int prime = 3;
    int phash = 0;      // pattern hash
    int shash = 0;      // first substring hash
    
    for(int i = 0; i < s2.size(); i++){
        phash += (int)s2[i] * pow(prime, i);
        shash += (int)s1[i] * pow(prime, i);
    }
    
    if(phash == shash)
        return 0;
    
    int n1 = s1.size();
    int n2 = s2.size();
    for(int i = 1; i < n1-n2+1; i++){
        shash = shash - s1[i-1];
        shash = shash/prime;
        shash = shash + s1[i+n2-1]*pow(prime,n2-1);

        if(shash == phash){
            //cout << i << endl; // Uncomment if need to find all locations and comment below return statement
            return i;
        }
    }
    return -1;
}

int main() {
	//code
	string s1 = "ABABDABACDABABCABAB";
	string s2 = "BA";
	//int a = (int)s1[0];
	cout << Rabin_Karp(s1, s2);
	return 0;
}

// Output - 1