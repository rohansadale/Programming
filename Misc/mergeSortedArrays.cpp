// You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. 
//Write a method to merge B into A in sorted order.

#include<iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, vector<int>&B, int n1, int n2){
    int last = A.size()-1;
    int i1 = n1-1;
    int i2 = n2-1;
    
    while(1){
        while(A[i1] <= B[i2]){
            A[last--] = B[i2--];
        }
        if(i2 < 0)
            break;
            
        while(A[i1] > B[i2]){
            A[last--] = A[i1--];
        }
        if(i1 < 0)
            break;
    }
    while(i2>0)
        A[last--] = B[i2--];
    
    cout << "Final Merged Array = ";
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
        
}

main()
{
    vector<int> A(10);
    vector<int>B(5);
    for(int i = 0; i < 5; i++){
        A[i] = i;
        B[i] = i+2;
    }
    cout << "A = ";
    
    for(int i = 0; i < 5; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "B = ";
    for(int i = 0; i < 5; i++){
        cout << B[i] << " ";
    }
    cout << endl;
    
    merge(A, B, 5, 5);
}


/*
A = 0 1 2 3 4 
B = 2 3 4 5 6 
Final Merged Array = 0 1 2 2 3 3 4 4 5 6 
*/
