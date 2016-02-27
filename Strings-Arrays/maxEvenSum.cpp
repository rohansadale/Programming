/*
Given a string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits 
and sum of left k digits is equal to the sum of right k digits.

Examples:

Input: str = "123123"
Output: 6
The complete string is of even length and sum of first and second
half digits is same

Input: str = "1538023"
Output: 4
The longest substring with same first and second half sum is "5380"

*/

#include <iostream>
#include <vector>
using namespace std;

int maxEvenSum(string s){
    int res = 0;
    vector<int> sum(s.size()+1, 0);
    sum[0] = 0;
    for(int i = 1; i <= s.size(); i++){
        sum[i] = sum[i-1] + (s[i-1] - '0');
    }
    
    int n = s.size();
    
    for(int len = 2; len <= n; len = len+2){
        for(int i = 0; i < n-len+1; i++){
            int j = len+i-1;
            
            if(sum[i+len/2] - sum[i] == sum[len+i] - sum[i+len/2])
                res = max(res, len);
        }
    }
    return res;
}
    

int main() {
	//code
	string s = "123123";
    cout << maxEvenSum(s);
	return 0;
}

// Output - 6