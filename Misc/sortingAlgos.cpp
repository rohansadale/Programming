/*
Sorting
*/

#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int> v){
    
    int n = v.size();
    for(int i = 0; i < n-1; i++){
        bool swapped = false; 
        for(int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1])
                swap(v[j], v[j+1]);
                swapped = true;
        }
        
        // No swapping in current iteration. This says that array is sorted
        if(!swapped)
            break;
    }
    
    cout << "Bubble Sort \n";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void selectionSort(vector<int> v){
    int n = v.size();
    for(int i = 0; i < n-1; i++){
        int index = i;
        int min = v[i];
        for(int j = i+1; j < n; j++){
            if(min > v[j]){
                index = j;
                min = v[j];
            }
        }
        swap(v[i], v[index]);
    }
    
    cout << "Selection Sort \n";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void insertionSort(vector<int> v){
    int n = v.size();
    for(int i = 1; i < n; i++){
        int j = i-1;
        int no = v[i];
        while(j >= 0 && v[j] > no){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = no;
    }
    
    cout << "Insertion Sort \n";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

main()
{
int n1 = 5;
int n2 = -1;
vector<int> v = {12, 11, 10, 5, 6};
bubbleSort(v);
selectionSort(v);
insertionSort(v);
}

/*

Output
Bubble Sort 
5 6 10 11 12 
Selection Sort 
5 6 10 11 12 
Insertion Sort 
5 6 10 11 12 

*/
