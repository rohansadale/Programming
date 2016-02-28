/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. 
It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. 
How to maximize total profit if only one job can be scheduled at a time.

Example-

Input: Four Jobs with following deadlines and profits
  JobID    Deadline      Profit
    a        4            20   
    b        1            10
    c        1            40  
    d        1            30
Output: Following is maximum profit sequence of jobs
        c, a   


Input:  Five Jobs with following deadlines and profits
   JobID     Deadline     Profit
     a         2           100
     b         1           19
     c         2           27
     d         1           25
     e         3           15
Output: Following is maximum profit sequence of jobs
        c, a, e
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Job{
    char name;
    int dead;
    int profit;
};

bool myCompare(Job a, Job b){
    return a.profit > b.profit;
}

void jobSchedular(Job arr[], int n){

    sort(arr, arr+n, myCompare);
    
    bool slot[n];
    for(int i = 0; i < n; i++)
        slot[i] = false;

    for(int i = 0; i < n; i++){
        for(int j = min(arr[i].dead, n)-1; j>= 0; j--){
            if(!slot[j]){
                slot[j] = true;
                cout << arr[i].name << " ";
                break;
            }
        }
    }
}


int main() {
	
    Job arr[] = { {'a', 3, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};

    jobSchedular(arr, 5);
	return 0;
}

// Output - a c d