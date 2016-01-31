/*
Design an algorithm to find the kth number such that the only prime factors are 2,3, and 5.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int min(int n1, int n2, int n3){
    if(n1 <= n2 && n1 <= n3)
        return n1;
    else if(n2 <= n1 && n2 <= n3)
        return n2;
    else
        return n3;
}

unsigned getNumber(int n){
    unsigned *a = new unsigned[n];
    int i2 = 0, i3 = 0, i5 = 0;
    int next_2 = 2;
    int next_3 = 3;
    int next_5 = 5;
    a[0] = 1;
    
    //initial number
    int num = 1;
    
    for(int i = 1; i < n ; i++){
        num = min(next_2, next_3, next_5);
        if(num != a[i-1])
            a[i] = num;
        //cout << num << endl;
        
        if(num == next_2){
            i2++;
            next_2 = 2*a[i2];
        }
        if(num == next_3){
            i3++;
            next_3 = 3*a[i3];
        }
        if(num == next_5) {
            i5++;
            next_5 = 5*a[i5];
        }
    }
    return a[n-1];
}


main()
{
unsigned no = getNumber(100);
cout << no;
}

// Output - 1536
