#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        for (int i = 1; i <= amount; i++) dp[i] = INT_MAX;
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    int remain_res = dp[i - coins[j]];
                    if (remain_res != INT_MAX && (remain_res + 1 < dp[i]))
                        dp[i] = remain_res + 1;
                }
            }
        }
        if (dp[amount] != INT_MAX)
            return dp[amount];
        else return -1;
    }
};

int main() {
    int n, amount;
    cin >> amount >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    Solution obj;
    auto start = high_resolution_clock::now();
    cout << obj.coinChange(coins, amount);
    auto stop = high_resolution_clock::now();
    cout << endl << duration_cast<microseconds>(stop - start).count(); 
}

// int dp[10001][12];
    
    // int func(vector<int>& coins, int amount, int index) {
    //     if (amount == 0)
    //         return 0;
    //     if (dp[amount][index] != -1) return dp[amount][index];
        
    //     if (index == coins.size() - 1) {
    //         if (amount % coins[index] == 0)
    //             dp[amount][index] = amount / coins[index];
    //         else return -1;
    //     }
    //     else {
    //         int s = 0;
    //         for (int i = 0; coins[index] * i <= amount; i++) {
    //             s  = func(coins, amount - (coins[index] * i), index + 1);
                
    //             if (s != -1) {
    //                 if (dp[amount][index] != -1)
    //                     dp[amount][index] = min(dp[amount][index], s + i);
    //                 else dp[amount][index] = s + i;
    //             }
    //         }
    //     }
    //     return dp[amount][index];
        
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     for (int i = 0; i <= amount; i++)
    //         for (int j = 0; j < coins.size(); j++) dp[i][j] = -1;
        
    //     return func(coins, amount, 0);
    // }