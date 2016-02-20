/*
Given an unsorted array of integers, sort the array into a wave like array. 
An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

Example:

 Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
 Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR
                 {20, 5, 10, 2, 80, 6, 100, 3} OR
                 any other array that is in wave form
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {3,5,6,10,7,20,1};
    for(int i = 1; i < v.size()-1; i = i+2){
        if(v[i] < v[i-1])
            swap(v[i], v[i-1]);
        else if (v[i] < v[i+1])
            swap(v[i], v[i+1]);
    }
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " " ;
}

// Output - 3 6 5 10 7 20 1 
