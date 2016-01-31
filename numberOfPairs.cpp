/*
Given an integer array and a positive integer k, count all distinct pairs with difference equal to k.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pairs(vector<int> &v, int k){
    sort(v.begin(), v.end());
    int l = 0;
    int h = 0;
    int count = 0;
    
    while(h < v.size()){
        if(v[h] - v[l] == k){
            count++;
            l++;
            h++;
        }
        else if(v[h] - v[l] > k)
            l++;
        else
            h++;
    }
    return count;
}

main(){
    vector<int> v = {1,3,4,2,5,6,9};
    cout << pairs(v, 3);

}

// Output - 4
