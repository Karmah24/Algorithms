#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
 
int main() {
    
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n, amt;
    cin >> n >> amt;
    int coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];

    int dp[amt + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= amt; i++) {

        for (int j = 0; j < n; j++) {

            if (i < coins[j]) continue;
            
            (dp[i] += dp[i - coins[j]]) %= MOD;
        }
    }
    cout << dp[amt];
}