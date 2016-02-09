//Given coins with values 1, 3, and 5. Find minimum number of coins needed to make the sum 11.
// Dynamic Programming


#include<iostream>
#include<vector>
using namespace std;

main()
{
    int max  = 11;
    vector<int>coins = {1,3,5};
    vector<int>sum(12,99);
    sum[0] = 0;
    
    for(int i = 1; i <= max; i++){
        for(int j = 0; j < coins.size(); j++){
            if(coins[j] <= i && sum[i-coins[j]] + 1 < sum[i])
               sum[i] = sum[i-coins[j]] + 1; 
        }
    }
    cout << sum[11];
}
