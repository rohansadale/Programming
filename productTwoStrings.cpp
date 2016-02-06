// Product of two large numbers

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string multiply(string s1, string s2){

    vector<int>product(s1.size() + s2.size()+1, 0);
    int n = product.size() - 1;
    
    int zeros = 0;
    for(int i = s1.size()-1; i >= 0; i--){
        int t = n;
        int carry = 0;
        for(int j = s2.size()-1; j >= 0; j--){
            int temp = product[t - zeros] + (s1[i] - '0') * (s2[j] - '0') + carry;
            product[t - zeros] = temp % 10;
            carry = temp/10;
            t--;
        }
        if(carry)
            product[t-zeros] += carry;
        zeros++;
    }
    
    string s;
    int i = 0;
    while(!product[i])
        i++;
    for(int j = i; j <= n; j++)
        s.append(to_string(product[j]));
        
    return s;
}

int main()
{
    string s1 = "1232321312";
    string s2 = "12";
    cout << multiply(s1, s2);
}

// Output - 14787855744
