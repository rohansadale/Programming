// All permutations of a string

#include<iostream>
#include <string>
using namespace std;

void permute(string &s, int low, int high){
    if(low == high)
        cout << s << endl;
    else{
        for(int i = low; i < high; i++){
            swap(s[low], s[i]);
            permute(s, low+1, high);
            swap(s[low], s[i]);
        }
    }
}

main()
{
    string s = "ABC";
    permute(s, 0,s.size());

}

/*
Output 
ABC
ACB
BAC
BCA
CBA
CAB
*/
