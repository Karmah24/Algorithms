#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {

        int dp[amt + 1];
        dp[0] = 0;
        for (int i = 1; i <= amt; i++) {
            dp[i] = INT_MAX;

            for (int j = 0; j < coins.size(); j++) {
                if (i < coins[j]) continue;
                if (dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j] + 1]);
                }
            }
        }
        return dp[amt] == INT_MAX ? -1 : dp[amt];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, amt;
    cin >> amt >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    Solution obj;
    auto start = high_resolution_clock::now();
    cout << obj.coinChange(coins, amt);
    auto stop = high_resolution_clock::now();
    cout << endl << duration_cast<microseconds>(stop - start).count(); 
}