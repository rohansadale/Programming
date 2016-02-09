//Implement an algorithm to print all valid (i.e., properly opened and closed) combinations of n-pairs of parentheses.

#include<iostream>
#include <string>
using namespace std;

void possibleCombinations(int left, int right, string s){
    if(right == 0){
        cout << s << endl;
        return;
    }
    if(left > 0) possibleCombinations(left-1, right, s+'(');
    if(right > left) possibleCombinations(left, right-1, s+')');
}

main()
{
    int n = 3;
    string s;
    possibleCombinations(n,n,s);

}


/*
Output
((()))
(()())
(())()
()(())
()()()
*/
