// Sum of two large numbers

#include<iostream>
#include <vector>
#include<algorithm>
#include<string>
using namespace std;

string sum(string s1, string s2){
    vector<int>v(max(s1.size(), s2.size()) + 1, 0);
    int n = v.size()-1; 
    for(int i = s1.size()-1; i >=0 ; i--){
        v[n] = s1[i] - '0';
        n--;
    }
    
    
    n = v.size()-1;
    int carry = 0;
    for(int i = s2.size()-1; i >= 0; i--){
        int temp = v[n];
        v[n] = (v[n] + (s2[i] - '0') + carry) % 10; 
        carry = (temp + (s2[i] - '0') + carry) / 10;
        n--;
    }
    if(carry)
        v[n] += carry;
    
    string sum;
    int j = 0;
    while(v[j] == 0)
        j++;
        
    for(int i = j; i < v.size(); i++){
        sum.append(to_string(v[i])); 
    }
    
    if(sum.empty())
        return to_string(0);
        
    return sum;
}

main()
{
    string s1 = "0";
    string s2 = "0101";
    cout << sum(s1, s2);

}

// Output - 101
