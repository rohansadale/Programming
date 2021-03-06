/*
Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes 
the whole array sorted.

Examples:
1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that 
the subarray lies between the indexes 3 and 8.

2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], your program should be able to find that 
the subarray lies between the indexes 2 and 5.

*/



#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    
    int max = v[0];
    int min = v[v.size()-1];
    int rightIndex = v.size()-1;
    int leftIndex = 0;
    
    for(int i = 0; i < v.size(); i++){
        if(max < v[i])
            max = v[i];
        if(v[i] < max)
            rightIndex = i;
    }
    
    for(int i = v.size()-1; i >= 0; i--){
        if(min > v[i])
            min = v[i];
        if(v[i] > min)
            leftIndex = i;
    }
    
    cout << "Sort the array between "<< leftIndex << " and " << rightIndex;
    
}

