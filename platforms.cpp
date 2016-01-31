/*
Minimum Number of Platforms Required for a Railway/Bus Station
http://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumPlatforms(float a[], float b[], int a1, int b1){
    int totalPlatforms = 0;
    int platform = 0;
    
    int arr = 0;
    int dept = 0;
    
    while(1){
        while(a[arr] < b[dept] && arr < a1){
            platform++;
            //cout << a[arr] << " " << platform << endl;
            arr++;
            totalPlatforms = max(platform, totalPlatforms);
        }
        
        while(a[arr] > b[dept] && dept < b1){
            platform--;
            dept++;
        }
        if(arr >= a1)
            break;
    }
    return totalPlatforms;
}

main(){
    float arrival[] = {9,  9.40, 9.50,  11.00, 15.00, 18.00};
    float dept[] = {9.10, 12.00, 11.20, 11.30, 19.00, 20.00};
    
    sort(arrival, arrival + 6);
    sort(dept, dept + 6);
    cout << minimumPlatforms(arrival, dept, 6, 6);
}
