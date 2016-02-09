//Write a method to sort an array of strings so that all the anagrams are next to each other.

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

#define all(c) c.begin(), c.end()

main()
{
    vector<string> v1 ={"cat", "dog", "tac", "god", "act"};
    vector<pair<string,int> > v2;
    for(int i = 0; i < v1.size(); i++){
        string s = v1[i];
        sort(all(s));
        v2.push_back(make_pair(s, i));
    }
    sort(all(v2));
    
    for(vector<pair<string, int> >::iterator it_v = v2.begin(); it_v != v2.end(); it_v++){
        cout << v1[(*it_v).second] << endl;        
    }
}


/*
Output:
cat
tac
act
dog
god
*/
