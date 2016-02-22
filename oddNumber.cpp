/*
Given an array of positive integers. 
All numbers occur even number of times except one number which occurs odd number of times. 
Find the number in O(n) time & constant space.

Example:
I/P = [1, 2, 3, 2, 3, 1, 3]
O/P = 3

*/

#include <iostream>
#include<vector>
using namespace std;

int oddNumber(vector<int> &v){
    int res = 0;
    
    for(int i = 0; i < v.size(); i++)
        res = res^v[i];
    
    return res;
}

int main() {
	
	vector<int> v = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
	cout << oddNumber(v);
	return 0;
}

// Output - 5
