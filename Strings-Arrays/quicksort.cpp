// Quicksort

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &v, int low, int high){
    int p = v[low];
    int i = low;
    low++;
    while(low < high){
        while(v[low] < p)
            low++;
        while(v[high] > p)
            high--;
        if(low < high){
            swap(v[low], v[high]);
        }
    }
    swap(v[high], v[i]);
    return high;
}

void quicksort(vector<int> &v, int low, int high){
    if(low < high){
        int p = partition(v, low, high);
        quicksort(v, low, p-1);
        quicksort(v, p+1, high);
    }
}

int main(){
    vector<int> v = {10, 7, 8, 9, 1, 5, 112,4,23,666,23,111};
    quicksort(v, 0, v.size()-1);
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

/*
Output - 
1
4
5
7
8
9
10
23
23
111
112
666
*/
