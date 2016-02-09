/*

Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.

*/

// PROGRAM 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

main()
{
    string s = "aaabbcccd";
    string out = "";
    int count = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == s[i+1])
            count++;
        else{
            string temp = s[i] + to_string(count); 
            out.append(temp);
            count = 1;
        }
    }
    cout << out;
}


//Output - a3b2c3d1
