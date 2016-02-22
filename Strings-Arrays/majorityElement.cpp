/*
Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times 
(and hence there is at most one such element).

Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE as follows:

       I/P : 3 3 4 2 4 4 2 4 4
       O/P : 4 

       I/P : 3 3 4 2 4 4 2 4
       O/P : NONE

*/

/*
//Short Code - O(nlogn)

main(){
    vector<int> v = {2, 2, 3, 5, 2, 2, 6};
    sort(v.begin(), v.end());
    if(v[0] == v[v.size()/2] || v[v.size()-1] == v[v.size()/2])
        cout << v[v.size()/2];
    else
        cout << "None";
  }

*/


// O(n) - Two loops | Moore’s Voting Algorithm

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

main(){
    vector<int> v = {2, 2, 3, 5, 2, 2, 6};

    int majI = 0;
    int count = 0;
    
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[majI])
            count++;
        else
            count--;
        
        if(count == 0){
            majI = i;
            count = 1;
        }
    }
    
    count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == v[majI])
            count++;
    }
    
   if(count >= v.size()/2)
            cout << v[majI];
    else
        cout << " None";
}

/*
Output - 2
*/
