/*

Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void compress(string s){
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
    if(out.size() < s.size())
        cout << out << endl;
    else
        cout << s << endl;;
}

main()
{
    compress("aabcccccaaa");
    compress("aabbcc");
}


/*
Output
a2b1c5a3
aabbcc
*/
