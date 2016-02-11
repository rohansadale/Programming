/*
Convert a roman number to decimal
*/

#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int romanToInt(string &roman){
    map<char,int> m;
    m['M'] = 1000;
    m['D'] = 500;
    m['C'] = 100;
    m['L'] = 50;
    m['X'] = 10;
    m['V'] = 5;
    m['I'] = 1;
    
    int result = 0;
    int prev = 0;
    int current = 0;
    for(int i = 0; i < roman.size(); i++){
        current = m[roman[i]];
        result += current;
        
        if(prev && prev < current)
            result = result - 2*prev;
        
        prev = current;
    }
    return result;
}

main(){
    string roman = "MXIV";
    cout << romanToInt(roman);

}

// Output - 1014
