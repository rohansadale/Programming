/*
Add two numbers without using +
*/

#include<iostream>
using namespace std;

int add(int n1, int n2){
    int carry = 0;
    
    while(n2 != 0){
        carry = n1 & n2;
        n1 = n1 ^ n2;
        n2 = carry << 1;
        cout << n1 << " " << n2 << " " << carry << endl;
    }
    return n1;
}


main()
{
int n1 = 5;
int n2 = -1;

cout << add(n1, n2);
}

// Output - 4
