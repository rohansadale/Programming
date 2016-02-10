// Longest non-decreasing subsequence in array


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

main()
{
    vector<int>data = {5, 3, 4, 8, 6, 7};
    vector<int>seq(6,1);
    
    for(int i = 1; i < data.size(); i++){
        for(int j = 0; j < i; j++){
            if(data[j] <= data[i] && seq[j] + 1 > seq[i] )
                seq[i] = seq[j] + 1;
        }
        cout << data[i] << " " << seq[i]<< endl;
    }
    cout << *max_element(seq.begin(), seq.end());
}
