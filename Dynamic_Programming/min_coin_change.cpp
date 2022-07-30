#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(int arr[], int n, int W) {

        if (W == 0) return 0;
        if (n < 0) return INT_MAX - 1;
        if (dp[n][W - 1] != -1) return dp[n][W - 1];

        int ifin, ifout = solve(arr, n - 1, W);
        ifin = W < arr[n] ? INT_MAX - 1 : solve(arr, n, W - arr[n]) + 1;

        return dp[n][W - 1] = min(ifin, ifout);
    }
public:
    int minCoinsMem(int coins[], int n, int amt) {

        dp = vector<vector<int>>(n, vector<int>(amt, -1));
        int res = solve(coins, n - 1, amt);

        return res == INT_MAX - 1 ? -1 : res;
    }

    int minCoinsTab(int coins[], int n, int amt) {

        int dp[amt + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
    
        for (int i = 1; i <= amt; i++) {
    
            for (int j = 0; j < n; j++) {
    
                if (i < coins[j]) continue;

                if (dp[i - coins[j]] == -1) continue;

                if (dp[i] == -1) dp[i] = dp[i - coins[j]] + 1;
                else dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amt];
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, amt;
    cin >> amt >> n;
    int coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];
    Solution obj;
    cout << obj.minCoinsTab(coins, n, amt);
}