// Reverse an array without affecting special characters

#include<iostream>
#include<string>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

bool isDigit(char c){
    if(c-'0' >= 0 && c-'9' <= 0)
        return true;
    else 
        return false;
}

string reverse(string str){

    //cout << str;
    if(str.empty())
        return str;
    
   
    int low = 0; 
    int high = str.size()-1;
    while(low < high){
        if(!isalpha(str[low]) || isDigit(str[low]))
            low++;
        if(!isalpha(str[high]) || isDigit(str[high]))
            high--;            
        swap(str[low], str[high]);
        low++;
        high--;
    }
    
    
    return str;
    
}

int main()
{
    char c = '9';
    
    cout << reverse("R~oh9,a!n");
    return 0;
}


// Output - n~a9h,o!R
