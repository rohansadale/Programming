/*
A magic index in an array A[l.. .n-l] is defined to be an index such that A[i] =
i. Given a sorted array of distinct integers, write a method to find a magic index, if
one exists, in array A.
*/

#include<iostream>
#include<vector>
using namespace std;

bool magicIndex(int a[], int n, int low, int high){
    int mid = (low+high)/2;
    if(a[mid] == mid)
        return true;
    if(a[mid] > mid)
        magicIndex(a, n, low, mid-1);
    else
        magicIndex(a, n, mid+1, high);
}

main(){
    int a[] = {-1,-2,2,5,10,12,34};    
    int n = sizeof(a)/sizeof(int);
    cout << magicIndex(a, n, 0, n-1);
}
