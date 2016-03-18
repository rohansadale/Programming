// Sort App by version number

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    string s = "1.1";
    vector<string> v1 = {"1.10.1", "1.10.2","1.11.1","2.1.1", "1.1.90"};
    vector<pair<string, string> >v2;    
    
    
/*
Below for loop if converting to string isn't allowed. Here we convert to veector of pairs and then apply sort on it. 

    stringstream ss;
    string token1, token2;
    char delimiter = '.';

    for(int i = 0; i < v1.size(); i++){
        stringstream ss(v1[i]);        
        getline(ss,token1, delimiter);
        getline(ss,token2, delimiter);
        //cout << token1 << " " << token2 << endl;
        v2.push_back(make_pair(token1, token2));
    }
*/    
    sort(v1.begin(), v1.end());
    for(auto i = 0; i < v1.size(); i++)
        cout << v1[i] << endl;
        
    return 0;
}

/*
Output
1.1.90
1.10.1
1.10.2
1.11.1
2.1.1
*/
